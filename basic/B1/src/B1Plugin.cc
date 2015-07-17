#include "B1Plugin.hh"

#include "B1EventAction.hh"

void B1Plugin::BuildGeometry(G4LogicalVolume *logVolume)
{

}

G4UserRunAction* B1Plugin::CreateRunAction()
{

}

G4UserEventAction* B1Plugin::CreateEventAction()
{
    return GetEventAction();
}

G4VUserPrimaryGeneratorAction* B1Plugin::CreatePrimaryGeneratorAction()
{

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
