[GlobalParams]
  displacements = 'disp_x disp_y'
[]

[Mesh]
  [paper]
    type = FileMeshGenerator
    file = '../gold/paper.msh'
  []
[]

[Variables]
  [disp_x]
  []
  [disp_y]
  []
  [d]
  []
[]

[AuxVariables]
  [bound]
  []
  [r_x]
  []
  [r_y]
  []
[]

[Bounds]
  [d_lower_bound]
    type = VariableOldValueBounds
    variable = bound
    bounded_variable = d
    bound_type = lower
  []
[]

[Kernels]
  [momentum_balance_x]
    type = Tutorial02Kernel
    variable = disp_x
    component = 0
    stress = pk1_stress
    save_in = 'r_x'
  []
  [momentum_balance_y]
    type = Tutorial02Kernel
    variable = disp_y
    component = 1
    stress = pk1_stress
    save_in = 'r_y'
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
[]

[Materials]
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
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
# HIDDEN
[]

[BCs]
  [fix_x]
    type = DirichletBC
    variable = disp_x
    value = 0
    boundary = 'top bottom'
  []
  [bottom_fix]
    type = DirichletBC
    variable = disp_y
    value = 0
    boundary = 'bottom'
  []
  [top_pull]
    type = FunctionDirichletBC
    variable = disp_y
    function = 't'
    boundary = 'top'
  []
[]

[Executioner]
  type = Transient
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -snes_type'
  petsc_options_value = 'lu vinewtonrsls'
  automatic_scaling = true
  end_time = 0.45
  dt = 1e-3
  nl_abs_tol = 1e-12
  nl_rel_tol = 1e-10
  nl_max_its = 200
[]

[Postprocessors]
  [force]
    type = NodalSum
    variable = r_y
    boundary = top
  []
  [displacement]
    type = SideAverageValue
    variable = disp_y
    boundary = top
  []
[]

[Outputs]
  exodus = true
  csv = true
  print_linear_residuals = false
[]
