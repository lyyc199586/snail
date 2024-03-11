#include "Tutorial02Strain.h"

// HIDDEN
// HIDDEN
// HIDDEN

InputParameters
Tutorial02Strain::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription("Calculate strain as function of displacement gradients");
  params.addRequiredCoupledVar("displacements", "Displacement variables");
  params.addParam<MaterialPropertyName>("strain", "strain", "Name of the strain");
  return params;
}

Tutorial02Strain::Tutorial02Strain(const InputParameters & params)
  : Material(params),
    _grad_u(adCoupledGradients("displacements")),
    _e(declareADProperty<RankTwoTensor>("strain"))
{
  _grad_u.resize(3, &_ad_grad_zero);
}

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
