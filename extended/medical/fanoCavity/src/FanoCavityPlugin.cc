#include "FanoCavityPlugin.hh"

using namespace g4;
using namespace std;

MAKE_G4_PLUGIN( FanoCavityPlugin )

const vector<string> FanoCavityPlugin::GetAvailableComponents() const { return {}; }

Component* FanoCavityPlugin::GetComponent(const std::string&)
{
	return nullptr;
}