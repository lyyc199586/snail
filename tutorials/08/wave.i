[GlobalParams]
  displacements = 'disp_x'
[]

[Mesh]
  [gmg]
    type = GeneratedMeshGenerator
    dim = 1
    nx = 100
  []
[]

# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN

[Materials]
  [Elasticity_tensor]
    type = ComputeIsotropicElasticityTensor
    youngs_modulus = 2.1e5
    poissons_ratio = 0
  []
  [stress]
    type = ComputeLinearElasticStress
  []
[]

[Postprocessors]
  [displacement]
    type = PointValue
    variable = disp_x
    point = '0.5 0 0'
  []
[]

[Outputs]
  interval = ${interval}
  csv = true
  exodus = true
[]
