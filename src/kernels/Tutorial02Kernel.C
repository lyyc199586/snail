#include "Tutorial02Kernel.h"

// HIDDEN
// HIDDEN
// HIDDEN

InputParameters
Tutorial02Kernel::validParams()
{
  auto params = ADKernel::validParams();
  params.addClassDescription("Solve the linear momentum balance");
  params.addParam<MaterialPropertyName>("stress", "stress", "The stress to balance");
  params.addRequiredParam<unsigned int>("component", "The residual component");
  return params;
}

Tutorial02Kernel::Tutorial02Kernel(const InputParameters & params)
  : ADKernel(params),
    _s(getADMaterialProperty<RankTwoTensor>("stress")),
    _component(getParam<unsigned int>("component"))
{
}

// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
