#include "Tutorial11Stress.h"

registerMooseObject("snailApp", Tutorial11Stress);

InputParameters
Tutorial11Stress::validParams()
{
  auto params = Tutorial10Stress::validParams();
  params.addClassDescription(
      "Calculate stress for a Neo-Hookean type material with three-field stabilization. The "
      "material is degraded based on the current damage.");
  params.addRequiredCoupledVar("damage", "The damage variable");
  params.addParam<MaterialPropertyName>("degradation", "g", "The fracture degradation function");
  params.addParam<MaterialPropertyName>(
      "strain_energy_density", "w", "Name of the strain energy density");
  return params;
}

Tutorial11Stress::Tutorial11Stress(const InputParameters & params)
  : DerivativeMaterialInterface<Tutorial10Stress>(params),
    _d(coupledName("damage")),
    _g(getADMaterialProperty<Real>("degradation")),
    _dg(getMaterialPropertyDerivative<Real, true>(getParam<MaterialPropertyName>("degradation"),
                                                  _d)),
    _w(declareADProperty<Real>("strain_energy_density")),
    _dw(declarePropertyDerivative<Real, true>(
        getParam<MaterialPropertyName>("strain_energy_density"), _d))
{
}

void
Tutorial11Stress::computeQpProperties()
{
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
}

// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
