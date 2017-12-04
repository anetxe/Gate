/*----------------------
   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See LICENSE.md for further details
----------------------*/


#ifndef GateGeometryVoxelImageReader_h
#define GateGeometryVoxelImageReader_h 1

#include "GateVVolume.hh"

#include "globals.hh"
#include "G4ThreeVector.hh"
#include <vector>
#include <map>

#include "GateVGeometryVoxelReader.hh"

class GateGeometryVoxelImageReaderMessenger;

/*! \class  GateGeometryVoxelImageReader
    \brief  This class is a concrete implementation of the abstract GateVGeometryVoxelReader

    - GateGeometryVoxelImageReader - by Giovanni.Santin@cern.ch

    - it reads a the voxel info from an ASCII file with the sequence of info: 
      + nx ny nz
      + dx dy dz (mm)
      + number_of_listed_voxels
      + i1 j1 k1 materialName1
      + i2 j2 k2 materialName2
      + ...

      \sa GateVGeometryVoxelReader
      \sa GateGeometryVoxelImageReaderMessenger
      \sa GateVGeometryVoxelTranslator
      \sa GateVSourceVoxelReader
      \sa GateVSourceVoxelTranslator
*/      

class GateGeometryVoxelImageReader : public GateVGeometryVoxelReader
{
public:

  GateGeometryVoxelImageReader(GateVVolume* inserter);
  virtual ~GateGeometryVoxelImageReader();

  virtual void ReadFile(G4String fileName);
  virtual void ReadRTFile(G4String header_fileName, G4String fileName);
  virtual void Describe(G4int level);

protected:

  GateGeometryVoxelImageReaderMessenger* m_messenger; 
};

#endif


