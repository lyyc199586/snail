#pragma once

#include "Tutorial10Stress.h"
#include "DerivativeMaterialInterface.h"

class Tutorial11Stress : public DerivativeMaterialInterface<Tutorial10Stress>
{
public:
  static InputParameters validParams();

  Tutorial11Stress(const InputParameters &);

protected:
  virtual void computeQpProperties() override;

// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN

  const VariableName _d;

  const ADMaterialProperty<Real> & _g;
  const ADMaterialProperty<Real> & _dg;

  ADMaterialProperty<Real> & _w;
  ADMaterialProperty<Real> & _dw;
};
