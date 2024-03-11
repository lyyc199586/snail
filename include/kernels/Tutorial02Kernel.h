#pragma once

#include "ADKernel.h"
#include "RankTwoTensor.h"

class Tutorial02Kernel : public ADKernel
{
public:
  static InputParameters validParams();

  Tutorial02Kernel(const InputParameters &);

protected:
// HIDDEN
// HIDDEN
// HIDDEN

  const ADMaterialProperty<RankTwoTensor> & _s;

  const unsigned int _component;
};
