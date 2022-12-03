#include "model_modeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
model_modeApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

model_modeApp::model_modeApp(InputParameters parameters) : MooseApp(parameters)
{
  model_modeApp::registerAll(_factory, _action_factory, _syntax);
}

model_modeApp::~model_modeApp() {}

void
model_modeApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"model_modeApp"});
  Registry::registerActionsTo(af, {"model_modeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
model_modeApp::registerApps()
{
  registerApp(model_modeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
model_modeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  model_modeApp::registerAll(f, af, s);
}
extern "C" void
model_modeApp__registerApps()
{
  model_modeApp::registerApps();
}
