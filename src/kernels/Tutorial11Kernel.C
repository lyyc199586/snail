#include "Tutorial11Kernel.h"

// HIDDEN
// HIDDEN
// HIDDEN

InputParameters
Tutorial11Kernel::validParams()
{
  auto params = ADKernel::validParams();
  params.addClassDescription("Solve the fracture propagation envelope");
  params.addParam<MaterialPropertyName>(
      "crit_energy_rel_rate", "Gc", "The critical energy release rate");
  params.addRequiredParam<Real>("reg_length", "The phase field regularization length");
  params.addParam<MaterialPropertyName>(
      "strain_energy_density", "w", "The strain energy density driving fracture propagation");
  return params;
}

Tutorial11Kernel::Tutorial11Kernel(const InputParameters & params)
  : DerivativeMaterialInterface<ADKernel>(params),
    _Gc(getADMaterialProperty<Real>("crit_energy_rel_rate")),
    _ell(getParam<Real>("reg_length")),
    _dw(getMaterialPropertyDerivative<Real, true>(
        getParam<MaterialPropertyName>("strain_energy_density"), _var.name()))
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
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
