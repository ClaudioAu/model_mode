//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "model_modeTestApp.h"
#include "model_modeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
model_modeTestApp::validParams()
{
  InputParameters params = model_modeApp::validParams();
  return params;
}

model_modeTestApp::model_modeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  model_modeTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

model_modeTestApp::~model_modeTestApp() {}

void
model_modeTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  model_modeApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"model_modeTestApp"});
    Registry::registerActionsTo(af, {"model_modeTestApp"});
  }
}

void
model_modeTestApp::registerApps()
{
  registerApp(model_modeApp);
  registerApp(model_modeTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
model_modeTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  model_modeTestApp::registerAll(f, af, s);
}
extern "C" void
model_modeTestApp__registerApps()
{
  model_modeTestApp::registerApps();
}
