//
//  VectorDB.h
//  vector_dice
//
//  Created by Steve Gifford on 1/8/14.
//  Copyright (c) 2014 mousebird consulting. All rights reserved.
//

#ifndef __vector_dice__VectorDB__
#define __vector_dice__VectorDB__

#include <iostream>
#include <vector>
#include <set>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "ogr_spatialref.h"
#include "KompexSQLitePrerequisites.h"
#include "KompexSQLiteDatabase.h"
#include "KompexSQLiteStatement.h"
#include "KompexSQLiteException.h"
#include "KompexSQLiteStreamRedirection.h"
#include "KompexSQLiteBlob.h"
#include "KompexSQLiteException.h"

namespace Maply
{

// Vector attribute types
typedef enum {VectorAttrInt=0,VectorAttrString,VectorAttrReal} VectorAttributeType;

class VectorDatabase
{
public:
    VectorDatabase();
    ~VectorDatabase();

    // Used to track attribute name/type
    class Attribute
    {
    public:
        bool operator < (const Attribute &that) const { return name < that.name; }
        std::string name;
        int index;
        VectorAttributeType type;
    };

    // Set up the data structures we need in the SQLite database
    bool setupDatabase(Kompex::SQLiteDatabase *db,const char *dbSrs,const char *tileSrs,double minX,double minY,double maxX,double maxY,int minLevel,int maxLevel,bool compress);
    
    // Add a style definition (just json, basically)
    void addStyle(const char *name,const char *styleStr);
    
    // Add a layer.  We store those in individual tables.
    int addVectorLayer(const char *);
    
    // Return an attribute ID by name if it exists, -1 if it doesn't
    bool getAttribute(const char *name,Attribute &attr);
    
    // Add an attribute to the table (or return the index of an existing one)
    Attribute addAttribute(const char *name,VectorAttributeType type);
    
    // Convert OGR vector data to our raw format
    void vectorToDBFormat(std::vector<OGRFeature *> &features,std::vector<unsigned char> &vecData);
    
    // Add the data for a vector tile
    bool addVectorTile(int x,int y,int level,int layerID,const char *data,unsigned int dataLen);
    
    // Create the quadIndex index
    void createIndex();
    
    // Close any open statements and such
    void flush();
    
    // Check this after opening
    bool isValid() { return valid; }
    
protected:
    
    Kompex::SQLiteDatabase *db;
    std::vector<std::string> layerNames;
    std::set<Attribute> attributes;
    
    double minx,miny,maxx,maxy;
    int minLevel,maxLevel;
    bool compress;
    bool valid;
    
    // Precompiled insert statement
    std::vector<Kompex::SQLiteStatement *> insertStmts;
};
    
}

#endif /* defined(__vector_dice__VectorDB__) */
