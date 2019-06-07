/*
 *  ProgramMTL.h
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 5/16/19.
 *  Copyright 2011-2019 mousebird consulting
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
 *
 */

#import <Foundation/Foundation.h>
#import "WrapperMTL.h"
#import "Program.h"

namespace WhirlyKit
{

/** Representation of an iOS Metal.  It's an identifiable so we can
 point to it generically.  Otherwise, pretty basic.
 */
class ProgramMTL : public Program
{
public:
    ProgramMTL();
    virtual ~ProgramMTL();
    
    /// Set up with a vertex and fragment shader
    ProgramMTL(const std::string &name,id<MTLFunction> vertfunc,id<MTLFunction> fragFunc);
    
    /// Return true if it was built correctly
    bool isValid();

    /// Tie a given texture to an index offset
    bool setTexture(StringIdentity nameID,int indexOffset);
    
    /// Check for the specific attribute associated with WhirlyKit lights
    bool hasLights();
    
    /// Set the attributes associated with lighting.
    /// We'll check their last updated time against ours.
    bool setLights(const std::vector<DirectionalLight> &lights, TimeInterval lastUpdated, Material *mat, Eigen::Matrix4f &modelMat);
        
    /// Return the name (for tracking purposes)
    const std::string &getName();
    
    /// Clean up OpenGL resources, rather than letting the destructor do it (which it will)
    virtual void teardownForRenderer(const RenderSetupInfo *setupInfo);
    void cleanUp();
    
public:
    bool valid;
    std::string name;
    id<MTLFunction> vertFunc,fragFunc;
    TimeInterval lightsLastUpdated;
};

    
    
}
