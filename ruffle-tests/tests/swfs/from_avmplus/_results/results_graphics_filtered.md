# Ruffle Test Results (Filtered)

**Date**: 2026-07-24 22:06 UTC

**Git SHA**: `2cf4014fd6`

**Run Duration**: 161m 52s

**Filtered**: 0 tests ignored out of 1574 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1574 |
| Passing | **1135** (72.1%) |
| Ruffle-matched | 32 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1167** (74.1%) |
| Failing | 407 |
| Total expected lines | 85830 |
| Matching lines | 72657 (84.7%) |
| Mismatched lines | 13173 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 373 | 91.6% |
| Runtime Error | 16 | 3.9% |
| Segfault | 14 | 3.4% |
| Timeout | 3 | 0.7% |
| Compile Fail | 1 | 0.2% |

## Passing Tests

**1135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `as3/Array/regress_524122_swf10` | 1 | 5.1s |  |
| 2 | `as3/Array/regress_524122_swf11` | 1 | 5.1s |  |
| 3 | `as3/Array/regress_636535` | 6 | 5.2s |  |
| 4 | `as3/Array/regress_733384` | 24 | 5.3s |  |
| 5 | `as3/Definitions/Classes/ClassDef/Bug162570` | 5 | 5.3s |  |
| 6 | `as3/Definitions/Classes/ClassDef/DefaultClass` | 15 | 5.4s |  |
| 7 | `as3/Definitions/Classes/ClassDef/DefaultClassPrototype` | 18 | 5.5s |  |
| 8 | `as3/Definitions/Classes/ClassDef/DynamicClass` | 15 | 5.5s |  |
| 9 | `as3/Definitions/Classes/ClassDef/DynamicClassHasOwnProperty` | 1 | 5.1s |  |
| 10 | `as3/Definitions/Classes/ClassDef/DynamicClassMeth` | 2 | 5.1s |  |
| 11 | `as3/Definitions/Classes/ClassDef/DynamicClassProp` | 12 | 5.2s |  |
| 12 | `as3/Definitions/Classes/ClassDef/DynamicClassPrototype` | 18 | 5.4s |  |
| 13 | `as3/Definitions/Classes/ClassDef/DynamicClassSameMethPropName` | 4 | 5.2s |  |
| 14 | `as3/Definitions/Classes/ClassDef/FinalClassPrototype` | 18 | 5.4s |  |
| 15 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClassMethodAndProp` | 20 | 5.4s |  |
| 16 | `as3/Definitions/Classes/ClassDef/IntClassWithStrParamCons` | 4 | 5.2s |  |
| 17 | `as3/Definitions/Classes/ClassDef/InternalClassPrototype` | 18 | 5.4s |  |
| 18 | `as3/Definitions/Classes/ClassDef/PrivateStaticClassMethodAndProp` | 14 | 5.2s |  |
| 19 | `as3/Definitions/Classes/ClassDef/PublicClassMethodAndProp` | 20 | 5.2s |  |
| 20 | `as3/Definitions/Classes/ClassDef/PublicClassPrototype` | 18 | 5.5s |  |
| 21 | `as3/Definitions/Classes/ClassDef/StatClassSameNamePackage` | 0 | 0.8s |  |
| 22 | `as3/Definitions/Classes/ClassDef/bug113887` | 2 | 5.1s |  |
| 23 | `as3/Definitions/Classes/ClassDef/dynfinClassCons` | 1 | 5.1s |  |
| 24 | `as3/Definitions/Classes/ClassDef/dynfinClassDefCons` | 1 | 5.1s |  |
| 25 | `as3/Definitions/Classes/ClassDef/dynfinClassWithMultiStrParamCons` | 3 | 5.1s |  |
| 26 | `as3/Definitions/Classes/ClassDef/dynfinClassWithParamCons` | 1 | 5.2s |  |
| 27 | `as3/Definitions/Classes/ClassDef/dynfinClassWithStrParamCons` | 4 | 5.1s |  |
| 28 | `as3/Definitions/Classes/ClassDef/finClassNoParamCons` | 1 | 5.0s |  |
| 29 | `as3/Definitions/Classes/ClassDef/finalClassDefCons` | 1 | 2.0s |  |
| 30 | `as3/Definitions/Classes/ClassDef/finalClassWithParamCons` | 1 | 2.0s |  |
| 31 | `as3/Definitions/Classes/ClassDef/intClassDefCons` | 1 | 6.0s |  |
| 32 | `as3/Definitions/Classes/ClassDef/intClassNoParamCons` | 1 | 6.0s |  |
| 33 | `as3/Definitions/Classes/ClassDef/intClassWithParamCons` | 1 | 6.0s |  |
| 34 | `as3/Definitions/Classes/ClassDef/publicClassConsNoParam` | 1 | 6.0s |  |
| 35 | `as3/Definitions/Classes/ClassDef/publicClassDefCons` | 4 | 6.0s |  |
| 36 | `as3/Definitions/Classes/ClassDef/publicClassWithParamCons` | 1 | 6.0s |  |
| 37 | `as3/Definitions/Classes/ClassDef/testClassInitializers` | 3 | 6.1s |  |
| 38 | `as3/Definitions/Classes/ClassDef/testdynfinpublicClassInitializers` | 3 | 6.2s |  |
| 39 | `as3/Definitions/Classes/ClassDef/testinternalClassInitializers` | 3 | 6.2s |  |
| 40 | `as3/Definitions/Classes/Ext/AccNSStatMethSubClassMeth` | 6 | 6.2s |  |
| 41 | `as3/Definitions/Classes/Ext/AccNSStatPropSubClassMeth` | 6 | 6.2s |  |
| 42 | `as3/Definitions/Classes/Ext/AccStatMethIntermediateSubClassMeth` | 4 | 6.2s |  |
| 43 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMeth` | 6 | 6.2s |  |
| 44 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | 1 | 6.3s |  |
| 45 | `as3/Definitions/Classes/Ext/AccStatMethSubClassStatMeth` | 4 | 6.2s |  |
| 46 | `as3/Definitions/Classes/Ext/AccStatPropIntermediateSubClassMeth` | 6 | 6.1s |  |
| 47 | `as3/Definitions/Classes/Ext/AccStatPropSubClassInit` | 6 | 6.1s |  |
| 48 | `as3/Definitions/Classes/Ext/AccStatPropSubClassStatMeth` | 6 | 6.1s |  |
| 49 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | 3 | 6.2s |  |
| 50 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClassWIntermediate` | 3 | 6.2s |  |
| 51 | `as3/Definitions/Classes/Ext/DynExtDefaultClass` | 23 | 6.9s |  |
| 52 | `as3/Definitions/Classes/Ext/DynExtDefaultClassFin` | 21 | 6.5s |  |
| 53 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPub` | 40 | 6.7s |  |
| 54 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPubStat` | 24 | 6.7s |  |
| 55 | `as3/Definitions/Classes/Ext/DynExtDefaultClassStat` | 21 | 6.6s |  |
| 56 | `as3/Definitions/Classes/Ext/DynExtDynamicClass` | 16 | 6.4s |  |
| 57 | `as3/Definitions/Classes/Ext/DynExtDynamicClassFin` | 20 | 6.5s |  |
| 58 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPub` | 18 | 6.4s |  |
| 59 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPubStat` | 16 | 6.5s |  |
| 60 | `as3/Definitions/Classes/Ext/DynExtDynamicClassStat` | 22 | 6.6s |  |
| 61 | `as3/Definitions/Classes/Ext/DynExtInternalClass` | 21 | 6.9s |  |
| 62 | `as3/Definitions/Classes/Ext/DynExtPublicClass` | 8 | 6.4s |  |
| 63 | `as3/Definitions/Classes/Ext/DynExtPublicClassFin` | 24 | 6.6s |  |
| 64 | `as3/Definitions/Classes/Ext/DynExtPublicClassPub` | 16 | 6.5s |  |
| 65 | `as3/Definitions/Classes/Ext/DynExtPublicClassPubStat` | 14 | 6.5s |  |
| 66 | `as3/Definitions/Classes/Ext/DynExtPublicClassStat` | 14 | 6.5s |  |
| 67 | `as3/Definitions/Classes/Ext/ExtDefaultClass` | 20 | 7.0s |  |
| 68 | `as3/Definitions/Classes/Ext/ExtDefaultClassPub` | 14 | 6.5s |  |
| 69 | `as3/Definitions/Classes/Ext/ExtDefaultClassPubStat` | 26 | 6.7s |  |
| 70 | `as3/Definitions/Classes/Ext/ExtDefaultClassStat` | 25 | 6.6s |  |
| 71 | `as3/Definitions/Classes/Ext/ExtDefaultProtClass` | 20 | 6.8s |  |
| 72 | `as3/Definitions/Classes/Ext/ExtDynamicClass` | 19 | 6.4s |  |
| 73 | `as3/Definitions/Classes/Ext/ExtDynamicClassPub` | 21 | 6.5s |  |
| 74 | `as3/Definitions/Classes/Ext/ExtDynamicClassPubStat` | 26 | 6.5s |  |
| 75 | `as3/Definitions/Classes/Ext/ExtDynamicClassStat` | 24 | 6.5s |  |
| 76 | `as3/Definitions/Classes/Ext/ExtError` | 40 | 6.5s |  |
| 77 | `as3/Definitions/Classes/Ext/ExtInternalClass` | 20 | 6.9s |  |
| 78 | `as3/Definitions/Classes/Ext/ExtPublicClass` | 7 | 6.5s |  |
| 79 | `as3/Definitions/Classes/Ext/ExtPublicClassFin` | 10 | 6.6s |  |
| 80 | `as3/Definitions/Classes/Ext/ExtPublicClassPub` | 14 | 6.6s |  |
| 81 | `as3/Definitions/Classes/Ext/ExtPublicClassStat` | 28 | 6.7s |  |
| 82 | `as3/Definitions/Classes/Ext/IntExtDefaultClass` | 22 | 6.8s |  |
| 83 | `as3/Definitions/Classes/Ext/IntExtDynamicClass` | 20 | 6.7s |  |
| 84 | `as3/Definitions/Classes/Ext/IntExtInternalClass` | 20 | 6.8s |  |
| 85 | `as3/Definitions/Classes/Ext/IntExtPublicClass` | 20 | 6.8s |  |
| 86 | `as3/Definitions/Classes/Ext/PubExtDefaultClass` | 19 | 6.3s |  |
| 87 | `as3/Definitions/Classes/Ext/PubExtDefaultClassFin` | 16 | 6.3s |  |
| 88 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPub` | 20 | 6.3s |  |
| 89 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPubStat` | 29 | 6.5s |  |
| 90 | `as3/Definitions/Classes/Ext/PubExtDefaultClassStat` | 27 | 6.6s |  |
| 91 | `as3/Definitions/Classes/Ext/PubExtDynamicClass` | 18 | 6.3s |  |
| 92 | `as3/Definitions/Classes/Ext/PubExtDynamicClassFin` | 18 | 6.2s |  |
| 93 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPub` | 20 | 6.2s |  |
| 94 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPubStat` | 29 | 6.4s |  |
| 95 | `as3/Definitions/Classes/Ext/PubExtDynamicClassStat` | 29 | 5.4s |  |
| 96 | `as3/Definitions/Classes/Ext/PubExtInternalClass` | 17 | 6.2s |  |
| 97 | `as3/Definitions/Classes/Ext/PubExtPublicClass` | 12 | 6.1s |  |
| 98 | `as3/Definitions/Classes/Ext/PubExtPublicClassFin` | 16 | 6.2s |  |
| 99 | `as3/Definitions/Classes/Ext/PubExtPublicClassStat` | 27 | 6.4s |  |
| 100 | `as3/Definitions/Classes/Ext/PubFinExtDefaultClass` | 22 | 6.4s |  |
| 101 | `as3/Definitions/Function/EmptyFunctionBody` | 24 | 6.1s |  |
| 102 | `as3/Definitions/Function/EmptyFunctionName` | 52 | 6.3s |  |
| 103 | `as3/Definitions/Function/FinalFunctionBody` | 12 | 6.0s |  |
| 104 | `as3/Definitions/Function/FinalFunctionName` | 28 | 6.0s |  |
| 105 | `as3/Definitions/Function/MultiOptArgFunction` | 12 | 6.1s |  |
| 106 | `as3/Definitions/Function/MultipleExtraArgFunction1` | 4 | 5.8s |  |
| 107 | `as3/Definitions/Function/MultipleExtraArgFunction2` | 4 | 5.8s |  |
| 108 | `as3/Definitions/Function/MultipleExtraArgFunction3` | 4 | 5.8s |  |
| 109 | `as3/Definitions/Function/NamespaceFunctionBody` | 12 | 5.9s |  |
| 110 | `as3/Definitions/Function/NamespaceFunctionName` | 28 | 6.0s |  |
| 111 | `as3/Definitions/Function/NoExtraArgFunction` | 4 | 5.8s |  |
| 112 | `as3/Definitions/Function/OneExtraArgFunction` | 20 | 3.1s |  |
| 113 | `as3/Definitions/Function/OneOptArgFunction` | 12 | 5.9s |  |
| 114 | `as3/Definitions/Function/OverrideFunctionBody` | 12 | 5.9s |  |
| 115 | `as3/Definitions/Function/OverrideFunctionName` | 28 | 6.1s |  |
| 116 | `as3/Definitions/Function/PrivateFunctionBody` | 12 | 6.0s |  |
| 117 | `as3/Definitions/Function/PrivateFunctionName` | 26 | 6.0s |  |
| 118 | `as3/Definitions/Function/PublicFunctionBody` | 24 | 6.1s |  |
| 119 | `as3/Definitions/Function/PublicFunctionName` | 54 | 6.4s |  |
| 120 | `as3/Definitions/Function/RestGlobal` | 17 | 5.8s |  |
| 121 | `as3/Definitions/Function/StaticFunctionBody` | 12 | 5.9s |  |
| 122 | `as3/Definitions/Function/StaticFunctionName` | 26 | 6.0s |  |
| 123 | `as3/Definitions/Function/StaticPrivateFunctionName` | 13 | 5.9s |  |
| 124 | `as3/Definitions/Function/StaticPublicFunctionName` | 13 | 6.0s |  |
| 125 | `as3/Definitions/Function/ThreeOptArgFunction` | 4 | 5.9s |  |
| 126 | `as3/Definitions/Function/VirtualFunctionBody` | 12 | 3.1s |  |
| 127 | `as3/Definitions/Function/VirtualFunctionName` | 28 | 5.4s |  |
| 128 | `as3/Definitions/Function/VoidEvaluation` | 3 | 5.9s |  |
| 129 | `as3/Definitions/Function/bug152222` | 2 | 5.8s |  |
| 130 | `as3/Definitions/Function/functionReturnTypes` | 319 | 7.6s |  |
| 131 | `as3/Definitions/Interfaces/Example_1_1_6` | 2 | 5.8s |  |
| 132 | `as3/Definitions/Interfaces/Example_9_3` | 4 | 5.8s |  |
| 133 | `as3/Definitions/Interfaces/ExtendMultipleInterfaces` | 8 | 6.1s |  |
| 134 | `as3/Definitions/Interfaces/GetSet` | 10 | 5.9s |  |
| 135 | `as3/Definitions/Interfaces/ImplementByExtension` | 6 | 5.9s |  |
| 136 | `as3/Definitions/Interfaces/ImplementMultipleInterfaces` | 8 | 5.6s |  |
| 137 | `as3/Definitions/Interfaces/InterfaceAsType` | 11 | 5.6s |  |
| 138 | `as3/Definitions/Interfaces/Lattice` | 7 | 5.5s |  |
| 139 | `as3/Definitions/Interfaces/bug127174` | 1 | 5.5s |  |
| 140 | `as3/Definitions/Super/SuperArgsCall` | 4 | 5.5s |  |
| 141 | `as3/Definitions/Super/SuperExprChainAccess` | 10 | 5.6s |  |
| 142 | `as3/Definitions/Super/SuperImplicitlyCalled` | 4 | 5.5s |  |
| 143 | `as3/Definitions/Super/SuperObject` | 1 | 5.4s |  |
| 144 | `as3/Definitions/Super/SuperObjectCall` | 1 | 5.5s |  |
| 145 | `as3/Definitions/Variable/ConstVariables_custom2` | 22 | 5.6s |  |
| 146 | `as3/Definitions/Variable/ModifyClassConstGlobally_rt` | 1 | 5.3s |  |
| 147 | `as3/Definitions/Variable/ModifyClassVariableInObjectInstance_rt` | 1 | 5.4s |  |
| 148 | `as3/Definitions/Variable/ModifyPackageConstGlobally_rt` | 1 | 5.4s |  |
| 149 | `as3/Definitions/Variable/ModifyVariables` | 25 | 5.6s |  |
| 150 | `as3/Definitions/Variable/ProtectedVariables` | 8 | 5.5s |  |
| 151 | `as3/Definitions/Variable/VarDefEmpty` | 44 | 5.8s |  |
| 152 | `as3/Definitions/Variable/VarDefOutside` | 20 | 5.4s |  |
| 153 | `as3/Definitions/Variable/VarDefOutsideNoVar` | 9 | 5.4s |  |
| 154 | `as3/Definitions/Variable/VarDefPrivate` | 44 | 5.8s |  |
| 155 | `as3/Definitions/Variable/VarDefPrivateStatic` | 44 | 6.0s |  |
| 156 | `as3/Definitions/Variable/VarDefPublic` | 44 | 5.9s |  |
| 157 | `as3/Definitions/Variable/VarDefPublicStatic` | 44 | 6.0s |  |
| 158 | `as3/Definitions/Variable/VarDefStatic` | 44 | 5.2s |  |
| 159 | `as3/Definitions/const/ConstAccessFromClass` | 1 | 5.5s |  |
| 160 | `as3/Definitions/const/ConstAccessWithinClass` | 1 | 5.5s |  |
| 161 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName` | 1 | 5.5s |  |
| 162 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName2` | 1 | 5.5s |  |
| 163 | `as3/Definitions/const/ConstAndFunctionArgWithSameName` | 1 | 5.5s |  |
| 164 | `as3/Definitions/const/ConstAndFunctionArgWithSameName2` | 1 | 5.5s |  |
| 165 | `as3/Definitions/const/ConstAsVarReplacement` | 1 | 5.5s |  |
| 166 | `as3/Definitions/const/ConstConditionalInitialization` | 1 | 5.5s |  |
| 167 | `as3/Definitions/const/ConstConditionalInitializationInClass` | 1 | 5.5s |  |
| 168 | `as3/Definitions/const/ConstConditionalInitializationInClass2` | 1 | 5.5s |  |
| 169 | `as3/Definitions/const/ConstConditionalInitializationInClass3_rt` | 1 | 5.6s |  |
| 170 | `as3/Definitions/const/ConstConditionalInitializationInFunc` | 1 | 5.5s |  |
| 171 | `as3/Definitions/const/ConstInPackage` | 1 | 5.5s |  |
| 172 | `as3/Definitions/const/ConstInPackage2` | 1 | 5.5s |  |
| 173 | `as3/Definitions/const/ConstInPackageWithClass` | 1 | 5.5s |  |
| 174 | `as3/Definitions/const/ConstInPackageWithFunction` | 1 | 5.5s |  |
| 175 | `as3/Definitions/const/ConstInitializationInsideConstructor` | 1 | 2.7s |  |
| 176 | `as3/Definitions/const/ConstInitializationOutsideClass_rt` | 1 | 5.6s |  |
| 177 | `as3/Definitions/const/ConstInsideClass` | 1 | 5.5s |  |
| 178 | `as3/Definitions/const/ConstKeyword` | 1 | 5.1s |  |
| 179 | `as3/Definitions/const/ConstReinit_rt` | 1 | 5.5s |  |
| 180 | `as3/Definitions/const/ConstVarAsClassProp` | 2 | 5.5s |  |
| 181 | `as3/Definitions/const/ConstVarInsideClassFunction` | 1 | 5.4s |  |
| 182 | `as3/Definitions/const/ConstVarInsideClassFunction2_rt` | 1 | 5.5s |  |
| 183 | `as3/Definitions/const/ConstVarInsideGlobalFunction` | 1 | 6.0s |  |
| 184 | `as3/Definitions/const/ConstVarInsideGlobalFunction2` | 1 | 5.9s |  |
| 185 | `as3/Definitions/const/ConstVarInsideGlobalFunction3` | 1 | 3.1s |  |
| 186 | `as3/Definitions/const/ConstVarInsideGlobalFunction4` | 1 | 5.9s |  |
| 187 | `as3/Definitions/const/ConstVarInsideGlobalFunction5_rt` | 1 | 6.0s |  |
| 188 | `as3/Definitions/const/ConstVarInsideGlobalFunction6` | 4 | 6.0s |  |
| 189 | `as3/Definitions/const/ConstWithinClass` | 1 | 5.9s |  |
| 190 | `as3/Definitions/const/ConstWithinPackage` | 1 | 3.1s |  |
| 191 | `as3/Definitions/const/GlobalConstInitialization2_rt` | 1 | 6.0s |  |
| 192 | `as3/Definitions/const/GlobalConstInitialization_rt` | 1 | 6.0s |  |
| 193 | `as3/Definitions/const/StaticConst` | 1 | 5.9s |  |
| 194 | `as3/Definitions/const/StaticConstInDerivedClass` | 1 | 5.8s |  |
| 195 | `as3/Definitions/const/StaticConstInitializationOutsideClass_rt` | 1 | 5.9s |  |
| 196 | `as3/Expressions/QualifiedReferences/AS3NSReferences` | 3 | 3.1s |  |
| 197 | `as3/Expressions/QualifiedReferences/DescendantOperator` | 3 | 6.1s |  |
| 198 | `as3/Expressions/QualifiedReferences/FilterOperator` | 2 | 6.1s |  |
| 199 | `as3/Expressions/QualifiedReferences/MultipleNamespaces` | 7 | 6.0s |  |
| 200 | `as3/Expressions/QualifiedReferences/NSSingleFunc` | 3 | 6.0s |  |
| 201 | `as3/Expressions/QualifiedReferences/ReturnNSReference` | 3 | 6.0s |  |
| 202 | `as3/Expressions/QualifiedReferences/ReturnNamespace` | 1 | 6.0s |  |
| 203 | `as3/Expressions/asOperator/asOperator` | 75 | 6.5s |  |
| 204 | `as3/Expressions/asOperator/asOperatorConversions` | 48 | 6.3s |  |
| 205 | `as3/Expressions/asOperator/asOperatorMuliti` | 12 | 6.0s |  |
| 206 | `as3/Expressions/asOperator/asOperatorTypes` | 48 | 6.2s |  |
| 207 | `as3/Expressions/asOperator/asTypeError` | 2 | 6.0s |  |
| 208 | `as3/Expressions/deleteOperator/deleteArray` | 9 | 6.0s |  |
| 209 | `as3/Expressions/deleteOperator/deleteClass` | 1 | 5.9s |  |
| 210 | `as3/Expressions/deleteOperator/deleteInstantiatedFunction` | 4 | 5.9s |  |
| 211 | `as3/Expressions/deleteOperator/deleteInstantiatedVar` | 2 | 5.9s |  |
| 212 | `as3/Expressions/deleteOperator/deleteNonexistentDynamicProperty` | 1 | 6.0s |  |
| 213 | `as3/Expressions/deleteOperator/deleteNoninstantiatedFunction` | 2 | 5.8s |  |
| 214 | `as3/Expressions/deleteOperator/deleteNoninstantiatedVar` | 2 | 3.1s |  |
| 215 | `as3/Expressions/e11_2_2_1` | 4 | 6.0s |  |
| 216 | `as3/Expressions/e11_2_4` | 25 | 6.2s |  |
| 217 | `as3/Expressions/e11_4_3` | 86 | 6.6s |  |
| 218 | `as3/Expressions/e11_9_4` | 56 | 6.5s |  |
| 219 | `as3/Expressions/e11_9_5` | 56 | 3.7s |  |
| 220 | `as3/Expressions/indexProperties` | 36 | 6.5s |  |
| 221 | `as3/Expressions/isOperator/isOper` | 429 | 6.4s |  |
| 222 | `as3/Expressions/isOperator/isOperTypeError` | 2 | 6.0s |  |
| 223 | `as3/Expressions/logicalAssignment` | 16 | 6.0s |  |
| 224 | `as3/Expressions/logicalAssignment2` | 4 | 6.0s |  |
| 225 | `as3/Expressions/postfix` | 14 | 6.0s |  |
| 226 | `as3/Math/MathClass` | 2 | 3.1s |  |
| 227 | `as3/Math/MathUtils` | 7 | 6.0s |  |
| 228 | `as3/Math/e15_8_2_11_rest` | 6 | 6.0s |  |
| 229 | `as3/Math/e15_8_2_12_rest` | 12 | 6.1s |  |
| 230 | `as3/Math/op_divide_703238` | 9 | 6.0s |  |
| 231 | `as3/Math/op_subtract_703238` | 8 | 5.9s |  |
| 232 | `as3/MethodClosures/MethodClosure` | 1 | 6.0s |  |
| 233 | `as3/MethodClosures/MethodClosureFunc` | 1 | 6.0s |  |
| 234 | `as3/RegExp/bug_513020` | 2 | 6.0s |  |
| 235 | `as3/RegExp/eregress_122076` | 1 | 6.1s |  |
| 236 | `as3/RuntimeErrors/Error1002PrecisionArgOutOfRange` | 1 | 6.0s |  |
| 237 | `as3/RuntimeErrors/Error1003RadixArgOutOfRange` | 1 | 6.1s |  |
| 238 | `as3/RuntimeErrors/Error1005ArrayIndexNotInteger` | 1 | 6.0s |  |
| 239 | `as3/RuntimeErrors/Error1006CallNonFunctionObject` | 2 | 6.0s |  |
| 240 | `as3/RuntimeErrors/Error1007InstantiationOnNonConstructor` | 1 | 6.0s |  |
| 241 | `as3/RuntimeErrors/Error1009CannotAccessPropOfNullRef` | 1 | 3.1s |  |
| 242 | `as3/RuntimeErrors/Error1010UndefinedTerm` | 1 | 6.0s |  |
| 243 | `as3/RuntimeErrors/Error1016DescendantsOpNotSupported` | 1 | 6.0s |  |
| 244 | `as3/RuntimeErrors/Error1034TypeCoercionFailed` | 1 | 6.0s |  |
| 245 | `as3/RuntimeErrors/Error1037CannotAssignMethod` | 1 | 6.1s |  |
| 246 | `as3/RuntimeErrors/Error1040InvalidRHSOfInstanceof` | 1 | 6.0s |  |
| 247 | `as3/RuntimeErrors/Error1041RHSOfIsMustBeClass` | 1 | 3.1s |  |
| 248 | `as3/RuntimeErrors/Error1056CannotCreatePropInSealedClass` | 1 | 6.1s |  |
| 249 | `as3/RuntimeErrors/Error1065VariableNotDefined` | 1 | 6.2s |  |
| 250 | `as3/RuntimeErrors/Error1069PropertyNotFound` | 1 | 5.9s |  |
| 251 | `as3/RuntimeErrors/Error1070MethodNotFound` | 1 | 6.0s |  |
| 252 | `as3/RuntimeErrors/Error1077IllegalReadOfWriteOnlyProp` | 1 | 6.0s |  |
| 253 | `as3/RuntimeErrors/Error1083XmlPrefixNotFound` | 1 | 6.0s |  |
| 254 | `as3/RuntimeErrors/Error1084XmlQNameProductionMismatch` | 1 | 6.0s |  |
| 255 | `as3/RuntimeErrors/Error1085XmlEndTagMissing` | 1 | 3.2s |  |
| 256 | `as3/RuntimeErrors/Error1086XmlMethodOnlyOnListWithOneItem` | 1 | 6.0s |  |
| 257 | `as3/RuntimeErrors/Error1087XmlAssignToIndexedXml` | 2 | 3.0s |  |
| 258 | `as3/RuntimeErrors/Error1088XmlDocNotWellFormed` | 1 | 6.0s |  |
| 259 | `as3/RuntimeErrors/Error1089XmlAssignToMoreThanOneItemList` | 2 | 6.0s |  |
| 260 | `as3/RuntimeErrors/Error1090XmlElementMalformed` | 1 | 3.0s |  |
| 261 | `as3/RuntimeErrors/Error1091XmlUnterminatedCdata` | 1 | 6.0s |  |
| 262 | `as3/RuntimeErrors/Error1093XmlUnterminatedDoctype` | 1 | 3.1s |  |
| 263 | `as3/RuntimeErrors/Error1094XmlUnterminatedComment` | 1 | 6.0s |  |
| 264 | `as3/RuntimeErrors/Error1097XmlUnterminatedProcessingInstr` | 1 | 6.0s |  |
| 265 | `as3/RuntimeErrors/Error1098XmlIllegalPrefixFoNoNamespace` | 1 | 3.1s |  |
| 266 | `as3/RuntimeErrors/Error1100RegExpFlagsArg` | 1 | 6.0s |  |
| 267 | `as3/RuntimeErrors/Error1104XmlDuplicateAttr` | 1 | 5.9s |  |
| 268 | `as3/RuntimeErrors/Error1115NotAConstructor/v11` | 3 | 6.2s |  |
| 269 | `as3/RuntimeErrors/Error1116FunctionProtoApply2ndArgMustBeArr` | 1 | 6.0s |  |
| 270 | `as3/RuntimeErrors/Error1118IllegalCyclicalLoop` | 2 | 6.0s |  |
| 271 | `as3/ShellClasses/Dictionary` | 22 | 6.1s |  |
| 272 | `as3/Statements/Exceptions/MultipleCatchBlocks2` | 7 | 6.2s |  |
| 273 | `as3/Statements/Exceptions/MultipleCatchBlocksArgument` | 1 | 6.1s |  |
| 274 | `as3/Statements/Exceptions/MultipleCatchBlocksEval` | 1 | 3.2s |  |
| 275 | `as3/Statements/Exceptions/MultipleCatchBlocksRange` | 1 | 6.1s |  |
| 276 | `as3/Statements/Exceptions/MultipleCatchBlocksRefErrorCaughtWithError` | 1 | 6.0s |  |
| 277 | `as3/Statements/Exceptions/MultipleCatchBlocksReference` | 1 | 6.1s |  |
| 278 | `as3/Statements/Exceptions/MultipleCatchBlocksType` | 1 | 6.1s |  |
| 279 | `as3/Statements/Exceptions/MultipleCatchBlocksType1` | 1 | 6.0s |  |
| 280 | `as3/Statements/Exceptions/MultipleCatchBlocksType2` | 1 | 5.9s |  |
| 281 | `as3/Statements/Exceptions/MultipleCatchBlocksType3` | 1 | 5.9s |  |
| 282 | `as3/Statements/Exceptions/MultipleCatchBlocksType4` | 1 | 5.9s |  |
| 283 | `as3/Statements/Exceptions/MultipleCatchBlocksType5` | 1 | 1.4s |  |
| 284 | `as3/Statements/Exceptions/MultipleCatchBlocksType6` | 1 | 1.4s |  |
| 285 | `as3/Statements/Exceptions/MultipleCatchBlocksType7` | 1 | 6.0s |  |
| 286 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArg1` | 1 | 6.1s |  |
| 287 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArgErrorCaughtByError` | 1 | 6.1s |  |
| 288 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDef1` | 1 | 6.0s |  |
| 289 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDefErrorCaughtWithError` | 1 | 6.1s |  |
| 290 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEval1` | 1 | 6.0s |  |
| 291 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEvalErrorCaughtByError` | 1 | 6.0s |  |
| 292 | `as3/Statements/Exceptions/MultipleCatchBlocksWithNoTypeErrorCatchBlock` | 1 | 6.0s |  |
| 293 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRange1` | 1 | 6.1s |  |
| 294 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRangeErrorCaughtByError` | 1 | 6.0s |  |
| 295 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRefError1` | 1 | 6.1s |  |
| 296 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntax` | 1 | 1.5s |  |
| 297 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntaxErrorCaughtByError` | 1 | 1.5s |  |
| 298 | `as3/Statements/Exceptions/MultipleCatchBlocksWithTwoType` | 2 | 6.1s |  |
| 299 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURI1` | 1 | 6.0s |  |
| 300 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURICaughtByError` | 1 | 5.4s |  |
| 301 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUninitialized1` | 1 | 6.1s |  |
| 302 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUnitializedCaughtWithError` | 1 | 6.1s |  |
| 303 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerify1` | 1 | 6.2s |  |
| 304 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerifyCaughtByError` | 1 | 1.0s |  |
| 305 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchBlocksTypeWithNoInnerCatchType` | 2 | 6.3s |  |
| 306 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchRefType` | 2 | 6.3s |  |
| 307 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideEighthCatch` | 2 | 6.3s |  |
| 308 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideFifthCatch` | 2 | 6.3s |  |
| 309 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSeventhCatch` | 2 | 3.3s |  |
| 310 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSixthCatch` | 2 | 3.4s |  |
| 311 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinally` | 2 | 6.2s |  |
| 312 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinallyExceptionBubbling` | 1 | 6.4s |  |
| 313 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatch` | 2 | 6.2s |  |
| 314 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatchWithoutMatchingCatch` | 2 | 6.2s |  |
| 315 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatch` | 2 | 6.1s |  |
| 316 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatchWithoutMatchingCatch` | 2 | 6.2s |  |
| 317 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatch` | 2 | 6.6s |  |
| 318 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatchWithoutMatchingCatch` | 1 | 6.5s |  |
| 319 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTry` | 1 | 6.6s |  |
| 320 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTryWithoutMatchingCatch` | 1 | 6.6s |  |
| 321 | `as3/Statements/Exceptions/TryCatchBlockPackage` | 1 | 6.5s |  |
| 322 | `as3/Statements/Exceptions/TryCatchBlockPackage2` | 1 | 6.5s |  |
| 323 | `as3/Statements/Exceptions/TryCatchBlockPackage3` | 1 | 3.5s |  |
| 324 | `as3/Statements/Exceptions/UserDefinedErrorsInPackage` | 1 | 6.5s |  |
| 325 | `as3/Statements/Exceptions/UserDefinedErrorsPackage` | 1 | 6.5s |  |
| 326 | `as3/Statements/Exceptions/UserDefinedErrorsPackage2` | 1 | 6.4s |  |
| 327 | `as3/Statements/Exceptions/UserDefinedErrorsPackage3` | 1 | 6.4s |  |
| 328 | `as3/Statements/Exceptions/UserDefinedErrorsPackageWithoutMatchingCatch` | 1 | 6.3s |  |
| 329 | `as3/Statements/e12_6_3_12` | 1 | 6.2s |  |
| 330 | `as3/Statements/for-each-in/eforeachin_001` | 8 | 6.7s |  |
| 331 | `as3/Statements/for-each-in/eforeachin_001_500476` | 2 | 6.2s |  |
| 332 | `as3/Statements/for-each-in/eforeachin_002` | 2 | 6.2s |  |
| 333 | `as3/Statements/switch/switch_000` | 3 | 6.2s |  |
| 334 | `as3/Statements/switch/switch_001` | 6 | 6.3s |  |
| 335 | `as3/Statements/switch/switch_002` | 5 | 6.3s |  |
| 336 | `as3/Statements/switch/switch_003` | 6 | 6.4s |  |
| 337 | `as3/String/localeCompare_585791/v12` | 8 | 6.3s |  |
| 338 | `as3/Types/Conversions/ExplicitConversions` | 54 | 6.4s |  |
| 339 | `as3/Types/Conversions/ImplicitConversions1_23` | 6 | 6.2s |  |
| 340 | `as3/Types/Conversions/ImplicitConversionsFalse` | 10 | 6.3s |  |
| 341 | `as3/Types/Conversions/ImplicitConversionsNaN` | 6 | 6.2s |  |
| 342 | `as3/Types/Conversions/ImplicitConversionsNeg1_23` | 10 | 6.3s |  |
| 343 | `as3/Types/Conversions/ImplicitConversionsNull` | 10 | 6.2s |  |
| 344 | `as3/Types/Conversions/ImplicitConversionsString` | 20 | 6.4s |  |
| 345 | `as3/Types/Conversions/ImplicitConversionsTrue` | 10 | 6.4s |  |
| 346 | `as3/Types/Conversions/ImplicitConversionsUndefined` | 11 | 6.3s |  |
| 347 | `as3/Types/Int/intConstructor` | 12 | 6.3s |  |
| 348 | `as3/Types/Int/intIs` | 12 | 6.3s |  |
| 349 | `as3/Types/Int/intType` | 2 | 6.2s |  |
| 350 | `as3/Types/Int/signed_unsigned` | 6 | 6.0s |  |
| 351 | `as3/Types/Int/wraparound` | 16 | 3.3s |  |
| 352 | `as3/Types/Number/visibility/v15` | 34 | 6.1s |  |
| 353 | `as3/Types/uint/UintFunctionArg` | 17 | 6.1s |  |
| 354 | `as3/Types/uint/UintHex` | 1 | 5.8s |  |
| 355 | `as3/Types/uint/UintIs` | 12 | 6.0s |  |
| 356 | `as3/Types/uint/UintPublicClassMethodArg` | 24 | 6.4s |  |
| 357 | `as3/Types/uint/UintType` | 1 | 6.0s |  |
| 358 | `as3/Types/uint/UintVarAsClassProp` | 1 | 6.1s |  |
| 359 | `as3/Types/uint/UintVarOperationInFunc` | 1 | 6.0s |  |
| 360 | `as3/Types/uint/UintVarOperationInFuncRet` | 1 | 6.0s |  |
| 361 | `as3/Types/uint/UintVarOperations` | 17 | 6.5s |  |
| 362 | `as3/Vector/Vector_double_methods` | 11 | 6.4s |  |
| 363 | `as3/Vector/Vector_object_methods` | 12 | 6.2s |  |
| 364 | `as3/Vector/Vector_uint_methods` | 2 | 5.8s |  |
| 365 | `as3/Vector/bug504525/v10` | 1 | 5.7s |  |
| 366 | `as3/Vector/bug504525/v11` | 1 | 5.7s |  |
| 367 | `as3/Vector/bug_683507` | 1 | 6.0s |  |
| 368 | `as3/Vector/concat` | 10 | 6.2s |  |
| 369 | `as3/Vector/concat_with_initializers` | 4 | 5.9s |  |
| 370 | `as3/Vector/constructor` | 18 | 6.4s |  |
| 371 | `as3/Vector/every` | 14 | 6.4s |  |
| 372 | `as3/Vector/every_initializers` | 5 | 5.8s |  |
| 373 | `as3/Vector/fixed_length` | 4 | 6.1s |  |
| 374 | `as3/Vector/get` | 7 | 6.0s |  |
| 375 | `as3/Vector/in` | 10 | 6.0s |  |
| 376 | `as3/Vector/in_initializers` | 10 | 6.4s |  |
| 377 | `as3/Vector/indexof` | 7 | 6.1s |  |
| 378 | `as3/Vector/indexof_initializers` | 7 | 6.1s |  |
| 379 | `as3/Vector/initializer_ws` | 2 | 5.7s |  |
| 380 | `as3/Vector/insert_remove` | 542 | 6.2s |  |
| 381 | `as3/Vector/interface_method_return_type` | 5 | 6.4s |  |
| 382 | `as3/Vector/join` | 4 | 5.7s |  |
| 383 | `as3/Vector/join_initializers` | 4 | 6.0s |  |
| 384 | `as3/Vector/lastindexof` | 5 | 5.7s |  |
| 385 | `as3/Vector/lastindexof_initializers` | 7 | 5.6s |  |
| 386 | `as3/Vector/length` | 9 | 5.6s |  |
| 387 | `as3/Vector/length_initializers` | 3 | 5.5s |  |
| 388 | `as3/Vector/nested_initializers` | 5 | 5.6s |  |
| 389 | `as3/Vector/optimization_tests` | 14 | 6.5s |  |
| 390 | `as3/Vector/pop` | 12 | 5.8s |  |
| 391 | `as3/Vector/push` | 12 | 6.1s |  |
| 392 | `as3/Vector/put` | 8 | 5.7s |  |
| 393 | `as3/Vector/reverse` | 5 | 5.6s |  |
| 394 | `as3/Vector/reverse_initializers` | 4 | 5.5s |  |
| 395 | `as3/Vector/shift` | 12 | 5.8s |  |
| 396 | `as3/Vector/slice` | 1 | 5.5s |  |
| 397 | `as3/Vector/slice_initializers` | 5 | 5.6s |  |
| 398 | `as3/Vector/sort` | 9 | 6.0s |  |
| 399 | `as3/Vector/sort_initializers` | 1 | 5.7s |  |
| 400 | `as3/Vector/specialized_at_runtime` | 3 | 5.8s |  |
| 401 | `as3/Vector/splice` | 4 | 5.5s |  |
| 402 | `as3/Vector/static_initializer` | 4 | 5.5s |  |
| 403 | `as3/Vector/tostring` | 7 | 5.5s |  |
| 404 | `as3/Vector/tostring_initializer` | 5 | 5.5s |  |
| 405 | `as3/Vector/typechecking` | 10 | 5.9s |  |
| 406 | `as3/Vector/unshift` | 7 | 5.8s |  |
| 407 | `e4x/Expressions/e11_1_3` | 8 | 5.9s |  |
| 408 | `e4x/Expressions/e11_1_5` | 17 | 6.0s |  |
| 409 | `e4x/Expressions/e11_2_1` | 40 | 6.5s |  |
| 410 | `e4x/Expressions/e11_2_2` | 24 | 6.0s |  |
| 411 | `e4x/Expressions/e11_2_3` | 10 | 5.9s |  |
| 412 | `e4x/Expressions/e11_2_4` | 15 | 6.2s |  |
| 413 | `e4x/Expressions/e11_3_2` | 7 | 5.8s |  |
| 414 | `e4x/Expressions/e11_4_1` | 18 | 6.0s |  |
| 415 | `e4x/Expressions/e11_5_1` | 66 | 6.5s |  |
| 416 | `e4x/Expressions/e11_6_1` | 19 | 6.1s |  |
| 417 | `e4x/Expressions/e11_6_2` | 15 | 6.3s |  |
| 418 | `e4x/Expressions/e11_6_3` | 6 | 5.9s |  |
| 419 | `e4x/Expressions/kXMLBadQNameErr` | 5 | 5.9s |  |
| 420 | `e4x/Namespace/e13_2_1` | 19 | 5.9s |  |
| 421 | `e4x/Namespace/e13_2_2` | 22 | 6.0s |  |
| 422 | `e4x/Namespace/e13_2_3_1` | 3 | 6.0s |  |
| 423 | `e4x/Namespace/e13_2_4_1` | 3 | 5.9s |  |
| 424 | `e4x/Namespace/e13_2_4_2` | 4 | 5.9s |  |
| 425 | `e4x/QName/e13_3_1` | 22 | 6.1s |  |
| 426 | `e4x/QName/e13_3_3_1` | 3 | 5.5s |  |
| 427 | `e4x/QName/e13_3_4_1` | 2 | 5.9s |  |
| 428 | `e4x/QName/e13_3_4_2` | 4 | 6.0s |  |
| 429 | `e4x/QName/e13_3_5` | 13 | 6.0s |  |
| 430 | `e4x/Regress/b121219` | 2 | 6.0s |  |
| 431 | `e4x/Regress/error1085` | 2 | 5.9s |  |
| 432 | `e4x/Regress/regress-257679` | 2 | 5.9s |  |
| 433 | `e4x/Regress/regress-263934` | 2 | 6.0s |  |
| 434 | `e4x/Regress/regress-263936` | 2 | 6.0s |  |
| 435 | `e4x/Regress/regress-264369` | 2 | 5.9s |  |
| 436 | `e4x/Regress/regress-271545` | 6 | 6.0s |  |
| 437 | `e4x/Regress/regress-277650` | 2 | 3.1s |  |
| 438 | `e4x/Regress/regress-277664` | 2 | 6.0s |  |
| 439 | `e4x/Regress/regress-277683` | 2 | 6.0s |  |
| 440 | `e4x/Regress/regress-277779` | 2 | 6.0s |  |
| 441 | `e4x/Regress/regress-278112` | 4 | 3.0s |  |
| 442 | `e4x/Statements/e12_2` | 14 | 6.1s |  |
| 443 | `e4x/Statements/e12_3` | 5 | 6.0s |  |
| 444 | `e4x/TypeConversion/bug153363` | 3 | 6.0s |  |
| 445 | `e4x/TypeConversion/bug153363_2` | 3 | 5.9s |  |
| 446 | `e4x/TypeConversion/e10_1_1` | 3 | 6.0s |  |
| 447 | `e4x/TypeConversion/e10_1_2` | 5 | 6.0s |  |
| 448 | `e4x/TypeConversion/e10_2_1` | 5 | 6.0s |  |
| 449 | `e4x/TypeConversion/e10_2_1_1` | 5 | 5.9s |  |
| 450 | `e4x/TypeConversion/e10_2_1_2` | 13 | 6.0s |  |
| 451 | `e4x/TypeConversion/e10_2_2` | 2 | 5.9s |  |
| 452 | `e4x/TypeConversion/e10_3` | 7 | 6.1s |  |
| 453 | `e4x/TypeConversion/e10_3_1` | 2 | 6.0s |  |
| 454 | `e4x/TypeConversion/e10_4` | 9 | 6.1s |  |
| 455 | `e4x/TypeConversion/e10_4_1` | 8 | 6.0s |  |
| 456 | `e4x/Types/e9_1_1_1` | 32 | 6.7s |  |
| 457 | `e4x/Types/e9_1_1_10` | 2 | 5.9s |  |
| 458 | `e4x/Types/e9_1_1_11` | 2 | 5.5s |  |
| 459 | `e4x/Types/e9_1_1_12` | 2 | 5.5s |  |
| 460 | `e4x/Types/e9_1_1_13` | 2 | 5.5s |  |
| 461 | `e4x/Types/e9_1_1_2` | 6 | 6.1s |  |
| 462 | `e4x/Types/e9_1_1_3` | 5 | 6.0s |  |
| 463 | `e4x/Types/e9_1_1_4` | 2 | 5.9s |  |
| 464 | `e4x/Types/e9_1_1_5` | 2 | 5.4s |  |
| 465 | `e4x/Types/e9_1_1_6` | 11 | 6.0s |  |
| 466 | `e4x/Types/e9_1_1_7` | 2 | 2.5s |  |
| 467 | `e4x/Types/e9_1_1_8` | 2 | 5.5s |  |
| 468 | `e4x/Types/e9_1_1_9` | 20 | 6.4s |  |
| 469 | `e4x/Types/e9_2_1_1` | 11 | 6.1s |  |
| 470 | `e4x/Types/e9_2_1_10` | 2 | 6.1s |  |
| 471 | `e4x/Types/e9_2_1_2` | 19 | 6.3s |  |
| 472 | `e4x/Types/e9_2_1_3` | 2 | 5.6s |  |
| 473 | `e4x/Types/e9_2_1_4` | 2 | 5.6s |  |
| 474 | `e4x/Types/e9_2_1_5` | 2 | 2.7s |  |
| 475 | `e4x/Types/e9_2_1_6` | 2 | 5.5s |  |
| 476 | `e4x/Types/e9_2_1_7` | 2 | 5.6s |  |
| 477 | `e4x/Types/e9_2_1_8` | 2 | 6.0s |  |
| 478 | `e4x/Types/e9_2_1_9` | 11 | 6.2s |  |
| 479 | `e4x/XML/bug157597` | 2 | 6.0s |  |
| 480 | `e4x/XML/bug157597_2` | 2 | 5.6s |  |
| 481 | `e4x/XML/bug157735` | 2 | 6.0s |  |
| 482 | `e4x/XML/bug158506` | 2 | 6.0s |  |
| 483 | `e4x/XML/e13_4_1` | 18 | 6.2s |  |
| 484 | `e4x/XML/e13_4_2` | 36 | 6.8s |  |
| 485 | `e4x/XML/e13_4_3` | 35 | 6.6s |  |
| 486 | `e4x/XML/e13_4_3_1` | 5 | 6.0s |  |
| 487 | `e4x/XML/e13_4_3_2` | 8 | 6.1s |  |
| 488 | `e4x/XML/e13_4_3_3` | 8 | 6.1s |  |
| 489 | `e4x/XML/e13_4_3_4` | 11 | 6.2s |  |
| 490 | `e4x/XML/e13_4_3_5` | 5 | 6.1s |  |
| 491 | `e4x/XML/e13_4_3_6` | 10 | 6.3s |  |
| 492 | `e4x/XML/e13_4_3_7` | 31 | 6.3s |  |
| 493 | `e4x/XML/e13_4_3_8` | 41 | 6.3s |  |
| 494 | `e4x/XML/e13_4_3_9` | 11 | 3.3s |  |
| 495 | `e4x/XML/e13_4_4_1` | 3 | 6.1s |  |
| 496 | `e4x/XML/e13_4_4_10` | 11 | 6.2s |  |
| 497 | `e4x/XML/e13_4_4_11` | 12 | 6.2s |  |
| 498 | `e4x/XML/e13_4_4_12` | 15 | 6.1s |  |
| 499 | `e4x/XML/e13_4_4_13` | 7 | 6.1s |  |
| 500 | `e4x/XML/e13_4_4_14` | 12 | 6.1s |  |
| 501 | `e4x/XML/e13_4_4_15` | 16 | 6.2s |  |
| 502 | `e4x/XML/e13_4_4_16` | 25 | 6.3s |  |
| 503 | `e4x/XML/e13_4_4_18` | 16 | 6.6s |  |
| 504 | `e4x/XML/e13_4_4_19` | 16 | 6.8s |  |
| 505 | `e4x/XML/e13_4_4_20` | 11 | 6.0s |  |
| 506 | `e4x/XML/e13_4_4_21` | 16 | 6.1s |  |
| 507 | `e4x/XML/e13_4_4_22` | 15 | 6.1s |  |
| 508 | `e4x/XML/e13_4_4_23` | 17 | 6.3s |  |
| 509 | `e4x/XML/e13_4_4_24` | 22 | 6.2s |  |
| 510 | `e4x/XML/e13_4_4_25` | 15 | 6.1s |  |
| 511 | `e4x/XML/e13_4_4_26` | 6 | 6.1s |  |
| 512 | `e4x/XML/e13_4_4_27` | 21 | 6.1s |  |
| 513 | `e4x/XML/e13_4_4_29/v10` | 19 | 6.6s |  |
| 514 | `e4x/XML/e13_4_4_29/v9` | 19 | 6.6s |  |
| 515 | `e4x/XML/e13_4_4_3/v10` | 16 | 6.4s |  |
| 516 | `e4x/XML/e13_4_4_3/v21` | 16 | 5.5s |  |
| 517 | `e4x/XML/e13_4_4_3/v9` | 16 | 6.3s |  |
| 518 | `e4x/XML/e13_4_4_31` | 19 | 4.8s |  |
| 519 | `e4x/XML/e13_4_4_32/v10` | 9 | 4.7s |  |
| 520 | `e4x/XML/e13_4_4_33` | 6 | 4.7s |  |
| 521 | `e4x/XML/e13_4_4_34` | 12 | 4.9s |  |
| 522 | `e4x/XML/e13_4_4_35` | 17 | 5.0s |  |
| 523 | `e4x/XML/e13_4_4_37` | 12 | 4.7s |  |
| 524 | `e4x/XML/e13_4_4_38` | 17 | 4.8s |  |
| 525 | `e4x/XML/e13_4_4_39` | 20 | 4.8s |  |
| 526 | `e4x/XML/e13_4_4_4` | 19 | 4.8s |  |
| 527 | `e4x/XML/e13_4_4_40` | 7 | 4.7s |  |
| 528 | `e4x/XML/e13_4_4_5` | 12 | 4.7s |  |
| 529 | `e4x/XML/e13_4_4_6` | 31 | 4.9s |  |
| 530 | `e4x/XML/e13_4_4_7` | 7 | 4.7s |  |
| 531 | `e4x/XML/e13_4_4_8` | 7 | 4.7s |  |
| 532 | `e4x/XML/e13_4_4_9` | 14 | 4.8s |  |
| 533 | `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | 3 | 4.7s |  |
| 534 | `e4x/XML/kXMLMarkupMustBeWellFormedErr` | 3 | 4.7s |  |
| 535 | `e4x/XML/kXMLPrefixNotBoundErr` | 7 | 4.7s |  |
| 536 | `e4x/XML/kXMLUnterminatedElementTagErr` | 5 | 4.7s |  |
| 537 | `e4x/XMLList/bug157735` | 2 | 4.6s |  |
| 538 | `e4x/XMLList/e13_5_1` | 26 | 4.8s |  |
| 539 | `e4x/XMLList/e13_5_2` | 37 | 4.9s |  |
| 540 | `e4x/XMLList/e13_5_3_1` | 5 | 4.7s |  |
| 541 | `e4x/XMLList/e13_5_4_1` | 3 | 4.7s |  |
| 542 | `e4x/XMLList/e13_5_4_10` | 7 | 4.7s |  |
| 543 | `e4x/XMLList/e13_5_4_11` | 13 | 4.7s |  |
| 544 | `e4x/XMLList/e13_5_4_12` | 19 | 4.8s |  |
| 545 | `e4x/XMLList/e13_5_4_13` | 28 | 4.8s |  |
| 546 | `e4x/XMLList/e13_5_4_14` | 11 | 4.7s |  |
| 547 | `e4x/XMLList/e13_5_4_15` | 3 | 4.7s |  |
| 548 | `e4x/XMLList/e13_5_4_16` | 24 | 4.9s |  |
| 549 | `e4x/XMLList/e13_5_4_19` | 5 | 4.7s |  |
| 550 | `e4x/XMLList/e13_5_4_2` | 28 | 5.1s |  |
| 551 | `e4x/XMLList/e13_5_4_20` | 12 | 4.8s |  |
| 552 | `e4x/XMLList/e13_5_4_21` | 12 | 4.8s |  |
| 553 | `e4x/XMLList/e13_5_4_22` | 5 | 4.7s |  |
| 554 | `e4x/XMLList/e13_5_4_3` | 16 | 4.8s |  |
| 555 | `e4x/XMLList/e13_5_4_4` | 39 | 5.2s |  |
| 556 | `e4x/XMLList/e13_5_4_5` | 11 | 4.7s |  |
| 557 | `e4x/XMLList/e13_5_4_6` | 6 | 4.7s |  |
| 558 | `e4x/XMLList/e13_5_4_7` | 6 | 4.7s |  |
| 559 | `e4x/XMLList/e13_5_4_8` | 11 | 4.8s |  |
| 560 | `e4x/XMLList/e13_5_4_9` | 10 | 4.7s |  |
| 561 | `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | 29 | 5.2s |  |
| 562 | `ecma3/Array/bug_630945` | 6 | 4.6s |  |
| 563 | `ecma3/Array/e15_4_1_2` | 16 | 6.0s |  |
| 564 | `ecma3/Array/e15_4_1_3` | 4 | 5.8s |  |
| 565 | `ecma3/Array/e15_4_2` | 9 | 5.9s |  |
| 566 | `ecma3/Array/e15_4_2_1_1` | 7 | 5.9s |  |
| 567 | `ecma3/Array/e15_4_2_1_2` | 1025 | 5.7s |  |
| 568 | `ecma3/Array/e15_4_2_2_1` | 17 | 6.0s |  |
| 569 | `ecma3/Array/e15_4_2_2_2` | 8 | 5.9s |  |
| 570 | `ecma3/Array/e15_4_3` | 1 | 5.8s |  |
| 571 | `ecma3/Array/e15_4_4_1` | 1 | 5.8s |  |
| 572 | `ecma3/Array/e15_4_4_10` | 6 | 6.1s |  |
| 573 | `ecma3/Array/e15_4_4_11` | 16 | 5.9s |  |
| 574 | `ecma3/Array/e15_4_4_12` | 4 | 5.9s |  |
| 575 | `ecma3/Array/e15_4_4_13` | 7 | 5.9s |  |
| 576 | `ecma3/Array/e15_4_4_2` | 13 | 5.9s |  |
| 577 | `ecma3/Array/e15_4_4_3_1` | 1 | 5.8s |  |
| 578 | `ecma3/Array/e15_4_4_4_001` | 9 | 6.0s |  |
| 579 | `ecma3/Array/e15_4_4_4_1` | 1046 | 6.4s |  |
| 580 | `ecma3/Array/e15_4_4_4_2` | 4 | 6.0s |  |
| 581 | `ecma3/Array/e15_4_4_5_1` | 53 | 6.0s |  |
| 582 | `ecma3/Array/e15_4_4_5_2` | 53 | 5.9s |  |
| 583 | `ecma3/Array/e15_4_4_6` | 5 | 5.7s |  |
| 584 | `ecma3/Array/e15_4_4_6_1` | 1 | 5.8s |  |
| 585 | `ecma3/Array/e15_4_4_7` | 6 | 5.8s |  |
| 586 | `ecma3/Array/e15_4_4_8` | 4 | 5.8s |  |
| 587 | `ecma3/Array/e15_4_4_9` | 8 | 5.9s |  |
| 588 | `ecma3/Array/e15_4_4_9_1` | 1 | 2.6s |  |
| 589 | `ecma3/Array/e15_4_5_1_1` | 27 | 6.3s |  |
| 590 | `ecma3/Array/e15_4_5_1_2` | 13 | 5.9s |  |
| 591 | `ecma3/Array/e15_4_5_2_1` | 6 | 5.9s |  |
| 592 | `ecma3/Array/e15_4_5_2_2` | 11 | 6.0s |  |
| 593 | `ecma3/Array/e15_4__1` | 12 | 6.0s |  |
| 594 | `ecma3/Array/eregress_130451` | 7 | 6.0s |  |
| 595 | `ecma3/Array/general1` | 6 | 5.9s |  |
| 596 | `ecma3/Array/general2` | 2 | 5.9s |  |
| 597 | `ecma3/Array/general3` | 4 | 3.1s |  |
| 598 | `ecma3/Array/slice` | 2 | 6.0s |  |
| 599 | `ecma3/Array/sortOn` | 32 | 6.2s |  |
| 600 | `ecma3/Array/sparseArray` | 15 | 6.0s |  |
| 601 | `ecma3/Array/splice1` | 2 | 6.1s |  |
| 602 | `ecma3/Array/splice2` | 2 | 6.0s |  |
| 603 | `ecma3/Boolean/e15_6_1` | 20 | 6.0s |  |
| 604 | `ecma3/Boolean/e15_6_2` | 57 | 6.3s |  |
| 605 | `ecma3/Boolean/e15_6_3_1_1` | 1 | 5.8s |  |
| 606 | `ecma3/Boolean/e15_6_3_1_4` | 2 | 6.0s |  |
| 607 | `ecma3/Boolean/e15_6_3_1_5` | 1 | 6.0s |  |
| 608 | `ecma3/Boolean/e15_6_4_1` | 1 | 6.0s |  |
| 609 | `ecma3/Boolean/e15_6_4_2_1` | 24 | 6.2s |  |
| 610 | `ecma3/Boolean/e15_6_4_2_2` | 3 | 5.9s |  |
| 611 | `ecma3/Boolean/e15_6_4_2_3` | 2 | 6.0s |  |
| 612 | `ecma3/Boolean/e15_6_4_3` | 22 | 6.1s |  |
| 613 | `ecma3/Boolean/e15_6_4_3_1` | 22 | 5.6s |  |
| 614 | `ecma3/Boolean/e15_6_4_3_2` | 3 | 6.0s |  |
| 615 | `ecma3/Boolean/e15_6_4_3_3` | 2 | 6.0s |  |
| 616 | `ecma3/Boolean/ecma4_sealedtype_1_rt` | 1 | 6.0s |  |
| 617 | `ecma3/Boolean/ecma4_sealedtype_2_rt` | 1 | 6.0s |  |
| 618 | `ecma3/Boolean/ecma4_sealedtype_3_rt` | 1 | 6.0s |  |
| 619 | `ecma3/Boolean/ecma4_sealedtype_4_rt` | 1 | 6.0s |  |
| 620 | `ecma3/Boolean/ecma4_sealedtype_5_rt` | 1 | 6.0s |  |
| 621 | `ecma3/Boolean/ecma4_st_valueOf_1_rt` | 2 | 6.1s |  |
| 622 | `ecma3/Boolean/ecma4_st_valueOf_2_rt` | 2 | 6.0s |  |
| 623 | `ecma3/Boolean/ecma4_st_valueOf_3_rt` | 1 | 6.0s |  |
| 624 | `ecma3/Boolean/ecma4_st_valueOf_4_rt` | 1 | 6.0s |  |
| 625 | `ecma3/Boolean/ecma4_st_valueOf_5_rt` | 1 | 6.0s |  |
| 626 | `ecma3/ErrorObject/e15_11_1` | 42 | 6.2s |  |
| 627 | `ecma3/ErrorObject/e15_11_2_1` | 30 | 6.0s |  |
| 628 | `ecma3/Exceptions/binding_001` | 2 | 3.1s |  |
| 629 | `ecma3/Exceptions/boolean_001_rt` | 6 | 6.1s |  |
| 630 | `ecma3/Exceptions/boolean_002_rt` | 6 | 6.1s |  |
| 631 | `ecma3/Exceptions/date_001_rt` | 1 | 5.8s |  |
| 632 | `ecma3/Exceptions/date_003_rt` | 1 | 5.8s |  |
| 633 | `ecma3/Exceptions/e15_11_4_4_1` | 9 | 6.1s |  |
| 634 | `ecma3/Exceptions/exception_003_rt` | 1 | 5.8s |  |
| 635 | `ecma3/Exceptions/exception_004_rt` | 1 | 5.8s |  |
| 636 | `ecma3/Exceptions/exception_005_rt` | 1 | 5.4s |  |
| 637 | `ecma3/Exceptions/exception_006_rt` | 1 | 5.8s |  |
| 638 | `ecma3/Exceptions/exception_007_rt` | 1 | 5.8s |  |
| 639 | `ecma3/Exceptions/exception_009` | 1 | 5.8s |  |
| 640 | `ecma3/Exceptions/exception_010_rt` | 1 | 5.8s |  |
| 641 | `ecma3/Exceptions/exception_014_rt` | 2 | 5.8s |  |
| 642 | `ecma3/Exceptions/expression_002_rt` | 1 | 5.8s |  |
| 643 | `ecma3/Exceptions/expression_003_rt` | 1 | 5.8s |  |
| 644 | `ecma3/Exceptions/expression_004_rt` | 1 | 5.8s |  |
| 645 | `ecma3/Exceptions/expression_006_rt` | 1 | 5.8s |  |
| 646 | `ecma3/Exceptions/expression_007_rt` | 1 | 5.8s |  |
| 647 | `ecma3/Exceptions/expression_008_rt` | 1 | 3.0s |  |
| 648 | `ecma3/Exceptions/expression_009_rt` | 1 | 5.8s |  |
| 649 | `ecma3/Exceptions/expression_010_rt` | 1 | 5.8s |  |
| 650 | `ecma3/Exceptions/expression_011_rt` | 1 | 5.7s |  |
| 651 | `ecma3/Exceptions/expression_012_rt` | 1 | 5.7s |  |
| 652 | `ecma3/Exceptions/expression_013_rt` | 1 | 5.7s |  |
| 653 | `ecma3/Exceptions/expression_014_rt` | 1 | 5.7s |  |
| 654 | `ecma3/Exceptions/expression_016_rt` | 1 | 5.7s |  |
| 655 | `ecma3/Exceptions/expression_017_rt` | 1 | 5.7s |  |
| 656 | `ecma3/Exceptions/expression_019_rt` | 1 | 5.7s |  |
| 657 | `ecma3/Exceptions/global_001_rt` | 1 | 5.7s |  |
| 658 | `ecma3/Exceptions/global_002_rt` | 1 | 5.7s |  |
| 659 | `ecma3/Exceptions/number_003_rt` | 4 | 6.0s |  |
| 660 | `ecma3/Exceptions/number_004_rt` | 4 | 6.0s |  |
| 661 | `ecma3/Exceptions/regress_58946` | 1 | 5.7s |  |
| 662 | `ecma3/Exceptions/regress_95101` | 2 | 5.8s |  |
| 663 | `ecma3/ExecutionContexts/e10_1_3` | 1 | 5.7s |  |
| 664 | `ecma3/ExecutionContexts/e10_1_3_1` | 8 | 5.8s |  |
| 665 | `ecma3/ExecutionContexts/e10_1_4_1` | 1 | 5.7s |  |
| 666 | `ecma3/ExecutionContexts/e10_1_4_10` | 1 | 5.7s |  |
| 667 | `ecma3/ExecutionContexts/e10_1_4_2` | 1 | 2.9s |  |
| 668 | `ecma3/ExecutionContexts/e10_1_4_8` | 1 | 5.7s |  |
| 669 | `ecma3/ExecutionContexts/e10_1_4_9` | 1 | 5.5s |  |
| 670 | `ecma3/ExecutionContexts/e10_1_5_1` | 1 | 5.8s |  |
| 671 | `ecma3/ExecutionContexts/e10_1_5_2` | 1 | 5.7s |  |
| 672 | `ecma3/ExecutionContexts/e10_1_5_3` | 1 | 5.7s |  |
| 673 | `ecma3/ExecutionContexts/e10_1_5_4` | 1 | 5.7s |  |
| 674 | `ecma3/ExecutionContexts/e10_1_6` | 9 | 5.7s |  |
| 675 | `ecma3/ExecutionContexts/e10_1_8_1` | 7 | 5.7s |  |
| 676 | `ecma3/ExecutionContexts/e10_1_8_2` | 8 | 5.7s |  |
| 677 | `ecma3/ExecutionContexts/e10_2_1` | 1 | 5.7s |  |
| 678 | `ecma3/ExecutionContexts/e10_2_3_1` | 2 | 5.7s |  |
| 679 | `ecma3/ExecutionContexts/e10_2_3_2` | 2 | 5.7s |  |
| 680 | `ecma3/Expressions/StrictEquality_001` | 7 | 5.7s |  |
| 681 | `ecma3/Expressions/e11_10_1` | 31 | 6.1s |  |
| 682 | `ecma3/Expressions/e11_10_2` | 1089 | 6.1s |  |
| 683 | `ecma3/Expressions/e11_10_3` | 1089 | 6.1s |  |
| 684 | `ecma3/Expressions/e11_11` | 62 | 6.2s |  |
| 685 | `ecma3/Expressions/e11_12_1` | 7 | 5.7s |  |
| 686 | `ecma3/Expressions/e11_12_3` | 1 | 5.7s |  |
| 687 | `ecma3/Expressions/e11_12_4` | 1 | 5.7s |  |
| 688 | `ecma3/Expressions/e11_13` | 7 | 5.2s |  |
| 689 | `ecma3/Expressions/e11_13_1` | 1 | 5.7s |  |
| 690 | `ecma3/Expressions/e11_13_2_1` | 30 | 6.2s |  |
| 691 | `ecma3/Expressions/e11_13_2_2` | 31 | 6.3s |  |
| 692 | `ecma3/Expressions/e11_13_2_3` | 40 | 6.5s |  |
| 693 | `ecma3/Expressions/e11_13_2_4` | 26 | 3.3s |  |
| 694 | `ecma3/Expressions/e11_13_2_5` | 26 | 6.2s |  |
| 695 | `ecma3/Expressions/e11_14_1` | 3 | 5.7s |  |
| 696 | `ecma3/Expressions/e11_1_1` | 7 | 5.8s |  |
| 697 | `ecma3/Expressions/e11_1_5` | 20 | 6.0s |  |
| 698 | `ecma3/Expressions/e11_1_6` | 25 | 6.0s |  |
| 699 | `ecma3/Expressions/e11_2_1_2` | 8 | 5.8s |  |
| 700 | `ecma3/Expressions/e11_2_1_3` | 2 | 5.8s |  |
| 701 | `ecma3/Expressions/e11_2_1_4_rt` | 2 | 5.7s |  |
| 702 | `ecma3/Expressions/e11_2_1_5` | 10 | 5.8s |  |
| 703 | `ecma3/Expressions/e11_2_2_11` | 1 | 5.8s |  |
| 704 | `ecma3/Expressions/e11_2_2_12_rt` | 1 | 5.7s |  |
| 705 | `ecma3/Expressions/e11_2_2_1_rt` | 1 | 5.8s |  |
| 706 | `ecma3/Expressions/e11_2_2_2_rt` | 1 | 5.8s |  |
| 707 | `ecma3/Expressions/e11_2_2_3_rt` | 1 | 5.7s |  |
| 708 | `ecma3/Expressions/e11_2_2_4_rt` | 1 | 3.0s |  |
| 709 | `ecma3/Expressions/e11_2_2_5_rt` | 1 | 2.8s |  |
| 710 | `ecma3/Expressions/e11_2_2_6_rt` | 1 | 3.0s |  |
| 711 | `ecma3/Expressions/e11_2_2_7_rt` | 1 | 5.8s |  |
| 712 | `ecma3/Expressions/e11_2_2_8_rt` | 1 | 5.8s |  |
| 713 | `ecma3/Expressions/e11_2_2_9_rt` | 1 | 5.7s |  |
| 714 | `ecma3/Expressions/e11_2_3_1` | 4 | 5.7s |  |
| 715 | `ecma3/Expressions/e11_2_3_3_rt` | 1 | 5.8s |  |
| 716 | `ecma3/Expressions/e11_2_3_4_rt` | 1 | 5.7s |  |
| 717 | `ecma3/Expressions/e11_2_3_5` | 1 | 5.7s |  |
| 718 | `ecma3/Expressions/e11_3_1` | 58 | 6.2s |  |
| 719 | `ecma3/Expressions/e11_3_2` | 58 | 6.3s |  |
| 720 | `ecma3/Expressions/e11_4_2` | 24 | 5.9s |  |
| 721 | `ecma3/Expressions/e11_4_4` | 52 | 6.2s |  |
| 722 | `ecma3/Expressions/e11_4_5` | 52 | 6.0s |  |
| 723 | `ecma3/Expressions/e11_4_6` | 190 | 7.8s |  |
| 724 | `ecma3/Expressions/e11_4_7` | 146 | 7.1s |  |
| 725 | `ecma3/Expressions/e11_4_8` | 70 | 6.0s |  |
| 726 | `ecma3/Expressions/e11_4_9` | 27 | 5.9s |  |
| 727 | `ecma3/Expressions/e11_5_1` | 47 | 6.2s |  |
| 728 | `ecma3/Expressions/e11_5_2` | 58 | 6.4s |  |
| 729 | `ecma3/Expressions/e11_5_3` | 70 | 6.4s |  |
| 730 | `ecma3/Expressions/e11_6_1_1` | 12 | 5.8s |  |
| 731 | `ecma3/Expressions/e11_6_1_2` | 13 | 5.8s |  |
| 732 | `ecma3/Expressions/e11_6_2_1` | 18 | 6.0s |  |
| 733 | `ecma3/Expressions/e11_6_3` | 34 | 6.0s |  |
| 734 | `ecma3/Expressions/e11_7_1` | 1089 | 6.2s |  |
| 735 | `ecma3/Expressions/e11_7_2` | 2178 | 6.3s |  |
| 736 | `ecma3/Expressions/e11_7_3` | 1089 | 6.2s |  |
| 737 | `ecma3/Expressions/e11_8_1` | 53 | 6.4s |  |
| 738 | `ecma3/Expressions/e11_8_2` | 52 | 6.3s |  |
| 739 | `ecma3/Expressions/e11_8_3` | 56 | 6.4s |  |
| 740 | `ecma3/Expressions/e11_8_4` | 56 | 6.3s |  |
| 741 | `ecma3/Expressions/e11_8_7` | 29 | 6.1s |  |
| 742 | `ecma3/Expressions/e11_9_1` | 47 | 6.3s |  |
| 743 | `ecma3/Expressions/e11_9_2` | 47 | 6.3s |  |
| 744 | `ecma3/Expressions/e11_9_3` | 47 | 6.2s |  |
| 745 | `ecma3/Expressions/e11_9_6_1` | 6 | 6.3s |  |
| 746 | `ecma3/Expressions/instanceof_001` | 14 | 6.2s |  |
| 747 | `ecma3/Expressions/instanceof_002` | 6 | 6.1s |  |
| 748 | `ecma3/Expressions/instanceof_003_rt` | 30 | 6.3s |  |
| 749 | `ecma3/Expressions/instanceof_004_rt` | 1 | 6.2s |  |
| 750 | `ecma3/Expressions/instanceof_006` | 1 | 6.2s |  |
| 751 | `ecma3/Function/apply_001` | 4 | 6.2s |  |
| 752 | `ecma3/Function/call_001_rt` | 1 | 6.2s |  |
| 753 | `ecma3/Function/e15_3_FPQA` | 2 | 6.0s |  |
| 754 | `ecma3/Function/function` | 2 | 6.0s |  |
| 755 | `ecma3/Function/regress_104584` | 3 | 3.1s |  |
| 756 | `ecma3/Function/regress_137181` | 2 | 6.1s |  |
| 757 | `ecma3/Function/regress_49286` | 2 | 6.2s |  |
| 758 | `ecma3/Function/regress_58274_rt` | 7 | 6.2s |  |
| 759 | `ecma3/Function/regress_97921` | 4 | 6.2s |  |
| 760 | `ecma3/Function/scope_001_rt` | 8 | 6.3s |  |
| 761 | `ecma3/Function/scope_002` | 8 | 6.3s |  |
| 762 | `ecma3/FunctionObjects/e15_3_3_1_1` | 1 | 6.1s |  |
| 763 | `ecma3/FunctionObjects/e15_3_3_1_2` | 1 | 6.1s |  |
| 764 | `ecma3/FunctionObjects/e15_3_3_1_4` | 1 | 6.1s |  |
| 765 | `ecma3/FunctionObjects/e15_3_4_1` | 1 | 6.2s |  |
| 766 | `ecma3/FunctionObjects/e15_3_4_2` | 4 | 6.2s |  |
| 767 | `ecma3/FunctionObjects/eapply_001_rt` | 4 | 6.1s |  |
| 768 | `ecma3/GlobalObject/e15_1_1_1` | 3 | 6.0s |  |
| 769 | `ecma3/GlobalObject/e15_1_1_2` | 3 | 5.9s |  |
| 770 | `ecma3/GlobalObject/e15_1_1_n` | 1 | 5.8s |  |
| 771 | `ecma3/GlobalObject/e15_1_2_2_1` | 276 | 8.8s |  |
| 772 | `ecma3/GlobalObject/e15_1_2_3_1` | 186 | 14.0s |  |
| 773 | `ecma3/GlobalObject/e15_1_2_3_2` | 153 | 7.7s |  |
| 774 | `ecma3/GlobalObject/e15_1_2_5_2` | 85 | 6.4s |  |
| 775 | `ecma3/GlobalObject/e15_1_2_5_3` | 514 | 6.5s |  |
| 776 | `ecma3/GlobalObject/e15_1_2_6` | 62 | 8.1s |  |
| 777 | `ecma3/GlobalObject/e15_1_2_7` | 55 | 7.8s |  |
| 778 | `ecma3/GlobalObject/e15_1_2_n` | 1 | 6.3s |  |
| 779 | `ecma3/GlobalObject/undefined` | 3 | 6.2s |  |
| 780 | `ecma3/JSON/Callbacks` | 7 | 6.3s |  |
| 781 | `ecma3/JSON/Invalid` | 40 | 7.7s |  |
| 782 | `ecma3/JSON/LargeString` | 1 | 6.2s |  |
| 783 | `ecma3/JSON/Strings` | 21 | 6.3s |  |
| 784 | `ecma3/Number/e15_7_3_1_2` | 4 | 6.3s |  |
| 785 | `ecma3/Number/e15_7_3_1_3` | 1 | 6.2s |  |
| 786 | `ecma3/Number/e15_7_3_2_1` | 1 | 6.2s |  |
| 787 | `ecma3/Number/e15_7_3_2_4` | 1 | 5.8s |  |
| 788 | `ecma3/Number/e15_7_3_3_1` | 1 | 3.3s |  |
| 789 | `ecma3/Number/e15_7_3_3_4` | 1 | 2.8s |  |
| 790 | `ecma3/Number/e15_7_3_4_1` | 1 | 6.2s |  |
| 791 | `ecma3/Number/e15_7_3_4_4` | 1 | 5.8s |  |
| 792 | `ecma3/Number/e15_7_3_5_1` | 1 | 6.2s |  |
| 793 | `ecma3/Number/e15_7_3_5_4` | 1 | 5.9s |  |
| 794 | `ecma3/Number/e15_7_3_6_1` | 1 | 3.3s |  |
| 795 | `ecma3/Number/e15_7_3_6_4` | 1 | 1.0s |  |
| 796 | `ecma3/Number/e15_7_4_1` | 1 | 6.1s |  |
| 797 | `ecma3/Number/e15_7_4_2_3_rt` | 1 | 6.3s |  |
| 798 | `ecma3/Number/e15_7_4_2_5` | 13 | 6.1s |  |
| 799 | `ecma3/Number/e15_7_4_3_2` | 3 | 6.2s |  |
| 800 | `ecma3/Number/e15_7_4_3_3_rt` | 1 | 6.2s |  |
| 801 | `ecma3/Number/e15_7_4_6_1` | 26 | 7.3s |  |
| 802 | `ecma3/Number/ecma4_sealedtype_1_rt` | 1 | 6.2s |  |
| 803 | `ecma3/Number/ecma4_sealedtype_2_rt` | 1 | 6.2s |  |
| 804 | `ecma3/Number/ecma4_sealedtype_3_rt` | 1 | 6.1s |  |
| 805 | `ecma3/Number/ecma4_sealedtype_4_rt` | 2 | 6.2s |  |
| 806 | `ecma3/Number/ecma4_st_valueOf_1_rt` | 1 | 6.2s |  |
| 807 | `ecma3/Number/ecma4_st_valueOf_2_rt` | 1 | 6.1s |  |
| 808 | `ecma3/Number/ecma4_st_valueOf_3_rt` | 1 | 6.1s |  |
| 809 | `ecma3/Number/toLocaleString2_rt` | 1 | 6.0s |  |
| 810 | `ecma3/Number/toLocaleString3_rt` | 1 | 6.1s |  |
| 811 | `ecma3/Number/toLocaleString4_rt` | 1 | 6.1s |  |
| 812 | `ecma3/ObjectObjects/bug129539` | 3 | 6.1s |  |
| 813 | `ecma3/ObjectObjects/class_001` | 10 | 6.2s |  |
| 814 | `ecma3/ObjectObjects/class_002` | 9 | 6.2s |  |
| 815 | `ecma3/ObjectObjects/class_003` | 7 | 6.2s |  |
| 816 | `ecma3/ObjectObjects/class_004` | 7 | 6.2s |  |
| 817 | `ecma3/ObjectObjects/class_005` | 2 | 6.2s |  |
| 818 | `ecma3/ObjectObjects/e15_2_1_1_rt` | 54 | 9.1s |  |
| 819 | `ecma3/ObjectObjects/e15_2_1_2_rt` | 3 | 6.2s |  |
| 820 | `ecma3/ObjectObjects/e15_2_2_1_rt` | 47 | 6.7s |  |
| 821 | `ecma3/ObjectObjects/e15_2_2_2` | 3 | 6.1s |  |
| 822 | `ecma3/ObjectObjects/e15_2_3_1_1` | 1 | 6.1s |  |
| 823 | `ecma3/ObjectObjects/e15_2_3_1_3` | 1 | 6.2s |  |
| 824 | `ecma3/ObjectObjects/e15_2_3_1_4` | 1 | 6.2s |  |
| 825 | `ecma3/ObjectObjects/e15_2_4_1_rt` | 1 | 6.2s |  |
| 826 | `ecma3/ObjectObjects/e15_2_4_3` | 9 | 6.5s |  |
| 827 | `ecma3/ObjectObjects/e8_6_2_6_001` | 1 | 6.1s |  |
| 828 | `ecma3/ObjectObjects/propertyIsEnumerable` | 5 | 6.1s |  |
| 829 | `ecma3/ObjectObjects/regress_72773_rt` | 1 | 6.3s |  |
| 830 | `ecma3/ObjectObjects/regress_79129_001` | 1 | 6.1s |  |
| 831 | `ecma3/Statements/block` | 4 | 6.3s |  |
| 832 | `ecma3/Statements/e12_10_1` | 8 | 5.9s |  |
| 833 | `ecma3/Statements/e12_2_1` | 18 | 6.3s |  |
| 834 | `ecma3/Statements/e12_5_1` | 6 | 5.8s |  |
| 835 | `ecma3/Statements/e12_5_2` | 6 | 5.8s |  |
| 836 | `ecma3/Statements/e12_5_3` | 12 | 6.0s |  |
| 837 | `ecma3/Statements/e12_6_1_1` | 3 | 5.9s |  |
| 838 | `ecma3/Statements/e12_6_2_1` | 1 | 5.9s |  |
| 839 | `ecma3/Statements/e12_6_2_2` | 1 | 5.7s |  |
| 840 | `ecma3/Statements/e12_6_2_3` | 1 | 5.8s |  |
| 841 | `ecma3/Statements/e12_6_2_4` | 1 | 5.8s |  |
| 842 | `ecma3/Statements/e12_6_2_5` | 1 | 5.8s |  |
| 843 | `ecma3/Statements/e12_6_2_6` | 1 | 5.9s |  |
| 844 | `ecma3/Statements/e12_6_2_7` | 1 | 5.9s |  |
| 845 | `ecma3/Statements/e12_6_2_8` | 1 | 5.9s |  |
| 846 | `ecma3/Statements/e12_6_3_1` | 1 | 5.8s |  |
| 847 | `ecma3/Statements/e12_6_3_10` | 2 | 6.0s |  |
| 848 | `ecma3/Statements/e12_6_3_11` | 1 | 6.0s |  |
| 849 | `ecma3/Statements/e12_6_3_19` | 2 | 6.0s |  |
| 850 | `ecma3/Statements/e12_6_3_2` | 1 | 6.0s |  |
| 851 | `ecma3/Statements/e12_6_3_3` | 1 | 6.1s |  |
| 852 | `ecma3/Statements/e12_6_3_4` | 9 | 6.1s |  |
| 853 | `ecma3/Statements/e12_6_3_9_rt` | 1 | 6.1s |  |
| 854 | `ecma3/Statements/e12_9_1` | 5 | 6.1s |  |
| 855 | `ecma3/Statements/edowhile_001` | 4 | 6.1s |  |
| 856 | `ecma3/Statements/edowhile_002` | 12 | 6.0s |  |
| 857 | `ecma3/Statements/edowhile_003` | 10 | 6.0s |  |
| 858 | `ecma3/Statements/edowhile_004` | 12 | 6.1s |  |
| 859 | `ecma3/Statements/edowhile_005` | 3 | 6.0s |  |
| 860 | `ecma3/Statements/edowhile_006` | 8 | 6.2s |  |
| 861 | `ecma3/Statements/edowhile_007` | 36 | 6.1s |  |
| 862 | `ecma3/Statements/eforin_001_500476` | 2 | 6.0s |  |
| 863 | `ecma3/Statements/eif_001` | 1 | 6.0s |  |
| 864 | `ecma3/Statements/elabel_001` | 5 | 5.9s |  |
| 865 | `ecma3/Statements/elabel_002` | 4 | 6.1s |  |
| 866 | `ecma3/Statements/eregress_131348` | 4 | 6.4s |  |
| 867 | `ecma3/Statements/eregress_74474_001` | 3 | 6.1s |  |
| 868 | `ecma3/Statements/eregress_74474_002` | 1 | 53.4s |  |
| 869 | `ecma3/Statements/eregress_74474_003` | 1 | 55.0s |  |
| 870 | `ecma3/Statements/eregress_83532_001` | 1 | 6.2s |  |
| 871 | `ecma3/Statements/eregress_83532_002` | 1 | 6.1s |  |
| 872 | `ecma3/Statements/eswitch_001` | 5 | 6.2s |  |
| 873 | `ecma3/Statements/eswitch_002` | 10 | 6.1s |  |
| 874 | `ecma3/Statements/eswitch_003` | 9 | 3.2s |  |
| 875 | `ecma3/Statements/eswitch_004` | 18 | 6.2s |  |
| 876 | `ecma3/Statements/etry_001` | 12 | 6.2s |  |
| 877 | `ecma3/Statements/etry_003` | 9 | 6.5s |  |
| 878 | `ecma3/Statements/etry_004` | 3 | 6.2s |  |
| 879 | `ecma3/Statements/etry_005` | 3 | 6.3s |  |
| 880 | `ecma3/Statements/etry_006` | 4 | 6.2s |  |
| 881 | `ecma3/Statements/etry_007` | 2 | 6.2s |  |
| 882 | `ecma3/Statements/etry_008` | 6 | 3.0s |  |
| 883 | `ecma3/Statements/etry_009` | 2 | 5.9s |  |
| 884 | `ecma3/Statements/etry_010` | 4 | 6.0s |  |
| 885 | `ecma3/Statements/etry_012` | 9 | 6.3s |  |
| 886 | `ecma3/Statements/ewhile_001` | 1 | 5.9s |  |
| 887 | `ecma3/Statements/ewhile_002` | 8 | 5.8s |  |
| 888 | `ecma3/Statements/ewhile_003` | 10 | 5.8s |  |
| 889 | `ecma3/Statements/ewhile_004` | 13 | 6.0s |  |
| 890 | `ecma3/Statements/expression` | 1 | 5.8s |  |
| 891 | `ecma3/Statements/throw` | 2 | 6.0s |  |
| 892 | `ecma3/String/Split` | 19 | 6.0s |  |
| 893 | `ecma3/String/concat` | 21 | 6.0s |  |
| 894 | `ecma3/String/e15_5_3_1_1` | 2 | 5.8s |  |
| 895 | `ecma3/String/e15_5_3_1_2` | 1 | 5.9s |  |
| 896 | `ecma3/String/e15_5_3_1_4` | 1 | 5.8s |  |
| 897 | `ecma3/String/e15_5_3_2_1` | 116 | 10.0s |  |
| 898 | `ecma3/String/e15_5_3_2_2` | 2 | 5.8s |  |
| 899 | `ecma3/String/e15_5_4_10_1_rt` | 24 | 6.9s |  |
| 900 | `ecma3/String/e15_5_4_11_1` | 387 | 6.5s |  |
| 901 | `ecma3/String/e15_5_4_11_2` | 96 | 6.3s |  |
| 902 | `ecma3/String/e15_5_4_11_3` | 240 | 6.3s |  |
| 903 | `ecma3/String/e15_5_4_11_4` | 96 | 6.2s |  |
| 904 | `ecma3/String/e15_5_4_11_5` | 131 | 6.3s |  |
| 905 | `ecma3/String/e15_5_4_11_6` | 96 | 6.1s |  |
| 906 | `ecma3/String/e15_5_4_12_1` | 387 | 6.3s |  |
| 907 | `ecma3/String/e15_5_4_12_2` | 1 | 6.4s |  |
| 908 | `ecma3/String/e15_5_4_12_3` | 864 | 6.4s |  |
| 909 | `ecma3/String/e15_5_4_12_4` | 128 | 6.1s |  |
| 910 | `ecma3/String/e15_5_4_12_5` | 96 | 1.7s |  |
| 911 | `ecma3/String/e15_5_4_13` | 17 | 6.1s |  |
| 912 | `ecma3/String/e15_5_4_1_rt` | 2 | 5.8s |  |
| 913 | `ecma3/String/e15_5_4_2_3` | 4 | 5.8s |  |
| 914 | `ecma3/String/e15_5_4_3_2` | 4 | 5.8s |  |
| 915 | `ecma3/String/e15_5_4_3_3_rt` | 1 | 5.9s |  |
| 916 | `ecma3/String/e15_5_4_4_1` | 189 | 5.9s |  |
| 917 | `ecma3/String/e15_5_4_4_2` | 33 | 6.1s |  |
| 918 | `ecma3/String/e15_5_4_4_3` | 18 | 3.1s |  |
| 919 | `ecma3/String/e15_5_4_4_4_rt` | 52 | 9.8s |  |
| 920 | `ecma3/String/e15_5_4_5_1` | 95 | 5.9s |  |
| 921 | `ecma3/String/e15_5_4_5_2` | 31 | 6.3s |  |
| 922 | `ecma3/String/e15_5_4_5_3` | 28 | 6.2s |  |
| 923 | `ecma3/String/e15_5_4_5_5` | 269 | 6.0s |  |
| 924 | `ecma3/String/e15_5_4_5_6_rt` | 11 | 6.6s |  |
| 925 | `ecma3/String/e15_5_4_6_1` | 578 | 6.3s |  |
| 926 | `ecma3/String/e15_5_4_7_1` | 654 | 6.4s |  |
| 927 | `ecma3/String/e15_5_4_7_2` | 72 | 6.4s |  |
| 928 | `ecma3/String/e15_5_4_7_3_rt` | 5 | 6.2s |  |
| 929 | `ecma3/String/e15_5_4_8_1_rt` | 30 | 7.5s |  |
| 930 | `ecma3/String/e15_5_4_8_3` | 13 | 6.0s |  |
| 931 | `ecma3/String/e15_5_4_8_477132` | 1 | 5.8s |  |
| 932 | `ecma3/String/ematch_001` | 24 | 6.0s |  |
| 933 | `ecma3/String/ematch_002` | 32 | 6.1s |  |
| 934 | `ecma3/String/ematch_003` | 10 | 6.0s |  |
| 935 | `ecma3/String/ematch_004` | 8 | 6.0s |  |
| 936 | `ecma3/String/eregress_104375` | 3 | 5.9s |  |
| 937 | `ecma3/String/eregress_137879` | 7 | 5.9s |  |
| 938 | `ecma3/String/eregress_137890` | 1 | 5.9s |  |
| 939 | `ecma3/String/eregress_83293` | 9 | 5.9s |  |
| 940 | `ecma3/String/ereplace_001` | 15 | 6.2s |  |
| 941 | `ecma3/String/esplit_001` | 18 | 6.0s |  |
| 942 | `ecma3/String/esplit_002` | 94 | 6.3s |  |
| 943 | `ecma3/String/esplit_003` | 86 | 6.1s |  |
| 944 | `ecma3/String/replace_439458` | 5 | 6.1s |  |
| 945 | `ecma3/String/search` | 8 | 5.9s |  |
| 946 | `ecma3/String/split_407156` | 1 | 5.8s |  |
| 947 | `ecma3/String/split_504567` | 1 | 5.8s |  |
| 948 | `ecma3/String/substr` | 24 | 6.2s |  |
| 949 | `ecma3/String/toLocaleLowerCase` | 387 | 6.3s |  |
| 950 | `ecma3/String/toLocaleLowerCase2` | 96 | 6.3s |  |
| 951 | `ecma3/String/toLocaleLowerCase3` | 240 | 6.5s |  |
| 952 | `ecma3/String/toLocaleLowerCase4` | 96 | 6.6s |  |
| 953 | `ecma3/String/toLocaleLowerCase5` | 131 | 6.7s |  |
| 954 | `ecma3/String/toLocaleLowerCase6` | 96 | 1.9s |  |
| 955 | `ecma3/String/toLocaleUpperCase` | 96 | 6.6s |  |
| 956 | `ecma3/String/toLocaleUpperCase2` | 128 | 6.6s |  |
| 957 | `ecma3/String/toLocaleUpperCase3` | 768 | 6.7s |  |
| 958 | `ecma3/String/toLocaleUpperCase4` | 1 | 6.5s |  |
| 959 | `ecma3/String/toLocaleUpperCase5` | 387 | 6.4s |  |
| 960 | `ecma3/TypeConversion/e9_2_rt` | 36 | 6.4s |  |
| 961 | `ecma3/TypeConversion/e9_3` | 15 | 6.2s |  |
| 962 | `ecma3/TypeConversion/e9_3_1` | 9 | 6.1s |  |
| 963 | `ecma3/TypeConversion/e9_3_1_1` | 189 | 8.9s |  |
| 964 | `ecma3/TypeConversion/e9_3_1_2` | 12 | 6.0s |  |
| 965 | `ecma3/TypeConversion/e9_5_2` | 56 | 6.5s |  |
| 966 | `ecma3/TypeConversion/e9_6` | 34 | 6.2s |  |
| 967 | `ecma3/TypeConversion/e9_7` | 38 | 6.4s |  |
| 968 | `ecma3/TypeConversion/e9_9_1_rt` | 48 | 5.7s |  |
| 969 | `ecma3/Types/e8_1` | 3 | 5.3s |  |
| 970 | `ecma3/Types/e8_2` | 2 | 5.2s |  |
| 971 | `ecma3/Types/e8_3` | 4 | 5.2s |  |
| 972 | `ecma3/Types/e8_4` | 4 | 5.3s |  |
| 973 | `ecma3/Unicode/u0000_BasicLatin` | 21 | 6.1s |  |
| 974 | `ecma3/Unicode/u0080_Latin_1Supplement` | 21 | 6.1s |  |
| 975 | `ecma3/Unicode/u0100_LatinExtended_A` | 21 | 6.0s |  |
| 976 | `ecma3/Unicode/u0180_LatinExtended_B` | 21 | 6.0s |  |
| 977 | `ecma3/Unicode/u0250_IPAExtensions` | 21 | 2.0s |  |
| 978 | `ecma3/Unicode/u02B0_SpacingModifierLetters` | 21 | 2.0s |  |
| 979 | `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | 21 | 2.0s |  |
| 980 | `ecma3/Unicode/u0370_GreekandCoptic` | 21 | 2.0s |  |
| 981 | `ecma3/Unicode/u0400_Cyrillic` | 42 | 2.0s |  |
| 982 | `ecma3/Unicode/u0500_CyrillicSupplementary` | 21 | 2.0s |  |
| 983 | `ecma3/Unicode/u0530_Armenian` | 21 | 2.0s |  |
| 984 | `ecma3/Unicode/u0590_Hebrew` | 21 | 2.0s |  |
| 985 | `ecma3/Unicode/u0600_Arabic` | 42 | 2.0s |  |
| 986 | `ecma3/Unicode/u0700_Syriac` | 21 | 2.0s |  |
| 987 | `ecma3/Unicode/u0780_Thaana` | 21 | 2.0s |  |
| 988 | `ecma3/Unicode/u0900_Devanagari` | 21 | 2.0s |  |
| 989 | `ecma3/Unicode/u0980_Bengali` | 21 | 2.0s |  |
| 990 | `ecma3/Unicode/u0A00_Gurmukhi` | 21 | 2.0s |  |
| 991 | `ecma3/Unicode/u0A80_Gujarati` | 21 | 2.0s |  |
| 992 | `ecma3/Unicode/u0B00_Oriya` | 21 | 2.0s |  |
| 993 | `ecma3/Unicode/u0B80_Tamil` | 21 | 2.0s |  |
| 994 | `ecma3/Unicode/u0C00_Telugu` | 21 | 2.0s |  |
| 995 | `ecma3/Unicode/u0C80_Kannada` | 21 | 2.0s |  |
| 996 | `ecma3/Unicode/u0D00_Malayalam` | 21 | 2.0s |  |
| 997 | `ecma3/Unicode/u0D80_Sinhala` | 21 | 2.0s |  |
| 998 | `ecma3/Unicode/u0E00_Thai` | 21 | 2.0s |  |
| 999 | `ecma3/Unicode/u0E80_Lao` | 21 | 6.0s |  |
| 1000 | `ecma3/Unicode/u0F00_Tibetan` | 42 | 2.0s |  |
| 1001 | `ecma3/Unicode/u1000_Myanmar` | 21 | 2.0s |  |
| 1002 | `ecma3/Unicode/u10A0_Georgian` | 21 | 2.0s |  |
| 1003 | `ecma3/Unicode/u1100_HangulJamo` | 42 | 2.0s |  |
| 1004 | `ecma3/Unicode/u1200_Ethiopic` | 42 | 2.0s |  |
| 1005 | `ecma3/Unicode/u13A0_Cherokee` | 21 | 2.0s |  |
| 1006 | `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | 63 | 2.0s |  |
| 1007 | `ecma3/Unicode/u1680_Ogham` | 21 | 2.0s |  |
| 1008 | `ecma3/Unicode/u16A0_Runic` | 21 | 2.0s |  |
| 1009 | `ecma3/Unicode/u1700_Tagalog` | 21 | 2.0s |  |
| 1010 | `ecma3/Unicode/u1720_Hanunoo` | 21 | 2.0s |  |
| 1011 | `ecma3/Unicode/u1740_Buhid` | 21 | 2.0s |  |
| 1012 | `ecma3/Unicode/u1760_Tagbanwa` | 21 | 2.0s |  |
| 1013 | `ecma3/Unicode/u1780_Khmer` | 21 | 2.0s |  |
| 1014 | `ecma3/Unicode/u1800_Mongolian` | 21 | 2.0s |  |
| 1015 | `ecma3/Unicode/u1E00_LatinExtendedAdditional` | 42 | 2.0s |  |
| 1016 | `ecma3/Unicode/u1F00_GreekExtended` | 42 | 2.0s |  |
| 1017 | `ecma3/Unicode/u2000_GeneralPunctuation` | 21 | 5.5s |  |
| 1018 | `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | 21 | 5.6s |  |
| 1019 | `ecma3/Unicode/u20A0_CurrencySymbols` | 21 | 5.3s |  |
| 1020 | `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | 21 | 1.7s |  |
| 1021 | `ecma3/Unicode/u2100_LetterlikeSymbols` | 21 | 1.7s |  |
| 1022 | `ecma3/Unicode/u2150_NumberForms` | 21 | 1.7s |  |
| 1023 | `ecma3/Unicode/u2190_Arrows` | 21 | 1.8s |  |
| 1024 | `ecma3/Unicode/u2200_MathematicalOperators` | 42 | 1.8s |  |
| 1025 | `ecma3/Unicode/u2300_MiscellaneousTechnical` | 42 | 5.3s |  |
| 1026 | `ecma3/Unicode/u2400_ControlPictures` | 21 | 1.7s |  |
| 1027 | `ecma3/Unicode/u2440_OpticalCharacterRecognition` | 21 | 1.7s |  |
| 1028 | `ecma3/Unicode/u2460_EnclosedAlphanumerics` | 21 | 1.8s |  |
| 1029 | `ecma3/Unicode/u2500_BoxDrawing` | 21 | 1.8s |  |
| 1030 | `ecma3/Unicode/u2580_BlockElements` | 21 | 1.7s |  |
| 1031 | `ecma3/Unicode/u25A0_GeometricShapes` | 21 | 1.8s |  |
| 1032 | `ecma3/Unicode/u2600_MiscellaneousSymbols` | 42 | 1.8s |  |
| 1033 | `ecma3/Unicode/u2700_Dingbats` | 21 | 1.8s |  |
| 1034 | `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | 21 | 5.2s |  |
| 1035 | `ecma3/Unicode/u27F0_SupplementalArrows_A` | 21 | 1.7s |  |
| 1036 | `ecma3/Unicode/u2800_BraillePatterns` | 42 | 1.8s |  |
| 1037 | `ecma3/Unicode/u2900_SupplementalArrows_B` | 21 | 1.8s |  |
| 1038 | `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | 21 | 1.8s |  |
| 1039 | `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | 42 | 1.8s |  |
| 1040 | `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | 21 | 1.8s |  |
| 1041 | `ecma3/Unicode/u2F00_KangxiRadicals` | 21 | 1.8s |  |
| 1042 | `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | 21 | 1.7s |  |
| 1043 | `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | 21 | 1.9s |  |
| 1044 | `ecma3/Unicode/u3040_Hiragana` | 21 | 1.8s |  |
| 1045 | `ecma3/Unicode/u30A0_Katakana` | 21 | 1.8s |  |
| 1046 | `ecma3/Unicode/u3100_Bopomofo` | 21 | 1.8s |  |
| 1047 | `ecma3/Unicode/u3130_HangulCompatibilityJamo` | 21 | 1.7s |  |
| 1048 | `ecma3/Unicode/u3190_Kanbun` | 21 | 1.7s |  |
| 1049 | `ecma3/Unicode/u31A0_BopomofoExtended` | 21 | 1.7s |  |
| 1050 | `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | 21 | 1.7s |  |
| 1051 | `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | 42 | 1.8s |  |
| 1052 | `ecma3/Unicode/u3300_CJKCompatibility` | 42 | 1.8s |  |
| 1053 | `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | 567 | 3.5s |  |
| 1054 | `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | 63 | 3.1s |  |
| 1055 | `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | 357 | 2.0s |  |
| 1056 | `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | 357 | 2.0s |  |
| 1057 | `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | 357 | 3.2s |  |
| 1058 | `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | 357 | 5.5s |  |
| 1059 | `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | 357 | 2.0s |  |
| 1060 | `ecma3/Unicode/uA000_YiSyllables` | 105 | 1.9s |  |
| 1061 | `ecma3/Unicode/uA490_YiRadicals` | 21 | 5.3s |  |
| 1062 | `ecma3/Unicode/uAC00_HangulSyllables` | 945 | 2.4s |  |
| 1063 | `ecma3/Unicode/uE000_PrivateUseArea` | 546 | 5.6s |  |
| 1064 | `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | 63 | 1.8s |  |
| 1065 | `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | 21 | 1.8s |  |
| 1066 | `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | 63 | 1.9s |  |
| 1067 | `ecma3/Unicode/uFE00_VariationSelectors` | 21 | 1.8s |  |
| 1068 | `ecma3/Unicode/uFE20_CombiningHalfMarks` | 21 | 1.8s |  |
| 1069 | `ecma3/Unicode/uFE30_CJKCompatibilityForms` | 21 | 6.9s |  |
| 1070 | `ecma3/Unicode/uFE50_SmallFormVariants` | 21 | 6.9s |  |
| 1071 | `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | 21 | 6.8s |  |
| 1072 | `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | 21 | 2.3s |  |
| 1073 | `ecma3/Unicode/uFFF0_Specials` | 21 | 6.8s |  |
| 1074 | `ecma3/Unicode/uc_001` | 4 | 6.0s |  |
| 1075 | `ecma3/Unicode/uc_003` | 6 | 6.0s |  |
| 1076 | `ecma3/Unicode/uc_004` | 8 | 6.0s |  |
| 1077 | `ecma3/Unicode/uc_005` | 10 | 6.1s |  |
| 1078 | `ecma3/Unicode/uc_006` | 56 | 6.4s |  |
| 1079 | `ecma3/Unicode/ucs4_bug_515947` | 3 | 6.0s |  |
| 1080 | `ecma3/instanceof/instanceof_001` | 2 | 6.0s |  |
| 1081 | `ecma3/instanceof/instanceof_002` | 5 | 6.0s |  |
| 1082 | `ecma3/instanceof/instanceof_003_rt` | 2 | 6.1s |  |
| 1083 | `ecma3/instanceof/regress_7635_rt` | 3 | 6.1s |  |
| 1084 | `misc/addNull` | 40 | 3.3s |  |
| 1085 | `misc/bug_490371` | 2 | 6.0s |  |
| 1086 | `misc/bug_521353` | 6 | 6.1s |  |
| 1087 | `misc/bug_532806` | 1 | 6.0s |  |
| 1088 | `misc/bug_534074` | 1 | 6.0s |  |
| 1089 | `misc/bug_547583` | 8 | 6.0s |  |
| 1090 | `misc/bug_598322` | 120 | 7.5s |  |
| 1091 | `misc/denseArrayDelete` | 1 | 6.0s |  |
| 1092 | `misc/getlex_anyname` | 1 | 6.0s |  |
| 1093 | `misc/md5_t` | 7 | 6.6s |  |
| 1094 | `misc/nsunbox` | 3 | 6.0s |  |
| 1095 | `misc/superInit` | 1 | 6.0s |  |
| 1096 | `misc/unchecked` | 1 | 6.0s |  |
| 1097 | `recursion/xml_functions` | 3 | 6.3s |  |
| 1098 | `regress/bug_415080` | 1 | 6.0s |  |
| 1099 | `regress/bug_424341` | 1 | 6.0s |  |
| 1100 | `regress/bug_458419` | 1 | 6.0s |  |
| 1101 | `regress/bug_460872` | 1 | 6.0s |  |
| 1102 | `regress/bug_481942` | 1 | 6.0s |  |
| 1103 | `regress/bug_492046` | 1 | 6.0s |  |
| 1104 | `regress/bug_498979` | 1 | 6.0s |  |
| 1105 | `regress/bug_521353` | 49 | 3.1s |  |
| 1106 | `regress/bug_526295` | 2 | 6.1s |  |
| 1107 | `regress/bug_532791` | 1 | 6.0s |  |
| 1108 | `regress/bug_535882` | 1 | 6.0s |  |
| 1109 | `regress/bug_547295` | 2 | 6.0s |  |
| 1110 | `regress/bug_549389` | 1 | 5.9s |  |
| 1111 | `regress/bug_551587` | 6 | 6.0s |  |
| 1112 | `regress/bug_555544` | 1 | 6.0s |  |
| 1113 | `regress/bug_555705_orig` | 2 | 5.7s |  |
| 1114 | `regress/bug_559565` | 1 | 6.0s |  |
| 1115 | `regress/bug_561191` | 19 | 6.0s |  |
| 1116 | `regress/bug_564839` | 21 | 6.3s |  |
| 1117 | `regress/bug_588041` | 1 | 6.0s |  |
| 1118 | `regress/bug_593383` | 109 | 7.5s |  |
| 1119 | `regress/bug_598683` | 2 | 6.0s |  |
| 1120 | `regress/bug_599357` | 53 | 7.4s |  |
| 1121 | `regress/bug_615544` | 2 | 6.0s |  |
| 1122 | `regress/bug_637809` | 3 | 6.0s |  |
| 1123 | `regress/bug_642535` | 8 | 6.1s |  |
| 1124 | `regress/bug_643009` | 6 | 6.0s |  |
| 1125 | `regress/bug_654761` | 2 | 6.0s |  |
| 1126 | `regress/bug_655315` | 2 | 6.0s |  |
| 1127 | `regress/bug_663469` | 51 | 6.0s |  |
| 1128 | `regress/bug_672012` | 1 | 6.0s |  |
| 1129 | `regress/bug_673284` | 1 | 6.2s |  |
| 1130 | `regress/bug_700613` | 5 | 6.0s |  |
| 1131 | `regress/bug_703238` | 27 | 5.9s |  |
| 1132 | `regress/bug_707133` | 2 | 6.0s |  |
| 1133 | `regress/bug_723461` | 6 | 6.0s |  |
| 1134 | `regress/security/bug_550269` | 2 | 6.0s |  |
| 1135 | `regress/security/bug_663469` | 5 | 6.0s |  |

## Ruffle-Matched Tests

**32 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `as3/Expressions/asOperator/asOper` | 2 | 2 | 7.0s |  |
| 2 | `as3/Math/e15_1_2_2` | 1 | 1 | 3.1s |  |
| 3 | `as3/RegExp/replace` | 2 | 3 | 6.0s |  |
| 4 | `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | 1 | 1 | 5.9s |  |
| 5 | `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | 1 | 1 | 6.0s |  |
| 6 | `as3/Types/Number/e15_7_4_6_1/swf14` | 18 | 18 | 7.7s |  |
| 7 | `as3/Types/Number/e15_7_4_6_1/swf15` | 3 | 3 | 7.7s |  |
| 8 | `e4x/XML/bug_564468` | 7 | 7 | 6.2s |  |
| 9 | `e4x/XML/e13_4_4_30` | 3 | 3 | 5.9s |  |
| 10 | `e4x/XML/misc_errors` | 2 | 2 | 5.1s |  |
| 11 | `e4x/XML/setNotification` | 13 | 13 | 2.6s |  |
| 12 | `e4x/XMLList/e13_5_4_18` | 2 | 2 | 4.7s |  |
| 13 | `ecma3/Array/e15_4_4_5` | 1 | 1 | 6.0s |  |
| 14 | `ecma3/Array/toLocaleString` | 1 | 1 | 6.0s |  |
| 15 | `ecma3/Date/e15_9_5_10_1` | 33 | 33 | 7.0s |  |
| 16 | `ecma3/Date/e15_9_5_12_1` | 67 | 67 | 7.1s |  |
| 17 | `ecma3/JSON/Classes` | 1 | 3 | 6.5s |  |
| 18 | `ecma3/Number/e15_7_1` | 1 | 1 | 6.6s |  |
| 19 | `ecma3/Number/e15_7_2` | 1 | 1 | 7.1s |  |
| 20 | `ecma3/Number/e15_7_4_7_1` | 3 | 10 | 6.6s |  |
| 21 | `ecma3/Number/eregress_121952` | 1 | 1 | 6.3s |  |
| 22 | `ecma3/Number/toStringLimits` | 1 | 1 | 6.1s |  |
| 23 | `ecma3/Number/tostring_001` | 2 | 2 | 6.1s |  |
| 24 | `ecma3/String/e15_5_1` | 1 | 1 | 6.2s |  |
| 25 | `ecma3/String/e15_5_2` | 1 | 1 | 6.6s |  |
| 26 | `ecma3/TypeConversion/e9_8_1` | 1 | 1 | 5.5s |  |
| 27 | `ecma3/Types/e8_5` | 3 | 3 | 5.4s |  |
| 28 | `regress/bug_478501` | 1 | 1 | 6.0s |  |
| 29 | `regress/bug_479786` | 1 | 1 | 6.0s |  |
| 30 | `regress/bug_558863_swf10` | 1 | 1 | 6.1s |  |
| 31 | `regress/bug_609416_swf10` | 1 | 1 | 6.1s |  |
| 32 | `regress/bug_638233` | 2 | 2 | 6.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**99 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `ecma3/Array/e15_4_2_1_3` | 99.9% | 1030 | 1031 | 1 |  |
| 2 | `ecma3/GlobalObject/e15_1_2_5_1` | 99.8% | 530 | 531 | 1 |  |
| 3 | `as3/ByteArray/ByteArray` | 99.8% | 424 | 425 | 1 |  |
| 4 | `as3/Array/insertremove` | 99.7% | 30766 | 30870 | 104 |  |
| 5 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321 | 323 | 2 |  |
| 6 | `as3/Vector/vectorIndexRangeExceptions` | 99.2% | 1260 | 1270 | 10 |  |
| 7 | `ecma3/String/e15_5_4_6_2_rt` | 98.7% | 229 | 232 | 3 |  |
| 8 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474 | 481 | 7 |  |
| 9 | `e4x/QName/e13_3_2` | 98.0% | 48 | 49 | 1 |  |
| 10 | `as3/Vector/initializer_expressions` | 97.6% | 40 | 41 | 1 |  |
| 11 | `ecma3/JSON/e15_12_1` | 97.2% | 35 | 36 | 1 |  |
| 12 | `ecma3/Number/e15_7_4_2_4` | 96.1% | 49 | 51 | 2 |  |
| 13 | `ecma3/String/e15_5_4_9_1_rt` | 95.5% | 21 | 22 | 1 |  |
| 14 | `e4x/XML/e13_4_4_17` | 94.7% | 18 | 19 | 1 |  |
| 15 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89 | 94 | 5 |  |
| 16 | `e4x/Namespace/e13_2_5` | 94.4% | 34 | 36 | 2 |  |
| 17 | `ecma3/Expressions/e11_4_1` | 94.4% | 17 | 18 | 1 |  |
| 18 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16 | 17 | 1 |  |
| 19 | `ecma3/JSON/e15_12_3` | 93.9% | 31 | 33 | 2 |  |
| 20 | `regress/bug_687838` | 93.7% | 104 | 111 | 7 |  |
| 21 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13 | 14 | 1 |  |
| 22 | `as3/Vector/some` | 92.3% | 12 | 13 | 1 |  |
| 23 | `e4x/XML/e13_4_4_28` | 92.3% | 12 | 13 | 1 |  |
| 24 | `as3/Vector/map` | 91.7% | 11 | 12 | 1 |  |
| 25 | `ecma3/JSON/e15_12_2` | 91.7% | 11 | 12 | 1 |  |
| 26 | `as3/ShellClasses/DictionarySubclass` | 90.9% | 20 | 22 | 2 |  |
| 27 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28 | 31 | 3 |  |
| 28 | `e4x/XMLList/e13_5_4_17` | 90.0% | 9 | 10 | 1 |  |
| 29 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9 | 10 | 1 |  |
| 30 | `ecma3/ObjectObjects/e15_2_4_2` | 90.0% | 9 | 10 | 1 |  |
| 31 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54 | 60 | 6 |  |
| 32 | `e4x/Expressions/e11_1_1` | 89.7% | 35 | 39 | 4 |  |
| 33 | `ecma3/TypeConversion/e9_4_1` | 89.5% | 17 | 19 | 2 |  |
| 34 | `ecma3/TypeConversion/e9_4_2` | 89.5% | 17 | 19 | 2 |  |
| 35 | `ecma3/Expressions/e11_1_4` | 89.3% | 25 | 28 | 3 |  |
| 36 | `as3/Vector/filter` | 88.9% | 8 | 9 | 1 |  |
| 37 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8 | 9 | 1 |  |
| 38 | `ecma3/JSON/AS3Types` | 88.5% | 23 | 26 | 3 |  |
| 39 | `as3/Vector/nested` | 87.5% | 7 | 8 | 1 |  |
| 40 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 85.7% | 6 | 7 | 1 |  |
| 41 | `as3/Vector/map_initializers` | 85.7% | 6 | 7 | 1 |  |
| 42 | `ecma3/Types/e8_6_1` | 85.7% | 6 | 7 | 1 |  |
| 43 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 83.3% | 5 | 6 | 1 |  |
| 44 | `as3/Vector/foreach` | 83.3% | 5 | 6 | 1 |  |
| 45 | `as3/Vector/some_initializers` | 83.3% | 5 | 6 | 1 |  |
| 46 | `e4x/XML/e13_4_4_36` | 81.2% | 13 | 16 | 3 |  |
| 47 | `as3/Vector/filter_initializers` | 80.0% | 4 | 5 | 1 |  |
| 48 | `as3/Vector/foreach_initializers` | 80.0% | 4 | 5 | 1 |  |
| 49 | `ecma3/Array/e15_4_2_3` | 80.0% | 4 | 5 | 1 |  |
| 50 | `ecma3/ObjectObjects/hasOwnProperty` | 80.0% | 8 | 10 | 2 |  |
| 51 | `ecma3/ObjectObjects/toLocaleString_rt` | 80.0% | 4 | 5 | 1 |  |
| 52 | `ecma3/Array/e15_4_1` | 78.6% | 11 | 14 | 3 |  |
| 53 | `ecma3/Array/e15_4_3_1_2` | 75.0% | 3 | 4 | 1 |  |
| 54 | `ecma3/Boolean/e15_6_4__1` | 75.0% | 3 | 4 | 1 |  |
| 55 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 75.0% | 3 | 4 | 1 |  |
| 56 | `ecma3/FunctionObjects/e15_3_4_rt` | 75.0% | 3 | 4 | 1 |  |
| 57 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 75.0% | 3 | 4 | 1 |  |
| 58 | `ecma3/JSON/adhoc` | 75.0% | 30 | 40 | 10 |  |
| 59 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6 | 8 | 2 |  |
| 60 | `ecma3/Statements/eforin_001` | 75.0% | 12 | 16 | 4 |  |
| 61 | `ecma3/Expressions/e11_2_1_1` | 72.0% | 183 | 254 | 71 |  |
| 62 | `ecma3/String/e15_5_5_1` | 70.0% | 7 | 10 | 3 |  |
| 63 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2 | 3 | 1 |  |
| 64 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 66.7% | 4 | 6 | 2 |  |
| 65 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 66.7% | 2 | 3 | 1 |  |
| 66 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 66.7% | 2 | 3 | 1 |  |
| 67 | `ecma3/Number/e15_7_4_rt` | 66.7% | 2 | 3 | 1 |  |
| 68 | `ecma3/Unicode/utf8count` | 66.7% | 2 | 3 | 1 |  |
| 69 | `regress/bug_550958` | 66.7% | 2 | 3 | 1 |  |
| 70 | `e4x/Statements/e12_1` | 64.7% | 11 | 17 | 6 |  |
| 71 | `regress/bug_420755` | 63.0% | 17 | 27 | 10 |  |
| 72 | `regress/bug_654807_swf13` | 60.0% | 102 | 170 | 68 |  |
| 73 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 58.3% | 21 | 36 | 15 |  |
| 74 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 53.8% | 7 | 13 | 6 |  |
| 75 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 76 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 53.1% | 17 | 32 | 15 |  |
| 77 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 78 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 79 | `as3/Definitions/Classes/ClassDef/InternalClass` | 53.1% | 17 | 32 | 15 |  |
| 80 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 81 | `as3/Types/Int/intMaxValue` | 50.0% | 2 | 4 | 2 |  |
| 82 | `as3/Types/Int/intMinValue` | 50.0% | 2 | 4 | 2 |  |
| 83 | `as3/Vector/bug_678952` | 50.0% | 1 | 2 | 1 |  |
| 84 | `e4x/Expressions/e11_1_2` | 50.0% | 12 | 24 | 12 |  |
| 85 | `ecma3/Array/e15_4_4_5_3` | 50.0% | 28 | 56 | 28 |  |
| 86 | `ecma3/Boolean/e15_6_3` | 50.0% | 1 | 2 | 1 |  |
| 87 | `ecma3/Boolean/e15_6_4` | 50.0% | 1 | 2 | 1 |  |
| 88 | `ecma3/FunctionObjects/e15_3_3_1_3` | 50.0% | 1 | 2 | 1 |  |
| 89 | `ecma3/JSON/e15_12_0` | 50.0% | 2 | 4 | 2 |  |
| 90 | `ecma3/JSON/regress` | 50.0% | 3 | 6 | 3 |  |
| 91 | `ecma3/Number/e15_7_3` | 50.0% | 1 | 2 | 1 |  |
| 92 | `ecma3/Number/e15_7_3_1_1` | 50.0% | 1 | 2 | 1 |  |
| 93 | `ecma3/Number/e15_7_3_3_3` | 50.0% | 1 | 2 | 1 |  |
| 94 | `ecma3/Number/e15_7_3_4_3` | 50.0% | 1 | 2 | 1 |  |
| 95 | `ecma3/String/e15_5_3` | 50.0% | 1 | 2 | 1 |  |
| 96 | `recursion/pcre_find_firstassertedchar` | 50.0% | 1 | 2 | 1 |  |
| 97 | `recursion/pcre_find_fixedlength` | 50.0% | 10 | 20 | 10 |  |
| 98 | `recursion/pcre_is_anchored` | 50.0% | 1 | 2 | 1 |  |
| 99 | `recursion/pcre_is_startline` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

**14 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as3/AMF/AMFSerializer` | 17.1s |  |
| 2 | `ecma3/Exceptions/bug127913` | 16.2s |  |
| 3 | `ecma3/Exceptions/number_001_rt` | 15.8s |  |
| 4 | `ecma3/Exceptions/string_001_rt` | 15.8s |  |
| 5 | `ecma3/Number/e15_7_4_2_1_rt` | 16.0s |  |
| 6 | `ecma3/Number/e15_7_4_2_2_rt` | 15.5s |  |
| 7 | `ecma3/Number/e15_7_4_3_1_rt` | 15.8s |  |
| 8 | `ecma3/Number/e15_7_4__1_rt` | 15.4s |  |
| 9 | `ecma3/Number/toLocaleString_rt` | 17.1s |  |
| 10 | `ecma3/String/e15_5_4` | 16.2s |  |
| 11 | `ecma3/String/e15_5_4_2_1` | 16.1s |  |
| 12 | `ecma3/String/e15_5_4_2_rt` | 16.1s |  |
| 13 | `ecma3/String/e15_5_4_3_1` | 16.4s |  |
| 14 | `ecma3/String/localeCompare_rt` | 16.1s |  |

## Runtime Errors

**16 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/Definitions/Super/SuperInForLoop` | exit code 1 | 5.4s |  |
| 2 | `as3/Definitions/Super/SuperProps` | exit code 1 | 5.6s |  |
| 3 | `misc/bug_508617` | exit code 1 | 6.0s |  |
| 4 | `mops/lf32` | exit code 1 | 25.0s |  |
| 5 | `mops/lf64` | exit code 1 | 6.2s |  |
| 6 | `mops/li16` | exit code 1 | 6.1s |  |
| 7 | `mops/li32` | exit code 1 | 6.1s |  |
| 8 | `mops/li8` | exit code 1 | 6.1s |  |
| 9 | `mops/lix16` | exit code 1 | 6.0s |  |
| 10 | `mops/lix8` | exit code 1 | 6.0s |  |
| 11 | `mops/sf32` | exit code 1 | 6.1s |  |
| 12 | `mops/sf64` | exit code 1 | 6.3s |  |
| 13 | `mops/si16` | exit code 1 | 6.2s |  |
| 14 | `mops/si32` | exit code 1 | 6.2s |  |
| 15 | `mops/si8` | exit code 1 | 6.2s |  |
| 16 | `regress/bug_483783` | exit code 1 | 6.1s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/ByteArray/ByteArray_bug662851_32bit` | runtime timeout (>10s) | 34.9s |  |
| 2 | `as3/ByteArray/ByteArray_bug662851_64bit` | runtime timeout (>10s) | 35.0s |  |
| 3 | `mops/mops_basics` | runtime timeout (>10s) | 37.5s |  |

## All Output Mismatches

**373 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `ecma3/Array/e15_4_2_1_3` | 99.9% | 1030/1031 | 1030 | 1031 |  |
| 2 | `ecma3/GlobalObject/e15_1_2_5_1` | 99.8% | 530/531 | 531 | 531 |  |
| 3 | `as3/ByteArray/ByteArray` | 99.8% | 424/425 | 425 | 425 |  |
| 4 | `as3/Array/insertremove` | 99.7% | 30766/30870 | 30870 | 30870 |  |
| 5 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321/323 | 323 | 323 |  |
| 6 | `as3/Vector/vectorIndexRangeExceptions` | 99.2% | 1260/1270 | 1270 | 1270 |  |
| 7 | `ecma3/String/e15_5_4_6_2_rt` | 98.7% | 229/232 | 231 | 232 |  |
| 8 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474/481 | 481 | 481 |  |
| 9 | `e4x/QName/e13_3_2` | 98.0% | 48/49 | 49 | 49 |  |
| 10 | `as3/Vector/initializer_expressions` | 97.6% | 40/41 | 41 | 41 |  |
| 11 | `ecma3/JSON/e15_12_1` | 97.2% | 35/36 | 36 | 36 |  |
| 12 | `ecma3/Number/e15_7_4_2_4` | 96.1% | 49/51 | 51 | 51 |  |
| 13 | `ecma3/String/e15_5_4_9_1_rt` | 95.5% | 21/22 | 22 | 22 |  |
| 14 | `e4x/XML/e13_4_4_17` | 94.7% | 18/19 | 19 | 19 |  |
| 15 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89/94 | 94 | 94 |  |
| 16 | `e4x/Namespace/e13_2_5` | 94.4% | 34/36 | 36 | 36 |  |
| 17 | `ecma3/Expressions/e11_4_1` | 94.4% | 17/18 | 18 | 18 |  |
| 18 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16/17 | 17 | 17 |  |
| 19 | `ecma3/JSON/e15_12_3` | 93.9% | 31/33 | 33 | 33 |  |
| 20 | `regress/bug_687838` | 93.7% | 104/111 | 111 | 111 |  |
| 21 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13/14 | 14 | 14 |  |
| 22 | `as3/Vector/some` | 92.3% | 12/13 | 13 | 13 |  |
| 23 | `e4x/XML/e13_4_4_28` | 92.3% | 12/13 | 13 | 13 |  |
| 24 | `as3/Vector/map` | 91.7% | 11/12 | 12 | 12 |  |
| 25 | `ecma3/JSON/e15_12_2` | 91.7% | 11/12 | 12 | 12 |  |
| 26 | `as3/ShellClasses/DictionarySubclass` | 90.9% | 20/22 | 22 | 22 |  |
| 27 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28/31 | 31 | 31 |  |
| 28 | `e4x/XMLList/e13_5_4_17` | 90.0% | 9/10 | 10 | 10 |  |
| 29 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9/10 | 10 | 10 |  |
| 30 | `ecma3/ObjectObjects/e15_2_4_2` | 90.0% | 9/10 | 10 | 10 |  |
| 31 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54/60 | 60 | 60 |  |
| 32 | `e4x/Expressions/e11_1_1` | 89.7% | 35/39 | 39 | 39 |  |
| 33 | `ecma3/TypeConversion/e9_4_1` | 89.5% | 17/19 | 19 | 19 |  |
| 34 | `ecma3/TypeConversion/e9_4_2` | 89.5% | 17/19 | 19 | 19 |  |
| 35 | `ecma3/Expressions/e11_1_4` | 89.3% | 25/28 | 28 | 28 |  |
| 36 | `as3/Vector/filter` | 88.9% | 8/9 | 9 | 9 |  |
| 37 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8/9 | 9 | 9 |  |
| 38 | `ecma3/JSON/AS3Types` | 88.5% | 23/26 | 24 | 26 |  |
| 39 | `as3/Vector/nested` | 87.5% | 7/8 | 8 | 8 |  |
| 40 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 85.7% | 6/7 | 7 | 7 |  |
| 41 | `as3/Vector/map_initializers` | 85.7% | 6/7 | 7 | 7 |  |
| 42 | `ecma3/Types/e8_6_1` | 85.7% | 6/7 | 7 | 7 |  |
| 43 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 83.3% | 5/6 | 5 | 6 |  |
| 44 | `as3/Vector/foreach` | 83.3% | 5/6 | 6 | 6 |  |
| 45 | `as3/Vector/some_initializers` | 83.3% | 5/6 | 6 | 6 |  |
| 46 | `e4x/XML/e13_4_4_36` | 81.2% | 13/16 | 16 | 16 |  |
| 47 | `as3/Vector/filter_initializers` | 80.0% | 4/5 | 5 | 5 |  |
| 48 | `as3/Vector/foreach_initializers` | 80.0% | 4/5 | 5 | 5 |  |
| 49 | `ecma3/Array/e15_4_2_3` | 80.0% | 4/5 | 5 | 5 |  |
| 50 | `ecma3/ObjectObjects/hasOwnProperty` | 80.0% | 8/10 | 10 | 10 |  |
| 51 | `ecma3/ObjectObjects/toLocaleString_rt` | 80.0% | 4/5 | 5 | 5 |  |
| 52 | `ecma3/Array/e15_4_1` | 78.6% | 11/14 | 14 | 14 |  |
| 53 | `ecma3/Array/e15_4_3_1_2` | 75.0% | 3/4 | 4 | 4 |  |
| 54 | `ecma3/Boolean/e15_6_4__1` | 75.0% | 3/4 | 4 | 4 |  |
| 55 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 56 | `ecma3/FunctionObjects/e15_3_4_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 57 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 58 | `ecma3/JSON/adhoc` | 75.0% | 30/40 | 40 | 40 |  |
| 59 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6/8 | 8 | 8 |  |
| 60 | `ecma3/Statements/eforin_001` | 75.0% | 12/16 | 16 | 16 |  |
| 61 | `ecma3/Expressions/e11_2_1_1` | 72.0% | 183/254 | 254 | 254 |  |
| 62 | `ecma3/String/e15_5_5_1` | 70.0% | 7/10 | 10 | 10 |  |
| 63 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2/3 | 3 | 3 |  |
| 64 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 66.7% | 4/6 | 6 | 6 |  |
| 65 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 66 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 67 | `ecma3/Number/e15_7_4_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 68 | `ecma3/Unicode/utf8count` | 66.7% | 2/3 | 3 | 3 |  |
| 69 | `regress/bug_550958` | 66.7% | 2/3 | 2 | 3 |  |
| 70 | `e4x/Statements/e12_1` | 64.7% | 11/17 | 17 | 17 |  |
| 71 | `regress/bug_420755` | 63.0% | 17/27 | 27 | 27 |  |
| 72 | `regress/bug_654807_swf13` | 60.0% | 102/170 | 170 | 170 |  |
| 73 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 58.3% | 21/36 | 21 | 36 |  |
| 74 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 53.8% | 7/13 | 13 | 13 |  |
| 75 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 76 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 53.1% | 17/32 | 17 | 32 |  |
| 77 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 78 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 79 | `as3/Definitions/Classes/ClassDef/InternalClass` | 53.1% | 17/32 | 17 | 32 |  |
| 80 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 81 | `as3/Types/Int/intMaxValue` | 50.0% | 2/4 | 4 | 4 |  |
| 82 | `as3/Types/Int/intMinValue` | 50.0% | 2/4 | 4 | 4 |  |
| 83 | `as3/Vector/bug_678952` | 50.0% | 1/2 | 2 | 2 |  |
| 84 | `e4x/Expressions/e11_1_2` | 50.0% | 12/24 | 24 | 20 |  |
| 85 | `ecma3/Array/e15_4_4_5_3` | 50.0% | 28/56 | 56 | 56 |  |
| 86 | `ecma3/Boolean/e15_6_3` | 50.0% | 1/2 | 2 | 2 |  |
| 87 | `ecma3/Boolean/e15_6_4` | 50.0% | 1/2 | 2 | 2 |  |
| 88 | `ecma3/FunctionObjects/e15_3_3_1_3` | 50.0% | 1/2 | 2 | 2 |  |
| 89 | `ecma3/JSON/e15_12_0` | 50.0% | 2/4 | 4 | 4 |  |
| 90 | `ecma3/JSON/regress` | 50.0% | 3/6 | 6 | 5 |  |
| 91 | `ecma3/Number/e15_7_3` | 50.0% | 1/2 | 2 | 2 |  |
| 92 | `ecma3/Number/e15_7_3_1_1` | 50.0% | 1/2 | 2 | 2 |  |
| 93 | `ecma3/Number/e15_7_3_3_3` | 50.0% | 1/2 | 2 | 2 |  |
| 94 | `ecma3/Number/e15_7_3_4_3` | 50.0% | 1/2 | 2 | 2 |  |
| 95 | `ecma3/String/e15_5_3` | 50.0% | 1/2 | 2 | 2 |  |
| 96 | `recursion/pcre_find_firstassertedchar` | 50.0% | 1/2 | 2 | 2 |  |
| 97 | `recursion/pcre_find_fixedlength` | 50.0% | 10/20 | 20 | 20 |  |
| 98 | `recursion/pcre_is_anchored` | 50.0% | 1/2 | 2 | 2 |  |
| 99 | `recursion/pcre_is_startline` | 50.0% | 1/2 | 2 | 2 |  |
| 100 | `as3/Definitions/Classes/ClassDef/PublicClass` | 47.7% | 21/44 | 21 | 44 |  |
| 101 | `as3/Definitions/Classes/ClassDef/PublicDynamicClass` | 47.7% | 21/44 | 21 | 44 |  |
| 102 | `regress/bug_539328` | 46.7% | 7/15 | 8 | 15 |  |
| 103 | `as3/Definitions/Classes/ClassDef/FinalPublicClass` | 42.5% | 17/40 | 17 | 40 |  |
| 104 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass` | 42.5% | 17/40 | 17 | 40 |  |
| 105 | `e4x/Expressions/e11_1_4` | 37.8% | 14/37 | 37 | 34 |  |
| 106 | `as3/Expressions/QualifiedReferences/WildcardOperator` | 33.3% | 1/3 | 3 | 3 |  |
| 107 | `ecma3/Exceptions/exception_011_rt` | 33.3% | 1/3 | 1 | 3 |  |
| 108 | `ecma3/Expressions/e11_6_1_3` | 33.3% | 3/9 | 9 | 9 |  |
| 109 | `ecma3/FunctionObjects/ecall_1` | 33.3% | 1/3 | 3 | 3 |  |
| 110 | `ecma3/NativeObjects/e15_2_rt` | 33.3% | 3/9 | 9 | 9 |  |
| 111 | `regress/bug_654807_swf12` | 31.8% | 54/170 | 170 | 170 |  |
| 112 | `e4x/Expressions/e11_3_1` | 28.6% | 10/35 | 35 | 20 |  |
| 113 | `ecma3/Array/e15_4_1_1` | 28.6% | 2/7 | 2 | 7 |  |
| 114 | `e4x/XML/e13_4_4_2` | 26.7% | 4/15 | 14 | 15 |  |
| 115 | `as3/String/localeCompare_585791/v9` | 25.0% | 2/8 | 8 | 8 |  |
| 116 | `as3/Types/Number/e` | 25.0% | 2/8 | 8 | 8 |  |
| 117 | `as3/Types/Number/ln10` | 25.0% | 2/8 | 8 | 8 |  |
| 118 | `as3/Types/Number/ln2` | 25.0% | 2/8 | 8 | 8 |  |
| 119 | `as3/Types/Number/pi` | 25.0% | 2/8 | 8 | 8 |  |
| 120 | `as3/Types/Number/sqrt2` | 25.0% | 2/8 | 8 | 8 |  |
| 121 | `ecma3/Array/e15_4_4` | 25.0% | 1/4 | 4 | 4 |  |
| 122 | `as3/Types/Number/log10e` | 22.2% | 2/9 | 9 | 9 |  |
| 123 | `as3/Types/Number/log2e` | 22.2% | 2/9 | 9 | 9 |  |
| 124 | `as3/Types/Number/sqrt1_2` | 22.2% | 2/9 | 9 | 9 |  |
| 125 | `as3/Array/bug_535446` | 20.0% | 2/10 | 10 | 10 |  |
| 126 | `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp` | 18.8% | 3/16 | 3 | 16 |  |
| 127 | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 16.7% | 1/6 | 6 | 6 |  |
| 128 | `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp` | 13.6% | 3/22 | 3 | 22 |  |
| 129 | `e4x/Regress/regress-524214` | 9.1% | 1/11 | 11 | 3 |  |
| 130 | `ecma3/GlobalObject/e15_1_2_4` | 5.1% | 50/983 | 983 | 983 |  |
| 131 | `as3/ByteArray/ByteArrayLzma` | 1.8% | 7/397 | 12 | 397 |  |
| 132 | `as3/Array/length_mods` | 0.0% | 0/20 | 9 | 20 |  |
| 133 | `as3/ByteArray/ByteArrayLzmaThirdParty` | 0.0% | 0/2 | 0 | 2 |  |
| 134 | `as3/Definitions/Classes/ClassDef/Bug118272Package` | 0.0% | 0/6 | 6 | 6 |  |
| 135 | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 136 | `as3/Expressions/deleteOperator/deleteFixedFunction` | 0.0% | 0/1 | 1 | 1 |  |
| 137 | `as3/Expressions/deleteOperator/deleteFixedVar` | 0.0% | 0/1 | 1 | 1 |  |
| 138 | `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | 0.0% | 0/1 | 1 | 1 |  |
| 139 | `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | 0.0% | 0/1 | 1 | 1 |  |
| 140 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | 0.0% | 0/2 | 1 | 2 |  |
| 141 | `as3/RuntimeErrors/Error1052InvalidUriPassed` | 0.0% | 0/1 | 1 | 1 |  |
| 142 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 143 | `as3/RuntimeErrors/Error1066Function-body-NotAllowed` | 0.0% | 0/1 | 1 | 1 |  |
| 144 | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | 0.0% | 0/1 | 0 | 1 |  |
| 145 | `as3/RuntimeErrors/Error1075MathNotAFunction` | 0.0% | 0/1 | 1 | 1 |  |
| 146 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 147 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 0.0% | 0/1 | 1 | 1 |  |
| 148 | `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | 0.0% | 0/2 | 2 | 2 |  |
| 149 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | 0.0% | 0/3 | 0 | 3 |  |
| 150 | `as3/RuntimeErrors/Error1117InvalidXmlName` | 0.0% | 0/2 | 1 | 2 |  |
| 151 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | 0.0% | 0/2 | 1 | 2 |  |
| 152 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | 0.0% | 0/1 | 1 | 1 |  |
| 153 | `as3/Statements/Exceptions/MultipleCatchBlocksURI` | 0.0% | 0/1 | 1 | 1 |  |
| 154 | `as3/Types/Number/abs` | 0.0% | 0/41 | 0 | 41 |  |
| 155 | `as3/Types/Number/acos` | 0.0% | 0/29 | 0 | 29 |  |
| 156 | `as3/Types/Number/asin` | 0.0% | 0/34 | 0 | 34 |  |
| 157 | `as3/Types/Number/atan` | 0.0% | 0/33 | 0 | 33 |  |
| 158 | `as3/Types/Number/atan2` | 0.0% | 0/72 | 0 | 72 |  |
| 159 | `as3/Types/Number/ceil` | 0.0% | 0/49 | 0 | 49 |  |
| 160 | `as3/Types/Number/cos` | 0.0% | 0/29 | 0 | 29 |  |
| 161 | `as3/Types/Number/exp` | 0.0% | 0/30 | 0 | 30 |  |
| 162 | `as3/Types/Number/floor` | 0.0% | 0/46 | 0 | 46 |  |
| 163 | `as3/Types/Number/log` | 0.0% | 0/32 | 0 | 32 |  |
| 164 | `as3/Types/Number/max` | 0.0% | 0/54 | 0 | 54 |  |
| 165 | `as3/Types/Number/min` | 0.0% | 0/54 | 0 | 54 |  |
| 166 | `as3/Types/Number/pow` | 0.0% | 0/96 | 0 | 96 |  |
| 167 | `as3/Types/Number/random` | 0.0% | 0/4 | 0 | 4 |  |
| 168 | `as3/Types/Number/round` | 0.0% | 0/54 | 0 | 54 |  |
| 169 | `as3/Types/Number/sin` | 0.0% | 0/28 | 0 | 28 |  |
| 170 | `as3/Types/Number/sqrt` | 0.0% | 0/69 | 0 | 69 |  |
| 171 | `as3/Types/Number/tan` | 0.0% | 0/28 | 0 | 28 |  |
| 172 | `as3/Types/Number/visibility/v16` | 0.0% | 0/9 | 0 | 9 |  |
| 173 | `as3/Vector/nonindexproperty/v10` | 0.0% | 0/51 | 0 | 51 |  |
| 174 | `as3/Vector/nonindexproperty/v11` | 0.0% | 0/55 | 0 | 55 |  |
| 175 | `e4x/Global/e13_1_2_1` | 0.0% | 0/10 | 0 | 10 |  |
| 176 | `e4x/Global/isXMLNameTypeErr` | 0.0% | 0/5 | 3 | 5 |  |
| 177 | `e4x/Regress/regress-263935` | 0.0% | 0/3 | 3 | 2 |  |
| 178 | `ecma3/Array/e15_4_3_2` | 0.0% | 0/1 | 1 | 1 |  |
| 179 | `ecma3/Boolean/e15_6_3_1` | 0.0% | 0/2 | 2 | 2 |  |
| 180 | `ecma3/Boolean/e15_6_3_1_2` | 0.0% | 0/1 | 1 | 1 |  |
| 181 | `ecma3/Boolean/e15_6_3_1_3` | 0.0% | 0/1 | 1 | 1 |  |
| 182 | `ecma3/Date/e15_9_1_1_1` | 0.0% | 0/686 | 0 | 686 |  |
| 183 | `ecma3/Date/e15_9_1_1_2` | 0.0% | 0/685 | 0 | 685 |  |
| 184 | `ecma3/Date/e15_9_2_1` | 0.0% | 0/24 | 0 | 24 |  |
| 185 | `ecma3/Date/e15_9_2_2_1` | 0.0% | 0/24 | 0 | 24 |  |
| 186 | `ecma3/Date/e15_9_2_2_2` | 0.0% | 0/20 | 0 | 20 |  |
| 187 | `ecma3/Date/e15_9_2_2_3` | 0.0% | 0/15 | 0 | 15 |  |
| 188 | `ecma3/Date/e15_9_2_2_4` | 0.0% | 0/3 | 0 | 3 |  |
| 189 | `ecma3/Date/e15_9_2_2_5` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `ecma3/Date/e15_9_2_2_6` | 0.0% | 0/4 | 0 | 4 |  |
| 191 | `ecma3/Date/e15_9_3_1_1` | 0.0% | 0/648 | 0 | 648 |  |
| 192 | `ecma3/Date/e15_9_3_1_2` | 0.0% | 0/90 | 0 | 90 |  |
| 193 | `ecma3/Date/e15_9_3_1_3` | 0.0% | 0/54 | 0 | 54 |  |
| 194 | `ecma3/Date/e15_9_3_1_4` | 0.0% | 0/90 | 0 | 90 |  |
| 195 | `ecma3/Date/e15_9_3_1_5` | 0.0% | 0/36 | 0 | 36 |  |
| 196 | `ecma3/Date/e15_9_3_2_1` | 0.0% | 0/90 | 0 | 90 |  |
| 197 | `ecma3/Date/e15_9_3_2_2` | 0.0% | 0/54 | 0 | 54 |  |
| 198 | `ecma3/Date/e15_9_3_2_3` | 0.0% | 0/72 | 0 | 72 |  |
| 199 | `ecma3/Date/e15_9_3_2_4` | 0.0% | 0/54 | 0 | 54 |  |
| 200 | `ecma3/Date/e15_9_3_2_5` | 0.0% | 0/36 | 0 | 36 |  |
| 201 | `ecma3/Date/e15_9_3_8_1` | 0.0% | 0/90 | 0 | 90 |  |
| 202 | `ecma3/Date/e15_9_3_8_2` | 0.0% | 0/90 | 0 | 90 |  |
| 203 | `ecma3/Date/e15_9_3_8_3` | 0.0% | 0/108 | 0 | 108 |  |
| 204 | `ecma3/Date/e15_9_3_8_4` | 0.0% | 0/72 | 0 | 72 |  |
| 205 | `ecma3/Date/e15_9_3_8_5` | 0.0% | 0/108 | 0 | 108 |  |
| 206 | `ecma3/Date/e15_9_4_2` | 0.0% | 0/391 | 0 | 391 |  |
| 207 | `ecma3/Date/e15_9_4_2_1` | 0.0% | 0/4 | 0 | 4 |  |
| 208 | `ecma3/Date/e15_9_4_3` | 0.0% | 0/40 | 0 | 40 |  |
| 209 | `ecma3/Date/e15_9_5` | 0.0% | 0/1 | 0 | 1 |  |
| 210 | `ecma3/Date/e15_9_5_1` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `ecma3/Date/e15_9_5_10` | 0.0% | 0/121 | 0 | 121 |  |
| 212 | `ecma3/Date/e15_9_5_10_10` | 0.0% | 0/33 | 0 | 33 |  |
| 213 | `ecma3/Date/e15_9_5_10_11` | 0.0% | 0/95 | 0 | 95 |  |
| 214 | `ecma3/Date/e15_9_5_10_12` | 0.0% | 0/64 | 0 | 64 |  |
| 215 | `ecma3/Date/e15_9_5_10_13` | 0.0% | 0/33 | 0 | 33 |  |
| 216 | `ecma3/Date/e15_9_5_10_3` | 0.0% | 0/31 | 0 | 31 |  |
| 217 | `ecma3/Date/e15_9_5_10_4` | 0.0% | 0/31 | 0 | 31 |  |
| 218 | `ecma3/Date/e15_9_5_10_5` | 0.0% | 0/31 | 0 | 31 |  |
| 219 | `ecma3/Date/e15_9_5_10_6` | 0.0% | 0/32 | 0 | 32 |  |
| 220 | `ecma3/Date/e15_9_5_10_7` | 0.0% | 0/31 | 0 | 31 |  |
| 221 | `ecma3/Date/e15_9_5_10_8` | 0.0% | 0/33 | 0 | 33 |  |
| 222 | `ecma3/Date/e15_9_5_10_9` | 0.0% | 0/33 | 0 | 33 |  |
| 223 | `ecma3/Date/e15_9_5_11` | 0.0% | 0/33 | 0 | 33 |  |
| 224 | `ecma3/Date/e15_9_5_11_1` | 0.0% | 0/55 | 0 | 55 |  |
| 225 | `ecma3/Date/e15_9_5_11_3` | 0.0% | 0/55 | 0 | 55 |  |
| 226 | `ecma3/Date/e15_9_5_11_4` | 0.0% | 0/55 | 0 | 55 |  |
| 227 | `ecma3/Date/e15_9_5_11_5` | 0.0% | 0/55 | 0 | 55 |  |
| 228 | `ecma3/Date/e15_9_5_11_6` | 0.0% | 0/55 | 0 | 55 |  |
| 229 | `ecma3/Date/e15_9_5_11_7` | 0.0% | 0/55 | 0 | 55 |  |
| 230 | `ecma3/Date/e15_9_5_12` | 0.0% | 0/33 | 0 | 33 |  |
| 231 | `ecma3/Date/e15_9_5_12_3` | 0.0% | 0/67 | 0 | 67 |  |
| 232 | `ecma3/Date/e15_9_5_12_4` | 0.0% | 0/67 | 0 | 67 |  |
| 233 | `ecma3/Date/e15_9_5_12_5` | 0.0% | 0/67 | 0 | 67 |  |
| 234 | `ecma3/Date/e15_9_5_12_6` | 0.0% | 0/55 | 0 | 55 |  |
| 235 | `ecma3/Date/e15_9_5_12_7` | 0.0% | 0/67 | 0 | 67 |  |
| 236 | `ecma3/Date/e15_9_5_12_8` | 0.0% | 0/2 | 0 | 2 |  |
| 237 | `ecma3/Date/e15_9_5_13` | 0.0% | 0/33 | 0 | 33 |  |
| 238 | `ecma3/Date/e15_9_5_13_1` | 0.0% | 0/36 | 0 | 36 |  |
| 239 | `ecma3/Date/e15_9_5_13_2` | 0.0% | 0/36 | 0 | 36 |  |
| 240 | `ecma3/Date/e15_9_5_13_3` | 0.0% | 0/36 | 0 | 36 |  |
| 241 | `ecma3/Date/e15_9_5_13_4` | 0.0% | 0/36 | 0 | 36 |  |
| 242 | `ecma3/Date/e15_9_5_13_5` | 0.0% | 0/36 | 0 | 36 |  |
| 243 | `ecma3/Date/e15_9_5_13_6` | 0.0% | 0/60 | 0 | 60 |  |
| 244 | `ecma3/Date/e15_9_5_13_7` | 0.0% | 0/60 | 0 | 60 |  |
| 245 | `ecma3/Date/e15_9_5_13_8` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `ecma3/Date/e15_9_5_14` | 0.0% | 0/44 | 0 | 44 |  |
| 247 | `ecma3/Date/e15_9_5_15` | 0.0% | 0/58 | 0 | 58 |  |
| 248 | `ecma3/Date/e15_9_5_15_1` | 0.0% | 0/33 | 0 | 33 |  |
| 249 | `ecma3/Date/e15_9_5_16` | 0.0% | 0/51 | 0 | 51 |  |
| 250 | `ecma3/Date/e15_9_5_17` | 0.0% | 0/51 | 0 | 51 |  |
| 251 | `ecma3/Date/e15_9_5_17_1` | 0.0% | 0/33 | 0 | 33 |  |
| 252 | `ecma3/Date/e15_9_5_18` | 0.0% | 0/51 | 0 | 51 |  |
| 253 | `ecma3/Date/e15_9_5_19` | 0.0% | 0/51 | 0 | 51 |  |
| 254 | `ecma3/Date/e15_9_5_2` | 0.0% | 0/15 | 0 | 15 |  |
| 255 | `ecma3/Date/e15_9_5_20` | 0.0% | 0/79 | 0 | 79 |  |
| 256 | `ecma3/Date/e15_9_5_21_1` | 0.0% | 0/9 | 0 | 9 |  |
| 257 | `ecma3/Date/e15_9_5_21_2` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `ecma3/Date/e15_9_5_21_3` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `ecma3/Date/e15_9_5_21_4` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `ecma3/Date/e15_9_5_21_5` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `ecma3/Date/e15_9_5_21_6` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `ecma3/Date/e15_9_5_21_7` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `ecma3/Date/e15_9_5_21_8` | 0.0% | 0/2 | 0 | 2 |  |
| 264 | `ecma3/Date/e15_9_5_22_1` | 0.0% | 0/68 | 0 | 68 |  |
| 265 | `ecma3/Date/e15_9_5_22_2` | 0.0% | 0/11 | 0 | 11 |  |
| 266 | `ecma3/Date/e15_9_5_22_3` | 0.0% | 0/11 | 0 | 11 |  |
| 267 | `ecma3/Date/e15_9_5_22_4` | 0.0% | 0/11 | 0 | 11 |  |
| 268 | `ecma3/Date/e15_9_5_22_5` | 0.0% | 0/11 | 0 | 11 |  |
| 269 | `ecma3/Date/e15_9_5_22_6` | 0.0% | 0/11 | 0 | 11 |  |
| 270 | `ecma3/Date/e15_9_5_22_7` | 0.0% | 0/11 | 0 | 11 |  |
| 271 | `ecma3/Date/e15_9_5_22_8` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `ecma3/Date/e15_9_5_23_1` | 0.0% | 0/18 | 0 | 18 |  |
| 273 | `ecma3/Date/e15_9_5_23_10` | 0.0% | 0/18 | 0 | 18 |  |
| 274 | `ecma3/Date/e15_9_5_23_11` | 0.0% | 0/18 | 0 | 18 |  |
| 275 | `ecma3/Date/e15_9_5_23_12` | 0.0% | 0/18 | 0 | 18 |  |
| 276 | `ecma3/Date/e15_9_5_23_13` | 0.0% | 0/18 | 0 | 18 |  |
| 277 | `ecma3/Date/e15_9_5_23_14` | 0.0% | 0/18 | 0 | 18 |  |
| 278 | `ecma3/Date/e15_9_5_23_15` | 0.0% | 0/18 | 0 | 18 |  |
| 279 | `ecma3/Date/e15_9_5_23_16` | 0.0% | 0/18 | 0 | 18 |  |
| 280 | `ecma3/Date/e15_9_5_23_17` | 0.0% | 0/18 | 0 | 18 |  |
| 281 | `ecma3/Date/e15_9_5_23_18` | 0.0% | 0/18 | 0 | 18 |  |
| 282 | `ecma3/Date/e15_9_5_23_2` | 0.0% | 0/26 | 0 | 26 |  |
| 283 | `ecma3/Date/e15_9_5_23_3_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 284 | `ecma3/Date/e15_9_5_23_4` | 0.0% | 0/44 | 0 | 44 |  |
| 285 | `ecma3/Date/e15_9_5_23_5` | 0.0% | 0/44 | 0 | 44 |  |
| 286 | `ecma3/Date/e15_9_5_23_6` | 0.0% | 0/44 | 0 | 44 |  |
| 287 | `ecma3/Date/e15_9_5_23_7` | 0.0% | 0/44 | 0 | 44 |  |
| 288 | `ecma3/Date/e15_9_5_23_8` | 0.0% | 0/42 | 0 | 42 |  |
| 289 | `ecma3/Date/e15_9_5_23_9` | 0.0% | 0/42 | 0 | 42 |  |
| 290 | `ecma3/Date/e15_9_5_24_1` | 0.0% | 0/16 | 0 | 16 |  |
| 291 | `ecma3/Date/e15_9_5_24_2` | 0.0% | 0/16 | 0 | 16 |  |
| 292 | `ecma3/Date/e15_9_5_24_3` | 0.0% | 0/16 | 0 | 16 |  |
| 293 | `ecma3/Date/e15_9_5_24_4` | 0.0% | 0/16 | 0 | 16 |  |
| 294 | `ecma3/Date/e15_9_5_24_5` | 0.0% | 0/16 | 0 | 16 |  |
| 295 | `ecma3/Date/e15_9_5_24_6` | 0.0% | 0/16 | 0 | 16 |  |
| 296 | `ecma3/Date/e15_9_5_24_7` | 0.0% | 0/16 | 0 | 16 |  |
| 297 | `ecma3/Date/e15_9_5_24_8` | 0.0% | 0/16 | 0 | 16 |  |
| 298 | `ecma3/Date/e15_9_5_25_1` | 0.0% | 0/153 | 0 | 153 |  |
| 299 | `ecma3/Date/e15_9_5_26_1` | 0.0% | 0/119 | 0 | 119 |  |
| 300 | `ecma3/Date/e15_9_5_27_1` | 0.0% | 0/119 | 0 | 119 |  |
| 301 | `ecma3/Date/e15_9_5_28_1` | 0.0% | 0/136 | 0 | 136 |  |
| 302 | `ecma3/Date/e15_9_5_29_1` | 0.0% | 0/119 | 0 | 119 |  |
| 303 | `ecma3/Date/e15_9_5_2_1` | 0.0% | 0/15 | 0 | 15 |  |
| 304 | `ecma3/Date/e15_9_5_2_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `ecma3/Date/e15_9_5_3` | 0.0% | 0/15 | 0 | 15 |  |
| 306 | `ecma3/Date/e15_9_5_30_1` | 0.0% | 0/144 | 0 | 144 |  |
| 307 | `ecma3/Date/e15_9_5_31_1` | 0.0% | 0/126 | 0 | 126 |  |
| 308 | `ecma3/Date/e15_9_5_32_1` | 0.0% | 0/180 | 0 | 180 |  |
| 309 | `ecma3/Date/e15_9_5_33_1` | 0.0% | 0/54 | 0 | 54 |  |
| 310 | `ecma3/Date/e15_9_5_34_1` | 0.0% | 0/164 | 0 | 164 |  |
| 311 | `ecma3/Date/e15_9_5_35_1` | 0.0% | 0/54 | 0 | 54 |  |
| 312 | `ecma3/Date/e15_9_5_36_1` | 0.0% | 0/54 | 0 | 54 |  |
| 313 | `ecma3/Date/e15_9_5_36_2` | 0.0% | 0/54 | 0 | 54 |  |
| 314 | `ecma3/Date/e15_9_5_36_3` | 0.0% | 0/54 | 0 | 54 |  |
| 315 | `ecma3/Date/e15_9_5_36_4` | 0.0% | 0/54 | 0 | 54 |  |
| 316 | `ecma3/Date/e15_9_5_36_5` | 0.0% | 0/162 | 0 | 162 |  |
| 317 | `ecma3/Date/e15_9_5_36_6` | 0.0% | 0/108 | 0 | 108 |  |
| 318 | `ecma3/Date/e15_9_5_36_7` | 0.0% | 0/54 | 0 | 54 |  |
| 319 | `ecma3/Date/e15_9_5_37_1` | 0.0% | 0/360 | 0 | 360 |  |
| 320 | `ecma3/Date/e15_9_5_37_2` | 0.0% | 0/54 | 0 | 54 |  |
| 321 | `ecma3/Date/e15_9_5_37_3` | 0.0% | 0/36 | 0 | 36 |  |
| 322 | `ecma3/Date/e15_9_5_37_4` | 0.0% | 0/54 | 0 | 54 |  |
| 323 | `ecma3/Date/e15_9_5_37_5` | 0.0% | 0/54 | 0 | 54 |  |
| 324 | `ecma3/Date/e15_9_5_3_1_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 325 | `ecma3/Date/e15_9_5_3_2` | 0.0% | 0/30 | 0 | 30 |  |
| 326 | `ecma3/Date/e15_9_5_4` | 0.0% | 0/16 | 0 | 16 |  |
| 327 | `ecma3/Date/e15_9_5_42` | 0.0% | 0/15 | 0 | 15 |  |
| 328 | `ecma3/Date/e15_9_5_4_1` | 0.0% | 0/30 | 0 | 30 |  |
| 329 | `ecma3/Date/e15_9_5_4_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 330 | `ecma3/Date/e15_9_5_5` | 0.0% | 0/15 | 0 | 15 |  |
| 331 | `ecma3/Date/e15_9_5_6` | 0.0% | 0/15 | 0 | 15 |  |
| 332 | `ecma3/Date/e15_9_5_7` | 0.0% | 0/16 | 0 | 16 |  |
| 333 | `ecma3/Exceptions/date_002_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `ecma3/Exceptions/date_004_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `ecma3/Exceptions/exception_001_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `ecma3/Exceptions/exception_002_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `ecma3/Exceptions/expression_005_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 338 | `ecma3/Exceptions/number_002_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 339 | `ecma3/Exceptions/string_002_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 340 | `ecma3/Expressions/e11_2_2_10_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 341 | `ecma3/FunctionObjects/e15_3_1_1_2_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 342 | `ecma3/FunctionObjects/e15_3_1_1_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 343 | `ecma3/FunctionObjects/e15_3_2_1_2_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `ecma3/FunctionObjects/e15_3_2_1_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 345 | `ecma3/FunctionObjects/e15_3_3_2` | 0.0% | 0/1 | 1 | 1 |  |
| 346 | `ecma3/FunctionObjects/e15_3_5_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `ecma3/GlobalObject/decodeURI` | 0.0% | 0/38 | 0 | 38 |  |
| 348 | `ecma3/GlobalObject/decodeURIComponent` | 0.0% | 0/24 | 0 | 24 |  |
| 349 | `ecma3/GlobalObject/e15_1_2_1_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 350 | `ecma3/GlobalObject/e15_1_3` | 0.0% | 0/2 | 2 | 2 |  |
| 351 | `ecma3/GlobalObject/encodeURI` | 0.0% | 0/39 | 0 | 39 |  |
| 352 | `ecma3/GlobalObject/encodeURIComponent` | 0.0% | 0/23 | 0 | 23 |  |
| 353 | `ecma3/Number/e15_7_3_2_2` | 0.0% | 0/2 | 2 | 2 |  |
| 354 | `ecma3/Number/e15_7_3_2_3` | 0.0% | 0/2 | 2 | 2 |  |
| 355 | `ecma3/Number/e15_7_3_3_2` | 0.0% | 0/2 | 2 | 2 |  |
| 356 | `ecma3/Number/e15_7_3_4_2` | 0.0% | 0/2 | 2 | 2 |  |
| 357 | `ecma3/Number/e15_7_3_5_2` | 0.0% | 0/2 | 2 | 2 |  |
| 358 | `ecma3/Number/e15_7_3_5_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 359 | `ecma3/Number/e15_7_3_6_2` | 0.0% | 0/2 | 2 | 2 |  |
| 360 | `ecma3/Number/e15_7_3_6_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 361 | `ecma3/ObjectObjects/class_006` | 0.0% | 0/1 | 1 | 1 |  |
| 362 | `ecma3/ObjectObjects/e15_2_3_1_2` | 0.0% | 0/1 | 1 | 1 |  |
| 363 | `ecma3/ObjectObjects/e15_2_3_1_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 364 | `ecma3/ObjectObjects/e15_2_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 365 | `ecma3/Statements/e12_10` | 0.0% | 0/1 | 1 | 1 |  |
| 366 | `ecma3/Statements/eforin_002` | 0.0% | 0/10 | 10 | 10 |  |
| 367 | `ecma3/String/e15_5_3_1_3` | 0.0% | 0/1 | 1 | 1 |  |
| 368 | `recursion/pcre_could_be_empty_branch` | 0.0% | 0/1 | 1 | 1 |  |
| 369 | `regress/bug_538107` | 0.0% | 0/2 | 0 | 2 |  |
| 370 | `regress/bug_551587_2_swf10` | 0.0% | 0/2 | 0 | 2 |  |
| 371 | `regress/bug_551587_2_swf11` | 0.0% | 0/2 | 0 | 2 |  |
| 372 | `regress/bug_558863_swf11` | 0.0% | 0/1 | 1 | 1 |  |
| 373 | `regress/bug_609416_swf11` | 0.0% | 0/1 | 0 | 1 |  |
