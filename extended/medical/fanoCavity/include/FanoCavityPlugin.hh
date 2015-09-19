#ifndef FANOCAVITY_PLUGIN_HH
#define FANOCAVITY_PLUGIN_HH

#include <vector>

#include "Plugin.hh"

class FanoCavityPlugin : public g4::Plugin
{
public:
    const std::vector<std::string> GetAvailableComponents() const override;

    g4::Component* GetComponent(const std::string&) override;
};

#endif