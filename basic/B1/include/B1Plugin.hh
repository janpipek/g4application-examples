#ifndef B1PLUGIN_HH
#define B1PLUGIN_HH

#include "SingleComponentPlugin.hh"
#include "util/ThreadLocal.hh"

#include "B1EventAction.hh"
#include "B1PrimaryGeneratorAction.hh"

class B1DetectorConstruction;

class B1Plugin : public g4::SingleComponentPlugin
{
public:
    B1Plugin();

    virtual ~B1Plugin();

    virtual void BuildGeometry(G4LogicalVolume *logVolume) override;

    virtual G4VPhysicalVolume* CreateWorld() override;

    virtual G4UserRunAction* CreateRunAction() override;

    virtual G4UserEventAction* CreateEventAction() override;

    virtual G4UserSteppingAction* CreateSteppingAction() override;

    virtual G4VUserPrimaryGeneratorAction* CreatePrimaryGeneratorAction() override;

    // To be used in the plugin
    B1PrimaryGeneratorAction* GetPrimaryGeneratorAction() { return _primaryGeneratorAction.Get(); }

    B1DetectorConstruction* GetDetectorConstruction() { return _detectorConstruction; }

    B1EventAction* GetEventAction(); // Lazy-evaluated, creates on demand

private:

    B1DetectorConstruction* _detectorConstruction;

    g4::util::ThreadLocal<B1PrimaryGeneratorAction> _primaryGeneratorAction;

    g4::util::ThreadLocal<B1EventAction> _eventAction;
};

#endif
