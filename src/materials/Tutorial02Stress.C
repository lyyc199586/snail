#include "Tutorial02Stress.h"

// HIDDEN
// HIDDEN
// HIDDEN

InputParameters
Tutorial02Stress::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription("Calculate stress for a linear elastic material");
  params.addRequiredParam<MaterialPropertyName>("lambda", "Lame's first parameter");
  params.addRequiredParam<MaterialPropertyName>("mu", "Shear modulus");
  params.addParam<MaterialPropertyName>("strain", "strain", "Name of the strain");
  params.addParam<MaterialPropertyName>("stress", "stress", "Name of the stress");
  return params;
}

Tutorial02Stress::Tutorial02Stress(const InputParameters & params)
  : Material(params),
    _e(getADMaterialProperty<RankTwoTensor>("strain")),
    _lambda(getADMaterialProperty<Real>("lambda")),
    _mu(getADMaterialProperty<Real>("mu")),
    _s(declareADProperty<RankTwoTensor>("stress"))
{
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
