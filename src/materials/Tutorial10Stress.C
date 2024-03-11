#include "Tutorial10Stress.h"
#include "StabilizationUtils.h"

registerMooseObject("snailApp", Tutorial10Stress);

InputParameters
Tutorial10Stress::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription(
      "Calculate stress for a Neo-Hookean type material with three-field stabilization");
  params.addParam<MaterialPropertyName>("deformation_gradient", "F", "Lame's first parameter");
  params.addRequiredParam<MaterialPropertyName>("bulk_modulus", "Lame's first parameter");
  params.addRequiredParam<MaterialPropertyName>("shear_modulus_1", "Shear modulus");
  params.addRequiredParam<MaterialPropertyName>("shear_modulus_2", "Shear modulus");
  params.addRequiredParam<Real>("beta", "Incompressibility exponent");
  params.addParam<MaterialPropertyName>("dilation", "Theta", "Name of the element dilation");
  params.addParam<MaterialPropertyName>(
      "hydrostatic_pressure", "p", "Name of the element hydrostatic pressure");
  return params;
}

Tutorial10Stress::Tutorial10Stress(const InputParameters & params)
  : Material(params),
    _F(getADMaterialProperty<RankTwoTensor>("deformation_gradient")),
    _K(getADMaterialProperty<Real>("bulk_modulus")),
    _mu1(getADMaterialProperty<Real>("shear_modulus_1")),
    _mu2(getADMaterialProperty<Real>("shear_modulus_2")),
    _beta(getParam<Real>("beta")),
    _Theta(declareADProperty<Real>("dilation")),
    _p(declareADProperty<Real>("hydrostatic_pressure")),
    _P(declareADProperty<RankTwoTensor>("pk1_stress"))
{
}

ADReal
Tutorial10Stress::h(const ADReal & J) const
{
  return std::pow(J, _beta) + std::pow(J, -_beta);
}

ADReal
Tutorial10Stress::dh(const ADReal & J) const
{
  return _beta * (std::pow(J, _beta - 1) - std::pow(J, -_beta - 1));
}

void
Tutorial10Stress::computeProperties()
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
}

void
Tutorial10Stress::computeQpProperties()
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
}

// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN
// HIDDEN

ADRankTwoTensor
Tutorial10Stress::isochoricStress(const ADReal & J, const ADRankTwoTensor & C) const
{
  usingTensorIndices(i, j, k, l);

  const auto I2 = ADRankTwoTensor::Identity();
  const auto C_bar = std::pow(J, -2.0 / 3.0) * C;
  const auto C_bar_inv = C_bar.inverse();
  const auto C_bar_cof = C_bar.det() * C_bar_inv;
  const auto S_bar = 2 * _mu1[_qp] * I2 + 3 * _mu2[_qp] * std::sqrt(C_bar_cof.tr()) *
                                              (C_bar_cof * C_bar_inv.tr() - C_bar_cof * C_bar_inv);

  const auto P_deviator =
      std::pow(J, -2.0 / 3.0) *
      ((I2.times<i, k, j, l>(I2) + I2.times<i, l, j, k>(I2)) / 2 - C.inverse().outerProduct(C) / 3);

  return P_deviator * S_bar;
}
