/**
 * \file AliEmcalTriggerBitConfig.h
 * \brief Definition of EMCAL trigger bit configurations
 *
 * Two configuation are defined:
 * - 2 triggers, 1 threshold
 * - 2 triggers, 2 thresholds
 *
 * \author Markus Fasel <markus.fasel@cern.ch>, Lawrence Berkeley National Laboratory
 */
#ifndef ALIEMCALTRIGGERBITCONFIG_H
#define ALIEMCALTRIGGERBITCONFIG_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

#include "AliLog.h"
#include <TNamed.h>

/**
 * \class AliEmcalTriggerBitConfig
 * \brief Definition of trigger bit configurations
 *
 * Trigger bit configuration used in the trigger patch maker and by the trigger patches
 * themselves in order to identify of which type the trigger patch is. Can be adapted to different
 * trigger bit configurations use in different reconstructions
 */
class AliEmcalTriggerBitConfig  : public TNamed {
public:
  AliEmcalTriggerBitConfig();
  AliEmcalTriggerBitConfig(Int_t l0bit, Int_t j1bit, Int_t j2bit, Int_t g1bit, Int_t g2bit, Int_t mcoffset);
  virtual ~AliEmcalTriggerBitConfig() {}

  void Initialise(const AliEmcalTriggerBitConfig &ref);

  /**
   * Get the trigger bit for Level0 triggers
   * @return Trigger bit number
   */
  Int_t GetLevel0Bit() const { if(fL0Bit < 0) AliFatal("Invalid trigger configuration: Level0 bit < 0"); return fL0Bit; }
  /**
   * Get trigger bit for the jet trigger, high threshold
   * @return Trigger bit number
   */
  Int_t GetJetHighBit() const { if(fJHighBit < 0) AliFatal("Invalid trigger configuration: Jet high bit < 0"); return fJHighBit; }
  /**
   * Get trigger bit for the jet trigger, low threshold
   * @return Trigger bit number
   */
  Int_t GetJetLowBit() const { if(fJLowBit < 0) AliFatal("Invalid trigger configuration: Jet low bit < 0"); return fJLowBit; }
  /**
   * Get trigger bit for the gamma trigger, high treshold
   * @return Trigger bit number
   */
  Int_t GetGammaHighBit() const { if(fGHighBit < 0) AliFatal("Invalid trigger configuration: Gamma high bit < 0"); return fGHighBit; }
  /**
   * Get trigger bit for the gamma trigger, low threshold
   * @return Trigger bit number
   */
  Int_t GetGammaLowBit() const { if(fGLowBit < 0) AliFatal("Invalid trigger configuration: Gamma low bit < 0"); return fGLowBit; }
  /**
   * Get the Monte-Carlo offset
   * @return MC offset
   */
  Int_t GetTriggerTypesEnd() const {if(fTriggerTypesEnd < 0) AliFatal("Invalid trigger configuration: MC Offset bit < 0"); return fTriggerTypesEnd; }

protected:
 Int_t fL0Bit;                      ///< Level0 bit
 Int_t fJHighBit;                   ///< Jet High bit
 Int_t fJLowBit;                    ///< Jet Low bit
 Int_t fGHighBit;                   ///< Gamma High bit
 Int_t fGLowBit;                    ///< Gamma Low bit
 Int_t fTriggerTypesEnd;            ///< Monte-Carlo offset

 /// \cond CLASSIMP
 ClassDef(AliEmcalTriggerBitConfig, 1);
 /// \endcond
};

/**
 * \class AliEmcalTriggerBitConfigOld
 * \brief Definition of old trigger bit configuration
 *
 * Definition of old trigger bit configuration:
 * - 2 triggers, 1 threshold
 */
class AliEmcalTriggerBitConfigOld : public AliEmcalTriggerBitConfig{
public:
  AliEmcalTriggerBitConfigOld();
  virtual ~AliEmcalTriggerBitConfigOld() {}

  /// \cond CLASSIMP
  ClassDef(AliEmcalTriggerBitConfigOld, 1);
  /// \endcond
};

/**
 * \class AliEmcalTriggerBitConfigNew
 * \brief Definition of new trigger bit configuration
 *
 * Definition of new trigger bit configuration:
 * - 2 triggers, 2 thresholds
 */
class AliEmcalTriggerBitConfigNew : public AliEmcalTriggerBitConfig{
public:
  AliEmcalTriggerBitConfigNew();
  virtual ~AliEmcalTriggerBitConfigNew() {}

  /// \cond CLASSIMP
  ClassDef(AliEmcalTriggerBitConfigNew, 1);
  /// \endcond
};

#endif /* ALIEMCALTRIGGERBITCONFIG_H */
