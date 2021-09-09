/*  PerformanceTimer.cpp
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 10/20/12.
 *  Copyright 2011-2021 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#import <math.h>
#import <vector>
#import <algorithm>
#import "WhirlyKitLog.h"
#import "PerformanceTimer.h"
#import "Platform.h"

namespace WhirlyKit
{
    
bool PerformanceTimer::TimeEntry::operator<(const WhirlyKit::PerformanceTimer::TimeEntry &that) const
{
    return name < that.name;
}

void PerformanceTimer::TimeEntry::addTime(TimeInterval dur)
{
    minDur = (numRuns == 0) ? dur : std::min(minDur,dur);
    maxDur = (numRuns == 0) ? dur : std::max(maxDur,dur);
    lastDur = dur;
    avgDur += dur;
    numRuns++;
}

bool PerformanceTimer::CountEntry::operator<(const WhirlyKit::PerformanceTimer::CountEntry &that) const
{
    return name < that.name;
}

void PerformanceTimer::CountEntry::addCount(int count)
{
    minCount = (numRuns == 0) ? count : std::min(minCount,count);
    maxCount = (numRuns == 0) ? count : std::max(maxCount,count);
    lastCount = count;
    avgCount += count;
    numRuns++;
}

void PerformanceTimer::startTiming(const std::string &what)
{
    actives[what] = TimeGetCurrent();
}

void PerformanceTimer::stopTiming(const std::string &what)
{
    const auto it = actives.find(what);
    if (it == actives.end())
        return;
    const TimeInterval start = it->second;
    actives.erase(it);
    
    auto eit = timeEntries.find(what);
    if (eit != timeEntries.end())
        eit->second.addTime(TimeGetCurrent()-start);
    else {
        TimeEntry newEntry;
        newEntry.addTime(TimeGetCurrent()-start);
        newEntry.name = what;
        timeEntries[what] = newEntry;
    }
}

PerformanceTimer::TimeEntry PerformanceTimer::getTiming(const std::string &what) const
{
    const auto it = timeEntries.find(what);
    return (it != timeEntries.end()) ? it->second : TimeEntry();
}

void PerformanceTimer::addCount(const std::string &what,int count)
{
    const auto result = countEntries.insert(std::make_pair(what, CountEntry()));
    if (result.second)
    {
        result.first->second.name = what;
    }
    result.first->second.addCount(count);
}

void PerformanceTimer::clear()
{
    actives.clear();
    timeEntries.clear();
    countEntries.clear();
}

static bool TimeEntryByMax (const PerformanceTimer::TimeEntry &a,const PerformanceTimer::TimeEntry &b)
{
    return a.avgDur > b.avgDur;
}
    
void PerformanceTimer::report(const std::string &what)
{
    wkLogLevel(Verbose,"Maply Performance: %s",what.c_str());    
}
    
void PerformanceTimer::log()
{
    std::vector<TimeEntry> sortedEntries;
    sortedEntries.reserve(timeEntries.size());

    for (const auto &timeEntry : timeEntries)
    {
        sortedEntries.push_back(timeEntry.second);
    }
    std::sort(sortedEntries.begin(),sortedEntries.end(),TimeEntryByMax);
    char line[1024];
    for (const auto &entry : sortedEntries)
    {
        if (entry.numRuns > 0)
        {
            sprintf(line,"%s: min, max, mean, last = (%.2f, %.2f, %.2f, %.2f) ms, %d reports",
                    entry.name.c_str(),1000*entry.minDur,1000*entry.
                    maxDur,1000*entry.avgDur / entry.numRuns, 1000*entry.lastDur, entry.numRuns);
            report(line);
        }
    }
    for (const auto &countEntry : countEntries)
    {
        const CountEntry &entry = countEntry.second;
        if (entry.numRuns > 0)
        {
            sprintf(line,"%s: min, max, mean, last, reports = (%d, %d, %2.f, %d, %d)",
                    entry.name.c_str(),entry.minCount,entry.maxCount,
                    (float)entry.avgCount / (float)entry.numRuns,entry.lastCount,entry.numRuns);
            report(line);
        }
    }
}
    
}
