#include "B1Plugin.hh"

#include "B1RunAction.hh"
#include "B1EventAction.hh"
#include "B1SteppingAction.hh"
#include "B1PrimaryGeneratorAction.hh"
#include "B1DetectorConstruction.hh"

B1Plugin::B1Plugin()
    : _detectorConstruction(new B1DetectorConstruction)
{ }

B1Plugin::~B1Plugin()
{
    delete _detectorConstruction;
}

G4VPhysicalVolume* B1Plugin::CreateWorld()
{
    return _detectorConstruction->CreateWorld();
}

void B1Plugin::BuildGeometry(G4LogicalVolume *logVolume)
{
    _detectorConstruction->BuildGeometry(logVolume);
}

G4UserRunAction* B1Plugin::CreateRunAction()
{
    return new B1RunAction(this);
}

G4UserEventAction* B1Plugin::CreateEventAction()
{
    return GetEventAction();
}

G4UserSteppingAction* B1Plugin::CreateSteppingAction()
{
    return new B1SteppingAction(this);
}

G4VUserPrimaryGeneratorAction* B1Plugin::CreatePrimaryGeneratorAction()
{
    _primaryGeneratorAction.Set(new B1PrimaryGeneratorAction());
    return _primaryGeneratorAction.Get();
}

B1EventAction* B1Plugin::GetEventAction()
{
    B1EventAction* action = _eventAction.Get();
    if (!action)
    {
        action = new B1EventAction();
        _eventAction.Set(action);
    }
    return action;
}
