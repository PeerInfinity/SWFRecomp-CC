# Ruffle Test Results (Filtered)

**Date**: 2026-07-24 18:21 UTC

**Git SHA**: `74a28f304a`

**Run Duration**: 160m 50s

**Filtered**: 0 tests ignored out of 1574 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1574 |
| Passing | **847** (53.8%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **871** (55.3%) |
| Failing | 703 |
| Total expected lines | 85932 |
| Matching lines | 67106 (78.1%) |
| Mismatched lines | 18826 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 681 | 96.9% |
| Runtime Error | 16 | 2.3% |
| Timeout | 3 | 0.4% |
| Segfault | 2 | 0.3% |
| Compile Fail | 1 | 0.1% |

## Passing Tests

**847 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `as3/Array/regress_524122_swf10` | 1 | 6.1s |  |
| 2 | `as3/Array/regress_524122_swf11` | 1 | 6.1s |  |
| 3 | `as3/Array/regress_636535` | 6 | 6.0s |  |
| 4 | `as3/Array/regress_733384` | 24 | 6.3s |  |
| 5 | `as3/Definitions/Classes/ClassDef/Bug162570` | 5 | 6.1s |  |
| 6 | `as3/Definitions/Classes/ClassDef/DefaultClass` | 15 | 6.4s |  |
| 7 | `as3/Definitions/Classes/ClassDef/DefaultClassPrototype` | 18 | 6.4s |  |
| 8 | `as3/Definitions/Classes/ClassDef/DynamicClass` | 15 | 6.4s |  |
| 9 | `as3/Definitions/Classes/ClassDef/DynamicClassHasOwnProperty` | 1 | 6.0s |  |
| 10 | `as3/Definitions/Classes/ClassDef/DynamicClassMeth` | 2 | 6.0s |  |
| 11 | `as3/Definitions/Classes/ClassDef/DynamicClassProp` | 12 | 6.1s |  |
| 12 | `as3/Definitions/Classes/ClassDef/DynamicClassPrototype` | 18 | 6.4s |  |
| 13 | `as3/Definitions/Classes/ClassDef/DynamicClassSameMethPropName` | 4 | 6.2s |  |
| 14 | `as3/Definitions/Classes/ClassDef/FinalClassPrototype` | 18 | 6.5s |  |
| 15 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClassMethodAndProp` | 20 | 6.2s |  |
| 16 | `as3/Definitions/Classes/ClassDef/IntClassWithStrParamCons` | 4 | 6.1s |  |
| 17 | `as3/Definitions/Classes/ClassDef/InternalClassPrototype` | 18 | 6.4s |  |
| 18 | `as3/Definitions/Classes/ClassDef/PrivateStaticClassMethodAndProp` | 14 | 6.1s |  |
| 19 | `as3/Definitions/Classes/ClassDef/PublicClassMethodAndProp` | 20 | 6.2s |  |
| 20 | `as3/Definitions/Classes/ClassDef/PublicClassPrototype` | 18 | 6.3s |  |
| 21 | `as3/Definitions/Classes/ClassDef/StatClassSameNamePackage` | 0 | 1.9s |  |
| 22 | `as3/Definitions/Classes/ClassDef/bug113887` | 2 | 6.1s |  |
| 23 | `as3/Definitions/Classes/ClassDef/dynfinClassCons` | 1 | 6.1s |  |
| 24 | `as3/Definitions/Classes/ClassDef/dynfinClassDefCons` | 1 | 6.1s |  |
| 25 | `as3/Definitions/Classes/ClassDef/dynfinClassWithMultiStrParamCons` | 3 | 6.2s |  |
| 26 | `as3/Definitions/Classes/ClassDef/dynfinClassWithParamCons` | 1 | 6.2s |  |
| 27 | `as3/Definitions/Classes/ClassDef/dynfinClassWithStrParamCons` | 4 | 6.2s |  |
| 28 | `as3/Definitions/Classes/ClassDef/finClassNoParamCons` | 1 | 6.3s |  |
| 29 | `as3/Definitions/Classes/ClassDef/finalClassDefCons` | 1 | 3.2s |  |
| 30 | `as3/Definitions/Classes/ClassDef/finalClassWithParamCons` | 1 | 3.2s |  |
| 31 | `as3/Definitions/Classes/ClassDef/intClassDefCons` | 1 | 6.0s |  |
| 32 | `as3/Definitions/Classes/ClassDef/intClassNoParamCons` | 1 | 6.0s |  |
| 33 | `as3/Definitions/Classes/ClassDef/intClassWithParamCons` | 1 | 6.0s |  |
| 34 | `as3/Definitions/Classes/ClassDef/publicClassConsNoParam` | 1 | 5.9s |  |
| 35 | `as3/Definitions/Classes/ClassDef/publicClassDefCons` | 4 | 6.0s |  |
| 36 | `as3/Definitions/Classes/ClassDef/publicClassWithParamCons` | 1 | 5.9s |  |
| 37 | `as3/Definitions/Classes/ClassDef/testClassInitializers` | 3 | 6.0s |  |
| 38 | `as3/Definitions/Classes/ClassDef/testdynfinpublicClassInitializers` | 3 | 6.0s |  |
| 39 | `as3/Definitions/Classes/ClassDef/testinternalClassInitializers` | 3 | 6.0s |  |
| 40 | `as3/Definitions/Classes/Ext/AccNSStatMethSubClassMeth` | 6 | 6.0s |  |
| 41 | `as3/Definitions/Classes/Ext/AccNSStatPropSubClassMeth` | 6 | 6.0s |  |
| 42 | `as3/Definitions/Classes/Ext/AccStatMethIntermediateSubClassMeth` | 4 | 6.0s |  |
| 43 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMeth` | 6 | 6.0s |  |
| 44 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | 1 | 6.0s |  |
| 45 | `as3/Definitions/Classes/Ext/AccStatMethSubClassStatMeth` | 4 | 6.0s |  |
| 46 | `as3/Definitions/Classes/Ext/AccStatPropIntermediateSubClassMeth` | 6 | 6.0s |  |
| 47 | `as3/Definitions/Classes/Ext/AccStatPropSubClassInit` | 6 | 6.0s |  |
| 48 | `as3/Definitions/Classes/Ext/AccStatPropSubClassStatMeth` | 6 | 6.0s |  |
| 49 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | 3 | 6.1s |  |
| 50 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClassWIntermediate` | 3 | 6.0s |  |
| 51 | `as3/Definitions/Classes/Ext/DynExtDefaultClass` | 23 | 6.8s |  |
| 52 | `as3/Definitions/Classes/Ext/DynExtDefaultClassFin` | 21 | 6.4s |  |
| 53 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPub` | 40 | 6.6s |  |
| 54 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPubStat` | 24 | 6.6s |  |
| 55 | `as3/Definitions/Classes/Ext/DynExtDefaultClassStat` | 21 | 6.5s |  |
| 56 | `as3/Definitions/Classes/Ext/DynExtDynamicClass` | 16 | 6.3s |  |
| 57 | `as3/Definitions/Classes/Ext/DynExtDynamicClassFin` | 20 | 6.3s |  |
| 58 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPub` | 18 | 6.3s |  |
| 59 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPubStat` | 16 | 6.3s |  |
| 60 | `as3/Definitions/Classes/Ext/DynExtDynamicClassStat` | 22 | 6.5s |  |
| 61 | `as3/Definitions/Classes/Ext/DynExtInternalClass` | 21 | 6.8s |  |
| 62 | `as3/Definitions/Classes/Ext/DynExtPublicClass` | 8 | 6.3s |  |
| 63 | `as3/Definitions/Classes/Ext/DynExtPublicClassFin` | 24 | 6.5s |  |
| 64 | `as3/Definitions/Classes/Ext/DynExtPublicClassPub` | 16 | 6.4s |  |
| 65 | `as3/Definitions/Classes/Ext/DynExtPublicClassPubStat` | 14 | 6.5s |  |
| 66 | `as3/Definitions/Classes/Ext/DynExtPublicClassStat` | 14 | 6.5s |  |
| 67 | `as3/Definitions/Classes/Ext/ExtDefaultClass` | 20 | 6.9s |  |
| 68 | `as3/Definitions/Classes/Ext/ExtDefaultClassPub` | 14 | 6.4s |  |
| 69 | `as3/Definitions/Classes/Ext/ExtDefaultClassPubStat` | 26 | 6.6s |  |
| 70 | `as3/Definitions/Classes/Ext/ExtDefaultClassStat` | 25 | 6.6s |  |
| 71 | `as3/Definitions/Classes/Ext/ExtDefaultProtClass` | 20 | 6.7s |  |
| 72 | `as3/Definitions/Classes/Ext/ExtDynamicClass` | 19 | 6.3s |  |
| 73 | `as3/Definitions/Classes/Ext/ExtDynamicClassPub` | 21 | 6.4s |  |
| 74 | `as3/Definitions/Classes/Ext/ExtDynamicClassPubStat` | 26 | 6.5s |  |
| 75 | `as3/Definitions/Classes/Ext/ExtDynamicClassStat` | 24 | 6.5s |  |
| 76 | `as3/Definitions/Classes/Ext/ExtError` | 40 | 6.4s |  |
| 77 | `as3/Definitions/Classes/Ext/ExtInternalClass` | 20 | 6.8s |  |
| 78 | `as3/Definitions/Classes/Ext/ExtPublicClass` | 7 | 6.4s |  |
| 79 | `as3/Definitions/Classes/Ext/ExtPublicClassFin` | 10 | 6.6s |  |
| 80 | `as3/Definitions/Classes/Ext/ExtPublicClassPub` | 14 | 6.6s |  |
| 81 | `as3/Definitions/Classes/Ext/ExtPublicClassStat` | 28 | 6.6s |  |
| 82 | `as3/Definitions/Classes/Ext/IntExtDefaultClass` | 22 | 7.0s |  |
| 83 | `as3/Definitions/Classes/Ext/IntExtDynamicClass` | 20 | 6.9s |  |
| 84 | `as3/Definitions/Classes/Ext/IntExtInternalClass` | 20 | 7.0s |  |
| 85 | `as3/Definitions/Classes/Ext/IntExtPublicClass` | 20 | 7.0s |  |
| 86 | `as3/Definitions/Classes/Ext/PubExtDefaultClass` | 19 | 6.6s |  |
| 87 | `as3/Definitions/Classes/Ext/PubExtDefaultClassFin` | 16 | 6.6s |  |
| 88 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPub` | 20 | 6.6s |  |
| 89 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPubStat` | 29 | 6.7s |  |
| 90 | `as3/Definitions/Classes/Ext/PubExtDefaultClassStat` | 27 | 6.7s |  |
| 91 | `as3/Definitions/Classes/Ext/PubExtDynamicClass` | 18 | 6.5s |  |
| 92 | `as3/Definitions/Classes/Ext/PubExtDynamicClassFin` | 18 | 6.5s |  |
| 93 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPub` | 20 | 6.5s |  |
| 94 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPubStat` | 29 | 6.6s |  |
| 95 | `as3/Definitions/Classes/Ext/PubExtDynamicClassStat` | 29 | 5.7s |  |
| 96 | `as3/Definitions/Classes/Ext/PubExtInternalClass` | 17 | 6.5s |  |
| 97 | `as3/Definitions/Classes/Ext/PubExtPublicClass` | 12 | 6.5s |  |
| 98 | `as3/Definitions/Classes/Ext/PubExtPublicClassFin` | 16 | 6.6s |  |
| 99 | `as3/Definitions/Classes/Ext/PubExtPublicClassStat` | 27 | 6.8s |  |
| 100 | `as3/Definitions/Classes/Ext/PubFinExtDefaultClass` | 22 | 6.8s |  |
| 101 | `as3/Definitions/Function/EmptyFunctionBody` | 24 | 6.4s |  |
| 102 | `as3/Definitions/Function/EmptyFunctionName` | 52 | 6.7s |  |
| 103 | `as3/Definitions/Function/FinalFunctionBody` | 12 | 6.3s |  |
| 104 | `as3/Definitions/Function/FinalFunctionName` | 28 | 6.4s |  |
| 105 | `as3/Definitions/Function/MultiOptArgFunction` | 12 | 6.5s |  |
| 106 | `as3/Definitions/Function/MultipleExtraArgFunction1` | 4 | 6.2s |  |
| 107 | `as3/Definitions/Function/MultipleExtraArgFunction2` | 4 | 6.2s |  |
| 108 | `as3/Definitions/Function/MultipleExtraArgFunction3` | 4 | 6.2s |  |
| 109 | `as3/Definitions/Function/NamespaceFunctionBody` | 12 | 6.4s |  |
| 110 | `as3/Definitions/Function/NamespaceFunctionName` | 28 | 6.4s |  |
| 111 | `as3/Definitions/Function/NoExtraArgFunction` | 4 | 6.2s |  |
| 112 | `as3/Definitions/Function/OneExtraArgFunction` | 20 | 3.4s |  |
| 113 | `as3/Definitions/Function/OneOptArgFunction` | 12 | 6.3s |  |
| 114 | `as3/Definitions/Function/OverrideFunctionBody` | 12 | 6.3s |  |
| 115 | `as3/Definitions/Function/OverrideFunctionName` | 28 | 6.4s |  |
| 116 | `as3/Definitions/Function/PrivateFunctionBody` | 12 | 6.3s |  |
| 117 | `as3/Definitions/Function/PrivateFunctionName` | 26 | 6.4s |  |
| 118 | `as3/Definitions/Function/PublicFunctionBody` | 24 | 6.5s |  |
| 119 | `as3/Definitions/Function/PublicFunctionName` | 54 | 6.7s |  |
| 120 | `as3/Definitions/Function/RestGlobal` | 17 | 6.1s |  |
| 121 | `as3/Definitions/Function/StaticFunctionBody` | 12 | 6.2s |  |
| 122 | `as3/Definitions/Function/StaticFunctionName` | 26 | 6.4s |  |
| 123 | `as3/Definitions/Function/StaticPrivateFunctionName` | 13 | 6.4s |  |
| 124 | `as3/Definitions/Function/StaticPublicFunctionName` | 13 | 6.4s |  |
| 125 | `as3/Definitions/Function/ThreeOptArgFunction` | 4 | 6.3s |  |
| 126 | `as3/Definitions/Function/VirtualFunctionBody` | 12 | 3.3s |  |
| 127 | `as3/Definitions/Function/VirtualFunctionName` | 28 | 5.7s |  |
| 128 | `as3/Definitions/Function/VoidEvaluation` | 3 | 6.3s |  |
| 129 | `as3/Definitions/Function/bug152222` | 2 | 6.1s |  |
| 130 | `as3/Definitions/Function/functionReturnTypes` | 319 | 8.0s |  |
| 131 | `as3/Definitions/Interfaces/Example_1_1_6` | 2 | 6.1s |  |
| 132 | `as3/Definitions/Interfaces/Example_9_3` | 4 | 6.2s |  |
| 133 | `as3/Definitions/Interfaces/ExtendMultipleInterfaces` | 8 | 6.5s |  |
| 134 | `as3/Definitions/Interfaces/GetSet` | 10 | 6.2s |  |
| 135 | `as3/Definitions/Interfaces/ImplementByExtension` | 6 | 6.6s |  |
| 136 | `as3/Definitions/Interfaces/ImplementMultipleInterfaces` | 8 | 6.2s |  |
| 137 | `as3/Definitions/Interfaces/InterfaceAsType` | 11 | 6.2s |  |
| 138 | `as3/Definitions/Interfaces/Lattice` | 7 | 6.0s |  |
| 139 | `as3/Definitions/Interfaces/bug127174` | 1 | 6.0s |  |
| 140 | `as3/Definitions/Super/SuperArgsCall` | 4 | 6.0s |  |
| 141 | `as3/Definitions/Super/SuperExprChainAccess` | 10 | 6.0s |  |
| 142 | `as3/Definitions/Super/SuperImplicitlyCalled` | 4 | 6.0s |  |
| 143 | `as3/Definitions/Super/SuperObject` | 1 | 5.9s |  |
| 144 | `as3/Definitions/Super/SuperObjectCall` | 1 | 6.0s |  |
| 145 | `as3/Definitions/Variable/ConstVariables_custom2` | 22 | 6.1s |  |
| 146 | `as3/Definitions/Variable/ModifyClassConstGlobally_rt` | 1 | 6.0s |  |
| 147 | `as3/Definitions/Variable/ModifyClassVariableInObjectInstance_rt` | 1 | 6.0s |  |
| 148 | `as3/Definitions/Variable/ModifyPackageConstGlobally_rt` | 1 | 6.0s |  |
| 149 | `as3/Definitions/Variable/ModifyVariables` | 25 | 6.1s |  |
| 150 | `as3/Definitions/Variable/ProtectedVariables` | 8 | 6.1s |  |
| 151 | `as3/Definitions/Variable/VarDefEmpty` | 44 | 6.4s |  |
| 152 | `as3/Definitions/Variable/VarDefOutside` | 20 | 6.0s |  |
| 153 | `as3/Definitions/Variable/VarDefOutsideNoVar` | 9 | 6.0s |  |
| 154 | `as3/Definitions/Variable/VarDefPrivate` | 44 | 6.5s |  |
| 155 | `as3/Definitions/Variable/VarDefPrivateStatic` | 44 | 6.7s |  |
| 156 | `as3/Definitions/Variable/VarDefPublic` | 44 | 6.5s |  |
| 157 | `as3/Definitions/Variable/VarDefPublicStatic` | 44 | 6.5s |  |
| 158 | `as3/Definitions/Variable/VarDefStatic` | 44 | 5.6s |  |
| 159 | `as3/Definitions/const/ConstAccessFromClass` | 1 | 6.0s |  |
| 160 | `as3/Definitions/const/ConstAccessWithinClass` | 1 | 6.0s |  |
| 161 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName` | 1 | 6.0s |  |
| 162 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName2` | 1 | 6.0s |  |
| 163 | `as3/Definitions/const/ConstAndFunctionArgWithSameName` | 1 | 6.0s |  |
| 164 | `as3/Definitions/const/ConstAndFunctionArgWithSameName2` | 1 | 6.0s |  |
| 165 | `as3/Definitions/const/ConstAsVarReplacement` | 1 | 5.9s |  |
| 166 | `as3/Definitions/const/ConstConditionalInitialization` | 1 | 6.0s |  |
| 167 | `as3/Definitions/const/ConstConditionalInitializationInClass` | 1 | 6.0s |  |
| 168 | `as3/Definitions/const/ConstConditionalInitializationInClass2` | 1 | 5.9s |  |
| 169 | `as3/Definitions/const/ConstConditionalInitializationInClass3_rt` | 1 | 6.0s |  |
| 170 | `as3/Definitions/const/ConstConditionalInitializationInFunc` | 1 | 5.9s |  |
| 171 | `as3/Definitions/const/ConstInPackage` | 1 | 5.9s |  |
| 172 | `as3/Definitions/const/ConstInPackage2` | 1 | 5.9s |  |
| 173 | `as3/Definitions/const/ConstInPackageWithClass` | 1 | 6.0s |  |
| 174 | `as3/Definitions/const/ConstInPackageWithFunction` | 1 | 6.0s |  |
| 175 | `as3/Definitions/const/ConstInitializationInsideConstructor` | 1 | 3.0s |  |
| 176 | `as3/Definitions/const/ConstInitializationOutsideClass_rt` | 1 | 6.0s |  |
| 177 | `as3/Definitions/const/ConstInsideClass` | 1 | 5.9s |  |
| 178 | `as3/Definitions/const/ConstKeyword` | 1 | 5.5s |  |
| 179 | `as3/Definitions/const/ConstReinit_rt` | 1 | 5.9s |  |
| 180 | `as3/Definitions/const/ConstVarAsClassProp` | 2 | 6.0s |  |
| 181 | `as3/Definitions/const/ConstVarInsideClassFunction` | 1 | 6.0s |  |
| 182 | `as3/Definitions/const/ConstVarInsideClassFunction2_rt` | 1 | 6.1s |  |
| 183 | `as3/Definitions/const/ConstVarInsideGlobalFunction` | 1 | 6.2s |  |
| 184 | `as3/Definitions/const/ConstVarInsideGlobalFunction2` | 1 | 6.2s |  |
| 185 | `as3/Definitions/const/ConstVarInsideGlobalFunction3` | 1 | 3.2s |  |
| 186 | `as3/Definitions/const/ConstVarInsideGlobalFunction4` | 1 | 6.3s |  |
| 187 | `as3/Definitions/const/ConstVarInsideGlobalFunction5_rt` | 1 | 6.2s |  |
| 188 | `as3/Definitions/const/ConstVarInsideGlobalFunction6` | 4 | 6.2s |  |
| 189 | `as3/Definitions/const/ConstWithinClass` | 1 | 6.2s |  |
| 190 | `as3/Definitions/const/ConstWithinPackage` | 1 | 3.2s |  |
| 191 | `as3/Definitions/const/GlobalConstInitialization2_rt` | 1 | 6.4s |  |
| 192 | `as3/Definitions/const/GlobalConstInitialization_rt` | 1 | 6.3s |  |
| 193 | `as3/Definitions/const/StaticConst` | 1 | 6.2s |  |
| 194 | `as3/Definitions/const/StaticConstInDerivedClass` | 1 | 6.1s |  |
| 195 | `as3/Definitions/const/StaticConstInitializationOutsideClass_rt` | 1 | 6.4s |  |
| 196 | `as3/Expressions/QualifiedReferences/AS3NSReferences` | 3 | 3.2s |  |
| 197 | `as3/Expressions/QualifiedReferences/DescendantOperator` | 3 | 6.4s |  |
| 198 | `as3/Expressions/QualifiedReferences/FilterOperator` | 2 | 6.4s |  |
| 199 | `as3/Expressions/QualifiedReferences/MultipleNamespaces` | 7 | 6.2s |  |
| 200 | `as3/Expressions/QualifiedReferences/NSSingleFunc` | 3 | 6.3s |  |
| 201 | `as3/Expressions/QualifiedReferences/ReturnNSReference` | 3 | 6.3s |  |
| 202 | `as3/Expressions/QualifiedReferences/ReturnNamespace` | 1 | 6.3s |  |
| 203 | `as3/Expressions/asOperator/asOperator` | 75 | 6.9s |  |
| 204 | `as3/Expressions/asOperator/asOperatorConversions` | 48 | 6.7s |  |
| 205 | `as3/Expressions/asOperator/asOperatorMuliti` | 12 | 6.4s |  |
| 206 | `as3/Expressions/asOperator/asOperatorTypes` | 48 | 6.6s |  |
| 207 | `as3/Expressions/asOperator/asTypeError` | 2 | 6.4s |  |
| 208 | `as3/Expressions/deleteOperator/deleteArray` | 9 | 6.2s |  |
| 209 | `as3/Expressions/deleteOperator/deleteClass` | 1 | 6.3s |  |
| 210 | `as3/Expressions/deleteOperator/deleteInstantiatedFunction` | 4 | 6.3s |  |
| 211 | `as3/Expressions/deleteOperator/deleteInstantiatedVar` | 2 | 6.3s |  |
| 212 | `as3/Expressions/deleteOperator/deleteNonexistentDynamicProperty` | 1 | 6.3s |  |
| 213 | `as3/Expressions/deleteOperator/deleteNoninstantiatedFunction` | 2 | 6.3s |  |
| 214 | `as3/Expressions/deleteOperator/deleteNoninstantiatedVar` | 2 | 3.3s |  |
| 215 | `as3/Expressions/e11_2_2_1` | 4 | 6.3s |  |
| 216 | `as3/Expressions/e11_2_4` | 25 | 6.6s |  |
| 217 | `as3/Expressions/e11_4_3` | 86 | 7.1s |  |
| 218 | `as3/Expressions/e11_9_4` | 56 | 7.1s |  |
| 219 | `as3/Expressions/e11_9_5` | 56 | 4.1s |  |
| 220 | `as3/Expressions/indexProperties` | 36 | 6.8s |  |
| 221 | `as3/Expressions/isOperator/isOper` | 429 | 6.8s |  |
| 222 | `as3/Expressions/isOperator/isOperTypeError` | 2 | 6.3s |  |
| 223 | `as3/Expressions/logicalAssignment` | 16 | 6.4s |  |
| 224 | `as3/Expressions/logicalAssignment2` | 4 | 6.3s |  |
| 225 | `as3/Expressions/postfix` | 14 | 6.3s |  |
| 226 | `as3/Math/MathClass` | 2 | 3.2s |  |
| 227 | `as3/Math/MathUtils` | 7 | 6.2s |  |
| 228 | `as3/Math/e15_8_2_11_rest` | 6 | 6.3s |  |
| 229 | `as3/Math/e15_8_2_12_rest` | 12 | 6.4s |  |
| 230 | `as3/Math/op_divide_703238` | 9 | 5.9s |  |
| 231 | `as3/Math/op_subtract_703238` | 8 | 5.8s |  |
| 232 | `as3/MethodClosures/MethodClosure` | 1 | 5.9s |  |
| 233 | `as3/MethodClosures/MethodClosureFunc` | 1 | 5.9s |  |
| 234 | `as3/RegExp/bug_513020` | 2 | 5.9s |  |
| 235 | `as3/RegExp/eregress_122076` | 1 | 6.0s |  |
| 236 | `as3/RuntimeErrors/Error1002PrecisionArgOutOfRange` | 1 | 6.0s |  |
| 237 | `as3/RuntimeErrors/Error1003RadixArgOutOfRange` | 1 | 6.0s |  |
| 238 | `as3/RuntimeErrors/Error1005ArrayIndexNotInteger` | 1 | 6.0s |  |
| 239 | `as3/RuntimeErrors/Error1006CallNonFunctionObject` | 2 | 6.0s |  |
| 240 | `as3/RuntimeErrors/Error1007InstantiationOnNonConstructor` | 1 | 6.0s |  |
| 241 | `as3/RuntimeErrors/Error1009CannotAccessPropOfNullRef` | 1 | 3.1s |  |
| 242 | `as3/RuntimeErrors/Error1010UndefinedTerm` | 1 | 6.0s |  |
| 243 | `as3/RuntimeErrors/Error1016DescendantsOpNotSupported` | 1 | 6.0s |  |
| 244 | `as3/RuntimeErrors/Error1034TypeCoercionFailed` | 1 | 6.0s |  |
| 245 | `as3/RuntimeErrors/Error1037CannotAssignMethod` | 1 | 5.9s |  |
| 246 | `as3/RuntimeErrors/Error1040InvalidRHSOfInstanceof` | 1 | 5.9s |  |
| 247 | `as3/RuntimeErrors/Error1041RHSOfIsMustBeClass` | 1 | 3.1s |  |
| 248 | `as3/RuntimeErrors/Error1056CannotCreatePropInSealedClass` | 1 | 6.0s |  |
| 249 | `as3/RuntimeErrors/Error1065VariableNotDefined` | 1 | 5.9s |  |
| 250 | `as3/RuntimeErrors/Error1069PropertyNotFound` | 1 | 5.9s |  |
| 251 | `as3/RuntimeErrors/Error1070MethodNotFound` | 1 | 6.0s |  |
| 252 | `as3/RuntimeErrors/Error1077IllegalReadOfWriteOnlyProp` | 1 | 6.0s |  |
| 253 | `as3/RuntimeErrors/Error1083XmlPrefixNotFound` | 1 | 6.0s |  |
| 254 | `as3/RuntimeErrors/Error1084XmlQNameProductionMismatch` | 1 | 5.9s |  |
| 255 | `as3/RuntimeErrors/Error1085XmlEndTagMissing` | 1 | 3.0s |  |
| 256 | `as3/RuntimeErrors/Error1086XmlMethodOnlyOnListWithOneItem` | 1 | 5.9s |  |
| 257 | `as3/RuntimeErrors/Error1087XmlAssignToIndexedXml` | 2 | 3.0s |  |
| 258 | `as3/RuntimeErrors/Error1088XmlDocNotWellFormed` | 1 | 5.9s |  |
| 259 | `as3/RuntimeErrors/Error1089XmlAssignToMoreThanOneItemList` | 2 | 5.9s |  |
| 260 | `as3/RuntimeErrors/Error1090XmlElementMalformed` | 1 | 2.9s |  |
| 261 | `as3/RuntimeErrors/Error1091XmlUnterminatedCdata` | 1 | 5.8s |  |
| 262 | `as3/RuntimeErrors/Error1093XmlUnterminatedDoctype` | 1 | 3.1s |  |
| 263 | `as3/RuntimeErrors/Error1094XmlUnterminatedComment` | 1 | 5.8s |  |
| 264 | `as3/RuntimeErrors/Error1097XmlUnterminatedProcessingInstr` | 1 | 5.8s |  |
| 265 | `as3/RuntimeErrors/Error1098XmlIllegalPrefixFoNoNamespace` | 1 | 3.0s |  |
| 266 | `as3/RuntimeErrors/Error1100RegExpFlagsArg` | 1 | 5.8s |  |
| 267 | `as3/RuntimeErrors/Error1104XmlDuplicateAttr` | 1 | 5.8s |  |
| 268 | `as3/RuntimeErrors/Error1115NotAConstructor/v11` | 3 | 6.1s |  |
| 269 | `as3/RuntimeErrors/Error1116FunctionProtoApply2ndArgMustBeArr` | 1 | 5.8s |  |
| 270 | `as3/RuntimeErrors/Error1118IllegalCyclicalLoop` | 2 | 5.9s |  |
| 271 | `as3/ShellClasses/Dictionary` | 22 | 6.0s |  |
| 272 | `as3/Statements/Exceptions/MultipleCatchBlocks2` | 7 | 6.0s |  |
| 273 | `as3/Statements/Exceptions/MultipleCatchBlocksArgument` | 1 | 6.0s |  |
| 274 | `as3/Statements/Exceptions/MultipleCatchBlocksEval` | 1 | 3.1s |  |
| 275 | `as3/Statements/Exceptions/MultipleCatchBlocksRange` | 1 | 6.0s |  |
| 276 | `as3/Statements/Exceptions/MultipleCatchBlocksRefErrorCaughtWithError` | 1 | 5.9s |  |
| 277 | `as3/Statements/Exceptions/MultipleCatchBlocksReference` | 1 | 6.0s |  |
| 278 | `as3/Statements/Exceptions/MultipleCatchBlocksType` | 1 | 6.1s |  |
| 279 | `as3/Statements/Exceptions/MultipleCatchBlocksType1` | 1 | 5.9s |  |
| 280 | `as3/Statements/Exceptions/MultipleCatchBlocksType2` | 1 | 5.8s |  |
| 281 | `as3/Statements/Exceptions/MultipleCatchBlocksType3` | 1 | 5.9s |  |
| 282 | `as3/Statements/Exceptions/MultipleCatchBlocksType4` | 1 | 5.9s |  |
| 283 | `as3/Statements/Exceptions/MultipleCatchBlocksType5` | 1 | 1.4s |  |
| 284 | `as3/Statements/Exceptions/MultipleCatchBlocksType6` | 1 | 1.4s |  |
| 285 | `as3/Statements/Exceptions/MultipleCatchBlocksType7` | 1 | 6.0s |  |
| 286 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArg1` | 1 | 6.0s |  |
| 287 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArgErrorCaughtByError` | 1 | 6.0s |  |
| 288 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDef1` | 1 | 5.9s |  |
| 289 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDefErrorCaughtWithError` | 1 | 5.9s |  |
| 290 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEval1` | 1 | 5.9s |  |
| 291 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEvalErrorCaughtByError` | 1 | 5.9s |  |
| 292 | `as3/Statements/Exceptions/MultipleCatchBlocksWithNoTypeErrorCatchBlock` | 1 | 6.0s |  |
| 293 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRange1` | 1 | 6.0s |  |
| 294 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRangeErrorCaughtByError` | 1 | 6.0s |  |
| 295 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRefError1` | 1 | 6.0s |  |
| 296 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntax` | 1 | 1.5s |  |
| 297 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntaxErrorCaughtByError` | 1 | 1.4s |  |
| 298 | `as3/Statements/Exceptions/MultipleCatchBlocksWithTwoType` | 2 | 6.2s |  |
| 299 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURI1` | 1 | 6.0s |  |
| 300 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURICaughtByError` | 1 | 5.3s |  |
| 301 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUninitialized1` | 1 | 5.9s |  |
| 302 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUnitializedCaughtWithError` | 1 | 5.9s |  |
| 303 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerify1` | 1 | 5.9s |  |
| 304 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerifyCaughtByError` | 1 | 0.9s |  |
| 305 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchBlocksTypeWithNoInnerCatchType` | 2 | 6.0s |  |
| 306 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchRefType` | 2 | 6.1s |  |
| 307 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideEighthCatch` | 2 | 6.0s |  |
| 308 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideFifthCatch` | 2 | 6.1s |  |
| 309 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSeventhCatch` | 2 | 3.2s |  |
| 310 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSixthCatch` | 2 | 3.2s |  |
| 311 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinally` | 2 | 6.0s |  |
| 312 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinallyExceptionBubbling` | 1 | 6.2s |  |
| 313 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatch` | 2 | 6.2s |  |
| 314 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatchWithoutMatchingCatch` | 2 | 6.1s |  |
| 315 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatch` | 2 | 6.0s |  |
| 316 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatchWithoutMatchingCatch` | 2 | 6.1s |  |
| 317 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatch` | 2 | 6.0s |  |
| 318 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatchWithoutMatchingCatch` | 1 | 6.0s |  |
| 319 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTry` | 1 | 6.0s |  |
| 320 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTryWithoutMatchingCatch` | 1 | 6.0s |  |
| 321 | `as3/Statements/Exceptions/TryCatchBlockPackage` | 1 | 5.9s |  |
| 322 | `as3/Statements/Exceptions/TryCatchBlockPackage2` | 1 | 6.0s |  |
| 323 | `as3/Statements/Exceptions/TryCatchBlockPackage3` | 1 | 3.1s |  |
| 324 | `as3/Statements/Exceptions/UserDefinedErrorsInPackage` | 1 | 5.9s |  |
| 325 | `as3/Statements/Exceptions/UserDefinedErrorsPackage` | 1 | 5.9s |  |
| 326 | `as3/Statements/Exceptions/UserDefinedErrorsPackage2` | 1 | 5.9s |  |
| 327 | `as3/Statements/Exceptions/UserDefinedErrorsPackage3` | 1 | 5.9s |  |
| 328 | `as3/Statements/Exceptions/UserDefinedErrorsPackageWithoutMatchingCatch` | 1 | 5.9s |  |
| 329 | `as3/Statements/e12_6_3_12` | 1 | 5.8s |  |
| 330 | `as3/Statements/for-each-in/eforeachin_001` | 8 | 6.2s |  |
| 331 | `as3/Statements/for-each-in/eforeachin_001_500476` | 2 | 5.8s |  |
| 332 | `as3/Statements/for-each-in/eforeachin_002` | 2 | 5.8s |  |
| 333 | `as3/Statements/switch/switch_000` | 3 | 5.8s |  |
| 334 | `as3/Statements/switch/switch_001` | 6 | 5.8s |  |
| 335 | `as3/Statements/switch/switch_002` | 5 | 5.8s |  |
| 336 | `as3/Statements/switch/switch_003` | 6 | 5.8s |  |
| 337 | `as3/String/localeCompare_585791/v12` | 8 | 5.8s |  |
| 338 | `as3/Types/Conversions/ExplicitConversions` | 54 | 6.1s |  |
| 339 | `as3/Types/Conversions/ImplicitConversions1_23` | 6 | 5.8s |  |
| 340 | `as3/Types/Conversions/ImplicitConversionsFalse` | 10 | 6.0s |  |
| 341 | `as3/Types/Conversions/ImplicitConversionsNaN` | 6 | 5.8s |  |
| 342 | `as3/Types/Conversions/ImplicitConversionsNeg1_23` | 10 | 5.9s |  |
| 343 | `as3/Types/Conversions/ImplicitConversionsNull` | 10 | 6.0s |  |
| 344 | `as3/Types/Conversions/ImplicitConversionsString` | 20 | 6.2s |  |
| 345 | `as3/Types/Conversions/ImplicitConversionsTrue` | 10 | 6.0s |  |
| 346 | `as3/Types/Conversions/ImplicitConversionsUndefined` | 11 | 6.0s |  |
| 347 | `as3/Types/Int/intConstructor` | 12 | 5.9s |  |
| 348 | `as3/Types/Int/intIs` | 12 | 5.8s |  |
| 349 | `as3/Types/Int/intType` | 2 | 5.9s |  |
| 350 | `as3/Types/Int/signed_unsigned` | 6 | 5.7s |  |
| 351 | `as3/Types/Int/wraparound` | 16 | 3.1s |  |
| 352 | `as3/Types/Number/visibility/v15` | 34 | 6.2s |  |
| 353 | `as3/Types/uint/UintFunctionArg` | 17 | 6.4s |  |
| 354 | `as3/Types/uint/UintHex` | 1 | 6.0s |  |
| 355 | `as3/Types/uint/UintIs` | 12 | 6.1s |  |
| 356 | `as3/Types/uint/UintPublicClassMethodArg` | 24 | 6.5s |  |
| 357 | `as3/Types/uint/UintType` | 1 | 6.1s |  |
| 358 | `as3/Types/uint/UintVarAsClassProp` | 1 | 6.0s |  |
| 359 | `as3/Types/uint/UintVarOperationInFunc` | 1 | 6.0s |  |
| 360 | `as3/Types/uint/UintVarOperationInFuncRet` | 1 | 6.0s |  |
| 361 | `as3/Types/uint/UintVarOperations` | 17 | 6.4s |  |
| 362 | `as3/Vector/Vector_double_methods` | 11 | 6.3s |  |
| 363 | `as3/Vector/Vector_object_methods` | 12 | 6.2s |  |
| 364 | `as3/Vector/Vector_uint_methods` | 2 | 5.9s |  |
| 365 | `as3/Vector/bug504525/v10` | 1 | 5.8s |  |
| 366 | `as3/Vector/bug504525/v11` | 1 | 5.8s |  |
| 367 | `as3/Vector/bug_683507` | 1 | 6.0s |  |
| 368 | `as3/Vector/concat_with_initializers` | 4 | 6.0s |  |
| 369 | `as3/Vector/constructor` | 18 | 6.3s |  |
| 370 | `as3/Vector/every` | 14 | 6.3s |  |
| 371 | `as3/Vector/every_initializers` | 5 | 5.8s |  |
| 372 | `as3/Vector/fixed_length` | 4 | 6.0s |  |
| 373 | `as3/Vector/get` | 7 | 5.9s |  |
| 374 | `as3/Vector/in` | 10 | 5.9s |  |
| 375 | `as3/Vector/in_initializers` | 10 | 6.0s |  |
| 376 | `as3/Vector/indexof` | 7 | 6.0s |  |
| 377 | `as3/Vector/indexof_initializers` | 7 | 6.0s |  |
| 378 | `as3/Vector/initializer_ws` | 2 | 5.8s |  |
| 379 | `as3/Vector/insert_remove` | 542 | 6.3s |  |
| 380 | `as3/Vector/interface_method_return_type` | 5 | 6.5s |  |
| 381 | `as3/Vector/join` | 4 | 5.8s |  |
| 382 | `as3/Vector/join_initializers` | 4 | 6.4s |  |
| 383 | `as3/Vector/lastindexof` | 5 | 5.9s |  |
| 384 | `as3/Vector/lastindexof_initializers` | 7 | 5.9s |  |
| 385 | `as3/Vector/length` | 9 | 6.0s |  |
| 386 | `as3/Vector/length_initializers` | 3 | 5.8s |  |
| 387 | `as3/Vector/nested_initializers` | 5 | 5.9s |  |
| 388 | `as3/Vector/optimization_tests` | 14 | 7.0s |  |
| 389 | `as3/Vector/pop` | 12 | 6.2s |  |
| 390 | `as3/Vector/push` | 12 | 6.4s |  |
| 391 | `as3/Vector/put` | 8 | 6.1s |  |
| 392 | `as3/Vector/reverse` | 5 | 5.9s |  |
| 393 | `as3/Vector/reverse_initializers` | 4 | 5.8s |  |
| 394 | `as3/Vector/shift` | 12 | 6.2s |  |
| 395 | `as3/Vector/slice` | 1 | 5.7s |  |
| 396 | `as3/Vector/slice_initializers` | 5 | 5.8s |  |
| 397 | `as3/Vector/sort` | 9 | 6.3s |  |
| 398 | `as3/Vector/sort_initializers` | 1 | 5.9s |  |
| 399 | `as3/Vector/specialized_at_runtime` | 3 | 6.2s |  |
| 400 | `as3/Vector/splice` | 4 | 6.0s |  |
| 401 | `as3/Vector/static_initializer` | 4 | 5.8s |  |
| 402 | `as3/Vector/tostring` | 7 | 5.9s |  |
| 403 | `as3/Vector/tostring_initializer` | 5 | 6.0s |  |
| 404 | `as3/Vector/typechecking` | 10 | 6.2s |  |
| 405 | `as3/Vector/unshift` | 7 | 6.2s |  |
| 406 | `ecma3/Array/bug_630945` | 6 | 6.0s |  |
| 407 | `ecma3/Array/e15_4_1_2` | 16 | 6.3s |  |
| 408 | `ecma3/Array/e15_4_1_3` | 4 | 6.2s |  |
| 409 | `ecma3/Array/e15_4_2` | 9 | 6.1s |  |
| 410 | `ecma3/Array/e15_4_2_1_1` | 7 | 6.1s |  |
| 411 | `ecma3/Array/e15_4_2_1_2` | 1025 | 6.1s |  |
| 412 | `ecma3/Array/e15_4_2_2_1` | 17 | 6.2s |  |
| 413 | `ecma3/Array/e15_4_2_2_2` | 8 | 6.2s |  |
| 414 | `ecma3/Array/e15_4_3` | 1 | 6.2s |  |
| 415 | `ecma3/Array/e15_4_4_1` | 1 | 6.1s |  |
| 416 | `ecma3/Array/e15_4_4_11` | 16 | 6.1s |  |
| 417 | `ecma3/Array/e15_4_4_12` | 4 | 6.0s |  |
| 418 | `ecma3/Array/e15_4_4_2` | 13 | 6.2s |  |
| 419 | `ecma3/Array/e15_4_4_3_1` | 1 | 6.1s |  |
| 420 | `ecma3/Array/e15_4_4_4_001` | 9 | 6.2s |  |
| 421 | `ecma3/Array/e15_4_4_5_1` | 53 | 6.2s |  |
| 422 | `ecma3/Array/e15_4_4_5_2` | 53 | 6.2s |  |
| 423 | `ecma3/Array/e15_4_4_6` | 5 | 6.0s |  |
| 424 | `ecma3/Array/e15_4_4_6_1` | 1 | 5.9s |  |
| 425 | `ecma3/Array/e15_4_4_7` | 6 | 6.0s |  |
| 426 | `ecma3/Array/e15_4_4_8` | 4 | 5.9s |  |
| 427 | `ecma3/Array/e15_4_4_9` | 8 | 6.0s |  |
| 428 | `ecma3/Array/e15_4_4_9_1` | 1 | 2.7s |  |
| 429 | `ecma3/Array/e15_4_5_1_1` | 27 | 6.5s |  |
| 430 | `ecma3/Array/e15_4_5_1_2` | 13 | 6.1s |  |
| 431 | `ecma3/Array/e15_4_5_2_1` | 6 | 6.0s |  |
| 432 | `ecma3/Array/e15_4_5_2_2` | 11 | 6.0s |  |
| 433 | `ecma3/Array/e15_4__1` | 12 | 6.1s |  |
| 434 | `ecma3/Array/eregress_130451` | 7 | 6.1s |  |
| 435 | `ecma3/Array/general1` | 6 | 6.0s |  |
| 436 | `ecma3/Array/general2` | 2 | 6.0s |  |
| 437 | `ecma3/Array/general3` | 4 | 3.2s |  |
| 438 | `ecma3/Array/slice` | 2 | 6.2s |  |
| 439 | `ecma3/Array/sortOn` | 32 | 6.2s |  |
| 440 | `ecma3/Array/sparseArray` | 15 | 6.3s |  |
| 441 | `ecma3/Array/splice1` | 2 | 6.2s |  |
| 442 | `ecma3/Array/splice2` | 2 | 6.2s |  |
| 443 | `ecma3/Boolean/e15_6_1` | 20 | 6.1s |  |
| 444 | `ecma3/Boolean/e15_6_2` | 57 | 6.5s |  |
| 445 | `ecma3/Boolean/e15_6_3_1_1` | 1 | 6.0s |  |
| 446 | `ecma3/Boolean/e15_6_3_1_4` | 2 | 5.9s |  |
| 447 | `ecma3/Boolean/e15_6_3_1_5` | 1 | 5.8s |  |
| 448 | `ecma3/Boolean/e15_6_4_1` | 1 | 5.8s |  |
| 449 | `ecma3/Boolean/e15_6_4_2_1` | 24 | 5.9s |  |
| 450 | `ecma3/Boolean/e15_6_4_2_2` | 3 | 5.7s |  |
| 451 | `ecma3/Boolean/e15_6_4_2_3` | 2 | 5.8s |  |
| 452 | `ecma3/Boolean/e15_6_4_3` | 22 | 5.9s |  |
| 453 | `ecma3/Boolean/e15_6_4_3_1` | 22 | 5.4s |  |
| 454 | `ecma3/Boolean/e15_6_4_3_2` | 3 | 5.8s |  |
| 455 | `ecma3/Boolean/e15_6_4_3_3` | 2 | 5.8s |  |
| 456 | `ecma3/Boolean/ecma4_sealedtype_1_rt` | 1 | 5.8s |  |
| 457 | `ecma3/Boolean/ecma4_sealedtype_2_rt` | 1 | 5.8s |  |
| 458 | `ecma3/Boolean/ecma4_sealedtype_3_rt` | 1 | 5.8s |  |
| 459 | `ecma3/Boolean/ecma4_sealedtype_4_rt` | 1 | 5.8s |  |
| 460 | `ecma3/Boolean/ecma4_sealedtype_5_rt` | 1 | 5.8s |  |
| 461 | `ecma3/Boolean/ecma4_st_valueOf_1_rt` | 2 | 5.9s |  |
| 462 | `ecma3/Boolean/ecma4_st_valueOf_2_rt` | 2 | 5.9s |  |
| 463 | `ecma3/Boolean/ecma4_st_valueOf_3_rt` | 1 | 5.8s |  |
| 464 | `ecma3/Boolean/ecma4_st_valueOf_4_rt` | 1 | 6.0s |  |
| 465 | `ecma3/Boolean/ecma4_st_valueOf_5_rt` | 1 | 6.0s |  |
| 466 | `ecma3/ErrorObject/e15_11_1` | 42 | 5.2s |  |
| 467 | `ecma3/ErrorObject/e15_11_2_1` | 30 | 4.8s |  |
| 468 | `ecma3/Exceptions/binding_001` | 2 | 2.3s |  |
| 469 | `ecma3/Exceptions/boolean_001_rt` | 6 | 4.9s |  |
| 470 | `ecma3/Exceptions/boolean_002_rt` | 6 | 5.0s |  |
| 471 | `ecma3/Exceptions/date_001_rt` | 1 | 4.7s |  |
| 472 | `ecma3/Exceptions/date_003_rt` | 1 | 4.6s |  |
| 473 | `ecma3/Exceptions/e15_11_4_4_1` | 9 | 4.9s |  |
| 474 | `ecma3/Exceptions/exception_003_rt` | 1 | 4.7s |  |
| 475 | `ecma3/Exceptions/exception_004_rt` | 1 | 4.7s |  |
| 476 | `ecma3/Exceptions/exception_005_rt` | 1 | 4.7s |  |
| 477 | `ecma3/Exceptions/exception_006_rt` | 1 | 4.8s |  |
| 478 | `ecma3/Exceptions/exception_007_rt` | 1 | 5.0s |  |
| 479 | `ecma3/Exceptions/exception_009` | 1 | 4.8s |  |
| 480 | `ecma3/Exceptions/exception_010_rt` | 1 | 4.7s |  |
| 481 | `ecma3/Exceptions/exception_014_rt` | 2 | 4.7s |  |
| 482 | `ecma3/Exceptions/expression_002_rt` | 1 | 4.7s |  |
| 483 | `ecma3/Exceptions/expression_003_rt` | 1 | 5.2s |  |
| 484 | `ecma3/Exceptions/expression_004_rt` | 1 | 5.0s |  |
| 485 | `ecma3/Exceptions/expression_006_rt` | 1 | 5.7s |  |
| 486 | `ecma3/Exceptions/expression_007_rt` | 1 | 5.4s |  |
| 487 | `ecma3/Exceptions/expression_008_rt` | 1 | 2.2s |  |
| 488 | `ecma3/Exceptions/expression_009_rt` | 1 | 4.6s |  |
| 489 | `ecma3/Exceptions/expression_010_rt` | 1 | 4.8s |  |
| 490 | `ecma3/Exceptions/expression_011_rt` | 1 | 5.8s |  |
| 491 | `ecma3/Exceptions/expression_012_rt` | 1 | 5.8s |  |
| 492 | `ecma3/Exceptions/expression_013_rt` | 1 | 5.8s |  |
| 493 | `ecma3/Exceptions/expression_014_rt` | 1 | 5.9s |  |
| 494 | `ecma3/Exceptions/expression_016_rt` | 1 | 5.8s |  |
| 495 | `ecma3/Exceptions/expression_017_rt` | 1 | 5.8s |  |
| 496 | `ecma3/Exceptions/expression_019_rt` | 1 | 5.8s |  |
| 497 | `ecma3/Exceptions/global_001_rt` | 1 | 5.8s |  |
| 498 | `ecma3/Exceptions/global_002_rt` | 1 | 5.8s |  |
| 499 | `ecma3/Exceptions/number_003_rt` | 4 | 6.1s |  |
| 500 | `ecma3/Exceptions/number_004_rt` | 4 | 6.0s |  |
| 501 | `ecma3/Exceptions/regress_58946` | 1 | 5.8s |  |
| 502 | `ecma3/Exceptions/regress_95101` | 2 | 5.9s |  |
| 503 | `ecma3/ExecutionContexts/e10_1_3` | 1 | 5.7s |  |
| 504 | `ecma3/ExecutionContexts/e10_1_3_1` | 8 | 5.9s |  |
| 505 | `ecma3/ExecutionContexts/e10_1_4_1` | 1 | 5.8s |  |
| 506 | `ecma3/ExecutionContexts/e10_1_4_10` | 1 | 5.8s |  |
| 507 | `ecma3/ExecutionContexts/e10_1_4_2` | 1 | 3.0s |  |
| 508 | `ecma3/ExecutionContexts/e10_1_4_8` | 1 | 5.8s |  |
| 509 | `ecma3/ExecutionContexts/e10_1_4_9` | 1 | 5.8s |  |
| 510 | `ecma3/ExecutionContexts/e10_1_5_1` | 1 | 5.9s |  |
| 511 | `ecma3/ExecutionContexts/e10_1_5_2` | 1 | 5.8s |  |
| 512 | `ecma3/ExecutionContexts/e10_1_5_3` | 1 | 5.8s |  |
| 513 | `ecma3/ExecutionContexts/e10_1_5_4` | 1 | 5.8s |  |
| 514 | `ecma3/ExecutionContexts/e10_1_6` | 9 | 5.8s |  |
| 515 | `ecma3/ExecutionContexts/e10_1_8_1` | 7 | 5.8s |  |
| 516 | `ecma3/ExecutionContexts/e10_1_8_2` | 8 | 5.8s |  |
| 517 | `ecma3/ExecutionContexts/e10_2_1` | 1 | 5.8s |  |
| 518 | `ecma3/ExecutionContexts/e10_2_3_1` | 2 | 5.8s |  |
| 519 | `ecma3/ExecutionContexts/e10_2_3_2` | 2 | 5.8s |  |
| 520 | `ecma3/Expressions/StrictEquality_001` | 7 | 5.8s |  |
| 521 | `ecma3/Expressions/e11_10_1` | 31 | 6.2s |  |
| 522 | `ecma3/Expressions/e11_10_2` | 1089 | 6.2s |  |
| 523 | `ecma3/Expressions/e11_10_3` | 1089 | 6.2s |  |
| 524 | `ecma3/Expressions/e11_11` | 62 | 6.2s |  |
| 525 | `ecma3/Expressions/e11_12_1` | 7 | 5.8s |  |
| 526 | `ecma3/Expressions/e11_12_3` | 1 | 5.7s |  |
| 527 | `ecma3/Expressions/e11_12_4` | 1 | 5.8s |  |
| 528 | `ecma3/Expressions/e11_13` | 7 | 5.3s |  |
| 529 | `ecma3/Expressions/e11_13_1` | 1 | 5.8s |  |
| 530 | `ecma3/Expressions/e11_13_2_1` | 30 | 6.4s |  |
| 531 | `ecma3/Expressions/e11_13_2_2` | 31 | 6.4s |  |
| 532 | `ecma3/Expressions/e11_13_2_3` | 40 | 6.6s |  |
| 533 | `ecma3/Expressions/e11_13_2_4` | 26 | 3.4s |  |
| 534 | `ecma3/Expressions/e11_13_2_5` | 26 | 6.3s |  |
| 535 | `ecma3/Expressions/e11_14_1` | 3 | 5.8s |  |
| 536 | `ecma3/Expressions/e11_1_1` | 7 | 5.8s |  |
| 537 | `ecma3/Expressions/e11_1_5` | 20 | 5.8s |  |
| 538 | `ecma3/Expressions/e11_1_6` | 25 | 6.2s |  |
| 539 | `ecma3/Expressions/e11_2_1_2` | 8 | 5.6s |  |
| 540 | `ecma3/Expressions/e11_2_1_3` | 2 | 5.6s |  |
| 541 | `ecma3/Expressions/e11_2_1_4_rt` | 2 | 5.7s |  |
| 542 | `ecma3/Expressions/e11_2_1_5` | 10 | 5.7s |  |
| 543 | `ecma3/Expressions/e11_2_2_11` | 1 | 5.7s |  |
| 544 | `ecma3/Expressions/e11_2_2_12_rt` | 1 | 5.7s |  |
| 545 | `ecma3/Expressions/e11_2_2_1_rt` | 1 | 5.7s |  |
| 546 | `ecma3/Expressions/e11_2_2_2_rt` | 1 | 5.8s |  |
| 547 | `ecma3/Expressions/e11_2_2_3_rt` | 1 | 6.2s |  |
| 548 | `ecma3/Expressions/e11_2_2_4_rt` | 1 | 2.9s |  |
| 549 | `ecma3/Expressions/e11_2_2_5_rt` | 1 | 2.8s |  |
| 550 | `ecma3/Expressions/e11_2_2_6_rt` | 1 | 2.8s |  |
| 551 | `ecma3/Expressions/e11_2_2_7_rt` | 1 | 5.8s |  |
| 552 | `ecma3/Expressions/e11_2_2_8_rt` | 1 | 6.3s |  |
| 553 | `ecma3/Expressions/e11_2_2_9_rt` | 1 | 5.7s |  |
| 554 | `ecma3/Expressions/e11_2_3_1` | 4 | 5.8s |  |
| 555 | `ecma3/Expressions/e11_2_3_3_rt` | 1 | 5.8s |  |
| 556 | `ecma3/Expressions/e11_2_3_4_rt` | 1 | 5.8s |  |
| 557 | `ecma3/Expressions/e11_2_3_5` | 1 | 5.5s |  |
| 558 | `ecma3/Expressions/e11_3_1` | 58 | 6.3s |  |
| 559 | `ecma3/Expressions/e11_3_2` | 58 | 6.1s |  |
| 560 | `ecma3/Expressions/e11_4_2` | 24 | 5.8s |  |
| 561 | `ecma3/Expressions/e11_4_4` | 52 | 6.2s |  |
| 562 | `ecma3/Expressions/e11_4_5` | 52 | 5.9s |  |
| 563 | `ecma3/Expressions/e11_4_6` | 190 | 7.5s |  |
| 564 | `ecma3/Expressions/e11_4_7` | 146 | 6.9s |  |
| 565 | `ecma3/Expressions/e11_4_8` | 70 | 5.9s |  |
| 566 | `ecma3/Expressions/e11_4_9` | 27 | 5.7s |  |
| 567 | `ecma3/Expressions/e11_5_1` | 47 | 6.0s |  |
| 568 | `ecma3/Expressions/e11_5_2` | 58 | 6.2s |  |
| 569 | `ecma3/Expressions/e11_5_3` | 70 | 6.2s |  |
| 570 | `ecma3/Expressions/e11_6_1_1` | 12 | 5.7s |  |
| 571 | `ecma3/Expressions/e11_6_1_2` | 13 | 6.2s |  |
| 572 | `ecma3/Expressions/e11_6_2_1` | 18 | 5.9s |  |
| 573 | `ecma3/Expressions/e11_6_3` | 34 | 6.0s |  |
| 574 | `ecma3/Expressions/e11_7_1` | 1089 | 6.2s |  |
| 575 | `ecma3/Expressions/e11_7_2` | 2178 | 6.2s |  |
| 576 | `ecma3/Expressions/e11_7_3` | 1089 | 6.1s |  |
| 577 | `ecma3/Expressions/e11_8_1` | 53 | 6.3s |  |
| 578 | `ecma3/Expressions/e11_8_2` | 52 | 6.2s |  |
| 579 | `ecma3/Expressions/e11_8_3` | 56 | 6.7s |  |
| 580 | `ecma3/Expressions/e11_8_4` | 56 | 6.2s |  |
| 581 | `ecma3/Expressions/e11_8_7` | 29 | 6.1s |  |
| 582 | `ecma3/Expressions/e11_9_1` | 47 | 6.2s |  |
| 583 | `ecma3/Expressions/e11_9_2` | 47 | 6.3s |  |
| 584 | `ecma3/Expressions/e11_9_3` | 47 | 6.2s |  |
| 585 | `ecma3/Expressions/e11_9_6_1` | 6 | 6.1s |  |
| 586 | `ecma3/Expressions/instanceof_001` | 14 | 6.2s |  |
| 587 | `ecma3/Expressions/instanceof_002` | 6 | 6.1s |  |
| 588 | `ecma3/Expressions/instanceof_003_rt` | 30 | 6.2s |  |
| 589 | `ecma3/Expressions/instanceof_004_rt` | 1 | 6.0s |  |
| 590 | `ecma3/Expressions/instanceof_006` | 1 | 6.1s |  |
| 591 | `ecma3/Function/apply_001` | 4 | 6.1s |  |
| 592 | `ecma3/Function/call_001_rt` | 1 | 6.1s |  |
| 593 | `ecma3/Function/e15_3_FPQA` | 2 | 6.0s |  |
| 594 | `ecma3/Function/function` | 2 | 6.0s |  |
| 595 | `ecma3/Function/regress_104584` | 3 | 3.1s |  |
| 596 | `ecma3/Function/regress_137181` | 2 | 6.0s |  |
| 597 | `ecma3/Function/regress_49286` | 2 | 6.0s |  |
| 598 | `ecma3/Function/regress_58274_rt` | 7 | 6.1s |  |
| 599 | `ecma3/Function/regress_97921` | 4 | 6.1s |  |
| 600 | `ecma3/Function/scope_001_rt` | 8 | 6.1s |  |
| 601 | `ecma3/Function/scope_002` | 8 | 6.1s |  |
| 602 | `ecma3/FunctionObjects/e15_3_3_1_1` | 1 | 6.0s |  |
| 603 | `ecma3/FunctionObjects/e15_3_3_1_2` | 1 | 6.0s |  |
| 604 | `ecma3/FunctionObjects/e15_3_3_1_4` | 1 | 6.0s |  |
| 605 | `ecma3/FunctionObjects/e15_3_4_1` | 1 | 6.0s |  |
| 606 | `ecma3/FunctionObjects/e15_3_4_2` | 4 | 6.0s |  |
| 607 | `ecma3/FunctionObjects/eapply_001_rt` | 4 | 6.0s |  |
| 608 | `ecma3/GlobalObject/e15_1_1_1` | 3 | 6.0s |  |
| 609 | `ecma3/GlobalObject/e15_1_1_2` | 3 | 6.1s |  |
| 610 | `ecma3/GlobalObject/e15_1_1_n` | 1 | 6.0s |  |
| 611 | `ecma3/GlobalObject/e15_1_2_3_2` | 153 | 7.7s |  |
| 612 | `ecma3/GlobalObject/e15_1_2_5_2` | 85 | 5.5s |  |
| 613 | `ecma3/GlobalObject/e15_1_2_5_3` | 514 | 5.7s |  |
| 614 | `ecma3/GlobalObject/e15_1_2_n` | 1 | 5.3s |  |
| 615 | `ecma3/GlobalObject/undefined` | 3 | 5.3s |  |
| 616 | `ecma3/JSON/Callbacks` | 7 | 5.5s |  |
| 617 | `ecma3/JSON/Invalid` | 40 | 6.7s |  |
| 618 | `ecma3/JSON/LargeString` | 1 | 5.5s |  |
| 619 | `ecma3/JSON/Strings` | 21 | 5.5s |  |
| 620 | `ecma3/Number/e15_7_3_1_2` | 4 | 5.5s |  |
| 621 | `ecma3/Number/e15_7_3_1_3` | 1 | 5.4s |  |
| 622 | `ecma3/Number/e15_7_3_2_1` | 1 | 5.4s |  |
| 623 | `ecma3/Number/e15_7_3_2_4` | 1 | 5.1s |  |
| 624 | `ecma3/Number/e15_7_3_3_1` | 1 | 2.7s |  |
| 625 | `ecma3/Number/e15_7_3_3_4` | 1 | 2.2s |  |
| 626 | `ecma3/Number/e15_7_3_4_1` | 1 | 5.5s |  |
| 627 | `ecma3/Number/e15_7_3_4_4` | 1 | 5.0s |  |
| 628 | `ecma3/Number/e15_7_3_5_1` | 1 | 5.4s |  |
| 629 | `ecma3/Number/e15_7_3_5_4` | 1 | 5.1s |  |
| 630 | `ecma3/Number/e15_7_3_6_1` | 1 | 2.6s |  |
| 631 | `ecma3/Number/e15_7_3_6_4` | 1 | 0.8s |  |
| 632 | `ecma3/Number/e15_7_4_1` | 1 | 5.4s |  |
| 633 | `ecma3/Number/e15_7_4_2_3_rt` | 1 | 5.5s |  |
| 634 | `ecma3/Number/e15_7_4_2_5` | 13 | 6.1s |  |
| 635 | `ecma3/Number/e15_7_4_3_2` | 3 | 6.1s |  |
| 636 | `ecma3/Number/e15_7_4_3_3_rt` | 1 | 6.1s |  |
| 637 | `ecma3/Number/ecma4_sealedtype_1_rt` | 1 | 6.0s |  |
| 638 | `ecma3/Number/ecma4_sealedtype_2_rt` | 1 | 5.9s |  |
| 639 | `ecma3/Number/ecma4_sealedtype_3_rt` | 1 | 5.9s |  |
| 640 | `ecma3/Number/ecma4_sealedtype_4_rt` | 2 | 6.0s |  |
| 641 | `ecma3/Number/ecma4_st_valueOf_1_rt` | 1 | 6.0s |  |
| 642 | `ecma3/Number/ecma4_st_valueOf_2_rt` | 1 | 6.0s |  |
| 643 | `ecma3/Number/ecma4_st_valueOf_3_rt` | 1 | 6.0s |  |
| 644 | `ecma3/Number/toLocaleString2_rt` | 1 | 5.9s |  |
| 645 | `ecma3/Number/toLocaleString3_rt` | 1 | 5.9s |  |
| 646 | `ecma3/Number/toLocaleString4_rt` | 1 | 6.0s |  |
| 647 | `ecma3/ObjectObjects/bug129539` | 3 | 5.9s |  |
| 648 | `ecma3/ObjectObjects/class_001` | 10 | 6.0s |  |
| 649 | `ecma3/ObjectObjects/class_002` | 9 | 6.1s |  |
| 650 | `ecma3/ObjectObjects/class_003` | 7 | 6.2s |  |
| 651 | `ecma3/ObjectObjects/class_004` | 7 | 6.1s |  |
| 652 | `ecma3/ObjectObjects/class_005` | 2 | 6.1s |  |
| 653 | `ecma3/ObjectObjects/e15_2_1_1_rt` | 54 | 8.8s |  |
| 654 | `ecma3/ObjectObjects/e15_2_1_2_rt` | 3 | 6.0s |  |
| 655 | `ecma3/ObjectObjects/e15_2_2_1_rt` | 47 | 6.7s |  |
| 656 | `ecma3/ObjectObjects/e15_2_2_2` | 3 | 5.9s |  |
| 657 | `ecma3/ObjectObjects/e15_2_3_1_1` | 1 | 5.8s |  |
| 658 | `ecma3/ObjectObjects/e15_2_3_1_3` | 1 | 5.8s |  |
| 659 | `ecma3/ObjectObjects/e15_2_3_1_4` | 1 | 5.9s |  |
| 660 | `ecma3/ObjectObjects/e15_2_4_1_rt` | 1 | 5.8s |  |
| 661 | `ecma3/ObjectObjects/e15_2_4_3` | 9 | 6.4s |  |
| 662 | `ecma3/ObjectObjects/e8_6_2_6_001` | 1 | 6.0s |  |
| 663 | `ecma3/ObjectObjects/propertyIsEnumerable` | 5 | 5.9s |  |
| 664 | `ecma3/ObjectObjects/regress_72773_rt` | 1 | 6.0s |  |
| 665 | `ecma3/ObjectObjects/regress_79129_001` | 1 | 5.9s |  |
| 666 | `ecma3/Statements/block` | 4 | 6.0s |  |
| 667 | `ecma3/Statements/e12_10_1` | 8 | 6.1s |  |
| 668 | `ecma3/Statements/e12_2_1` | 18 | 6.5s |  |
| 669 | `ecma3/Statements/e12_5_1` | 6 | 6.0s |  |
| 670 | `ecma3/Statements/e12_5_2` | 6 | 6.0s |  |
| 671 | `ecma3/Statements/e12_5_3` | 12 | 6.1s |  |
| 672 | `ecma3/Statements/e12_6_1_1` | 3 | 6.0s |  |
| 673 | `ecma3/Statements/e12_6_2_1` | 1 | 6.0s |  |
| 674 | `ecma3/Statements/e12_6_2_2` | 1 | 5.9s |  |
| 675 | `ecma3/Statements/e12_6_2_3` | 1 | 6.0s |  |
| 676 | `ecma3/Statements/e12_6_2_4` | 1 | 6.0s |  |
| 677 | `ecma3/Statements/e12_6_2_5` | 1 | 6.0s |  |
| 678 | `ecma3/Statements/e12_6_2_6` | 1 | 6.0s |  |
| 679 | `ecma3/Statements/e12_6_2_7` | 1 | 6.0s |  |
| 680 | `ecma3/Statements/e12_6_2_8` | 1 | 6.0s |  |
| 681 | `ecma3/Statements/e12_6_3_1` | 1 | 6.0s |  |
| 682 | `ecma3/Statements/e12_6_3_10` | 2 | 6.0s |  |
| 683 | `ecma3/Statements/e12_6_3_11` | 1 | 6.0s |  |
| 684 | `ecma3/Statements/e12_6_3_19` | 2 | 6.0s |  |
| 685 | `ecma3/Statements/e12_6_3_2` | 1 | 6.0s |  |
| 686 | `ecma3/Statements/e12_6_3_3` | 1 | 6.0s |  |
| 687 | `ecma3/Statements/e12_6_3_4` | 9 | 6.1s |  |
| 688 | `ecma3/Statements/e12_6_3_9_rt` | 1 | 6.0s |  |
| 689 | `ecma3/Statements/e12_9_1` | 5 | 6.0s |  |
| 690 | `ecma3/Statements/edowhile_001` | 4 | 6.0s |  |
| 691 | `ecma3/Statements/edowhile_002` | 12 | 6.0s |  |
| 692 | `ecma3/Statements/edowhile_003` | 10 | 6.0s |  |
| 693 | `ecma3/Statements/edowhile_004` | 12 | 6.0s |  |
| 694 | `ecma3/Statements/edowhile_005` | 3 | 6.0s |  |
| 695 | `ecma3/Statements/edowhile_006` | 8 | 6.0s |  |
| 696 | `ecma3/Statements/edowhile_007` | 36 | 6.1s |  |
| 697 | `ecma3/Statements/eforin_001_500476` | 2 | 6.0s |  |
| 698 | `ecma3/Statements/eif_001` | 1 | 6.0s |  |
| 699 | `ecma3/Statements/elabel_001` | 5 | 5.9s |  |
| 700 | `ecma3/Statements/elabel_002` | 4 | 6.0s |  |
| 701 | `ecma3/Statements/eregress_131348` | 4 | 6.2s |  |
| 702 | `ecma3/Statements/eregress_74474_001` | 3 | 6.1s |  |
| 703 | `ecma3/Statements/eregress_74474_002` | 1 | 65.9s |  |
| 704 | `ecma3/Statements/eregress_74474_003` | 1 | 64.1s |  |
| 705 | `ecma3/Statements/eregress_83532_001` | 1 | 6.0s |  |
| 706 | `ecma3/Statements/eregress_83532_002` | 1 | 6.0s |  |
| 707 | `ecma3/Statements/eswitch_001` | 5 | 6.0s |  |
| 708 | `ecma3/Statements/eswitch_002` | 10 | 6.0s |  |
| 709 | `ecma3/Statements/eswitch_003` | 9 | 3.1s |  |
| 710 | `ecma3/Statements/eswitch_004` | 18 | 6.1s |  |
| 711 | `ecma3/Statements/etry_001` | 12 | 6.1s |  |
| 712 | `ecma3/Statements/etry_003` | 9 | 6.4s |  |
| 713 | `ecma3/Statements/etry_004` | 3 | 6.1s |  |
| 714 | `ecma3/Statements/etry_005` | 3 | 6.1s |  |
| 715 | `ecma3/Statements/etry_006` | 4 | 6.1s |  |
| 716 | `ecma3/Statements/etry_007` | 2 | 6.1s |  |
| 717 | `ecma3/Statements/etry_008` | 6 | 3.0s |  |
| 718 | `ecma3/Statements/etry_009` | 2 | 5.9s |  |
| 719 | `ecma3/Statements/etry_010` | 4 | 5.9s |  |
| 720 | `ecma3/Statements/etry_012` | 9 | 6.2s |  |
| 721 | `ecma3/Statements/ewhile_001` | 1 | 5.7s |  |
| 722 | `ecma3/Statements/ewhile_002` | 8 | 5.8s |  |
| 723 | `ecma3/Statements/ewhile_003` | 10 | 5.7s |  |
| 724 | `ecma3/Statements/ewhile_004` | 13 | 6.0s |  |
| 725 | `ecma3/Statements/expression` | 1 | 5.8s |  |
| 726 | `ecma3/Statements/throw` | 2 | 5.9s |  |
| 727 | `ecma3/String/Split` | 19 | 6.0s |  |
| 728 | `ecma3/String/e15_5_3_1_1` | 2 | 5.8s |  |
| 729 | `ecma3/String/e15_5_3_1_2` | 1 | 5.8s |  |
| 730 | `ecma3/String/e15_5_3_1_4` | 1 | 5.8s |  |
| 731 | `ecma3/String/e15_5_3_2_1` | 116 | 9.9s |  |
| 732 | `ecma3/String/e15_5_3_2_2` | 2 | 5.8s |  |
| 733 | `ecma3/String/e15_5_4_11_2` | 96 | 6.2s |  |
| 734 | `ecma3/String/e15_5_4_11_3` | 240 | 6.3s |  |
| 735 | `ecma3/String/e15_5_4_11_4` | 96 | 6.1s |  |
| 736 | `ecma3/String/e15_5_4_11_6` | 96 | 6.1s |  |
| 737 | `ecma3/String/e15_5_4_12_2` | 1 | 6.3s |  |
| 738 | `ecma3/String/e15_5_4_12_3` | 864 | 6.4s |  |
| 739 | `ecma3/String/e15_5_4_12_4` | 128 | 6.1s |  |
| 740 | `ecma3/String/e15_5_4_12_5` | 96 | 1.8s |  |
| 741 | `ecma3/String/e15_5_4_1_rt` | 2 | 5.9s |  |
| 742 | `ecma3/String/e15_5_4_2_3` | 4 | 5.8s |  |
| 743 | `ecma3/String/e15_5_4_3_2` | 4 | 5.8s |  |
| 744 | `ecma3/String/e15_5_4_3_3_rt` | 1 | 5.8s |  |
| 745 | `ecma3/String/e15_5_4_5_1` | 95 | 5.8s |  |
| 746 | `ecma3/String/e15_5_4_6_1` | 578 | 6.3s |  |
| 747 | `ecma3/String/e15_5_4_7_1` | 654 | 6.4s |  |
| 748 | `ecma3/String/e15_5_4_7_3_rt` | 5 | 6.4s |  |
| 749 | `ecma3/String/e15_5_4_8_3` | 13 | 6.2s |  |
| 750 | `ecma3/String/e15_5_4_8_477132` | 1 | 6.1s |  |
| 751 | `ecma3/String/ematch_001` | 24 | 6.2s |  |
| 752 | `ecma3/String/ematch_002` | 32 | 6.3s |  |
| 753 | `ecma3/String/ematch_003` | 10 | 6.2s |  |
| 754 | `ecma3/String/eregress_104375` | 3 | 6.1s |  |
| 755 | `ecma3/String/eregress_137879` | 7 | 6.0s |  |
| 756 | `ecma3/String/eregress_137890` | 1 | 6.0s |  |
| 757 | `ecma3/String/eregress_83293` | 9 | 6.0s |  |
| 758 | `ecma3/String/ereplace_001` | 15 | 6.2s |  |
| 759 | `ecma3/String/esplit_001` | 18 | 6.1s |  |
| 760 | `ecma3/String/esplit_003` | 86 | 6.2s |  |
| 761 | `ecma3/String/replace_439458` | 5 | 6.0s |  |
| 762 | `ecma3/String/search` | 8 | 6.1s |  |
| 763 | `ecma3/String/split_407156` | 1 | 6.0s |  |
| 764 | `ecma3/String/split_504567` | 1 | 6.0s |  |
| 765 | `ecma3/String/toLocaleLowerCase2` | 96 | 6.5s |  |
| 766 | `ecma3/String/toLocaleLowerCase3` | 240 | 6.5s |  |
| 767 | `ecma3/String/toLocaleLowerCase4` | 96 | 6.3s |  |
| 768 | `ecma3/String/toLocaleLowerCase6` | 96 | 1.8s |  |
| 769 | `ecma3/String/toLocaleUpperCase` | 96 | 6.3s |  |
| 770 | `ecma3/String/toLocaleUpperCase2` | 128 | 6.4s |  |
| 771 | `ecma3/String/toLocaleUpperCase3` | 768 | 6.5s |  |
| 772 | `ecma3/String/toLocaleUpperCase4` | 1 | 6.4s |  |
| 773 | `ecma3/TypeConversion/e9_2_rt` | 36 | 6.3s |  |
| 774 | `ecma3/TypeConversion/e9_3` | 15 | 6.1s |  |
| 775 | `ecma3/TypeConversion/e9_3_1` | 9 | 6.1s |  |
| 776 | `ecma3/TypeConversion/e9_3_1_1` | 189 | 8.6s |  |
| 777 | `ecma3/TypeConversion/e9_3_1_2` | 12 | 6.0s |  |
| 778 | `ecma3/TypeConversion/e9_5_2` | 56 | 6.6s |  |
| 779 | `ecma3/TypeConversion/e9_6` | 34 | 6.3s |  |
| 780 | `ecma3/TypeConversion/e9_7` | 38 | 6.5s |  |
| 781 | `ecma3/TypeConversion/e9_9_1_rt` | 48 | 6.4s |  |
| 782 | `ecma3/Types/e8_1` | 3 | 6.0s |  |
| 783 | `ecma3/Types/e8_2` | 2 | 6.0s |  |
| 784 | `ecma3/Types/e8_3` | 4 | 6.0s |  |
| 785 | `ecma3/Types/e8_4` | 4 | 6.1s |  |
| 786 | `ecma3/Unicode/uc_001` | 4 | 6.2s |  |
| 787 | `ecma3/Unicode/uc_003` | 6 | 6.1s |  |
| 788 | `ecma3/Unicode/uc_004` | 8 | 6.2s |  |
| 789 | `ecma3/Unicode/uc_005` | 10 | 6.4s |  |
| 790 | `ecma3/Unicode/uc_006` | 56 | 6.8s |  |
| 791 | `ecma3/Unicode/ucs4_bug_515947` | 3 | 6.3s |  |
| 792 | `ecma3/instanceof/instanceof_001` | 2 | 6.4s |  |
| 793 | `ecma3/instanceof/instanceof_002` | 5 | 6.4s |  |
| 794 | `ecma3/instanceof/instanceof_003_rt` | 2 | 6.4s |  |
| 795 | `ecma3/instanceof/regress_7635_rt` | 3 | 6.3s |  |
| 796 | `misc/addNull` | 40 | 3.4s |  |
| 797 | `misc/bug_490371` | 2 | 6.2s |  |
| 798 | `misc/bug_521353` | 6 | 6.2s |  |
| 799 | `misc/bug_532806` | 1 | 6.1s |  |
| 800 | `misc/bug_534074` | 1 | 6.1s |  |
| 801 | `misc/bug_547583` | 8 | 6.1s |  |
| 802 | `misc/bug_598322` | 120 | 7.6s |  |
| 803 | `misc/denseArrayDelete` | 1 | 6.0s |  |
| 804 | `misc/getlex_anyname` | 1 | 6.1s |  |
| 805 | `misc/md5_t` | 7 | 6.7s |  |
| 806 | `misc/nsunbox` | 3 | 6.1s |  |
| 807 | `misc/superInit` | 1 | 6.1s |  |
| 808 | `misc/unchecked` | 1 | 6.2s |  |
| 809 | `recursion/xml_functions` | 3 | 6.4s |  |
| 810 | `regress/bug_415080` | 1 | 6.3s |  |
| 811 | `regress/bug_424341` | 1 | 6.3s |  |
| 812 | `regress/bug_458419` | 1 | 5.8s |  |
| 813 | `regress/bug_460872` | 1 | 5.7s |  |
| 814 | `regress/bug_481942` | 1 | 5.7s |  |
| 815 | `regress/bug_492046` | 1 | 5.7s |  |
| 816 | `regress/bug_498979` | 1 | 5.7s |  |
| 817 | `regress/bug_521353` | 49 | 3.0s |  |
| 818 | `regress/bug_526295` | 2 | 5.8s |  |
| 819 | `regress/bug_532791` | 1 | 5.7s |  |
| 820 | `regress/bug_535882` | 1 | 5.7s |  |
| 821 | `regress/bug_547295` | 2 | 5.7s |  |
| 822 | `regress/bug_549389` | 1 | 5.6s |  |
| 823 | `regress/bug_551587` | 6 | 5.8s |  |
| 824 | `regress/bug_555544` | 1 | 5.8s |  |
| 825 | `regress/bug_555705_orig` | 2 | 5.5s |  |
| 826 | `regress/bug_559565` | 1 | 5.7s |  |
| 827 | `regress/bug_561191` | 19 | 5.8s |  |
| 828 | `regress/bug_564839` | 21 | 6.0s |  |
| 829 | `regress/bug_588041` | 1 | 5.7s |  |
| 830 | `regress/bug_593383` | 109 | 7.3s |  |
| 831 | `regress/bug_598683` | 2 | 5.8s |  |
| 832 | `regress/bug_599357` | 53 | 7.1s |  |
| 833 | `regress/bug_615544` | 2 | 5.8s |  |
| 834 | `regress/bug_637809` | 3 | 5.8s |  |
| 835 | `regress/bug_642535` | 8 | 5.8s |  |
| 836 | `regress/bug_643009` | 6 | 5.8s |  |
| 837 | `regress/bug_654761` | 2 | 5.8s |  |
| 838 | `regress/bug_655315` | 2 | 5.8s |  |
| 839 | `regress/bug_663469` | 51 | 5.8s |  |
| 840 | `regress/bug_672012` | 1 | 5.8s |  |
| 841 | `regress/bug_673284` | 1 | 6.0s |  |
| 842 | `regress/bug_700613` | 5 | 5.7s |  |
| 843 | `regress/bug_703238` | 27 | 5.6s |  |
| 844 | `regress/bug_707133` | 2 | 5.8s |  |
| 845 | `regress/bug_723461` | 6 | 5.8s |  |
| 846 | `regress/security/bug_550269` | 2 | 5.7s |  |
| 847 | `regress/security/bug_663469` | 5 | 5.8s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `as3/Expressions/asOperator/asOper` | 2 | 2 | 7.6s |  |
| 2 | `as3/Math/e15_1_2_2` | 1 | 1 | 3.2s |  |
| 3 | `as3/RegExp/replace` | 2 | 3 | 6.0s |  |
| 4 | `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | 1 | 1 | 5.7s |  |
| 5 | `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | 1 | 1 | 5.9s |  |
| 6 | `e4x/XML/bug_564468` | 7 | 7 | 6.1s |  |
| 7 | `e4x/XML/setNotification` | 13 | 13 | 3.4s |  |
| 8 | `ecma3/Array/toLocaleString` | 1 | 1 | 6.2s |  |
| 9 | `ecma3/Date/e15_9_5_10_1` | 33 | 33 | 7.0s |  |
| 10 | `ecma3/Date/e15_9_5_12_1` | 67 | 67 | 7.0s |  |
| 11 | `ecma3/JSON/Classes` | 1 | 3 | 5.7s |  |
| 12 | `ecma3/Number/e15_7_1` | 1 | 1 | 6.0s |  |
| 13 | `ecma3/Number/e15_7_2` | 1 | 1 | 6.4s |  |
| 14 | `ecma3/Number/e15_7_4_7_1` | 9 | 10 | 6.7s |  |
| 15 | `ecma3/Number/toStringLimits` | 1 | 1 | 6.0s |  |
| 16 | `ecma3/Number/tostring_001` | 2 | 2 | 5.8s |  |
| 17 | `ecma3/String/e15_5_1` | 1 | 1 | 6.1s |  |
| 18 | `ecma3/TypeConversion/e9_8_1` | 1 | 1 | 6.2s |  |
| 19 | `ecma3/Types/e8_5` | 3 | 3 | 6.3s |  |
| 20 | `regress/bug_478501` | 1 | 1 | 5.8s |  |
| 21 | `regress/bug_479786` | 1 | 1 | 5.7s |  |
| 22 | `regress/bug_558863_swf10` | 1 | 1 | 5.8s |  |
| 23 | `regress/bug_609416_swf10` | 1 | 1 | 5.8s |  |
| 24 | `regress/bug_638233` | 2 | 2 | 5.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**374 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `ecma3/Array/e15_4_2_1_3` | 99.9% | 1030 | 1031 | 1 |  |
| 2 | `as3/Array/insertremove` | 99.7% | 30766 | 30870 | 104 |  |
| 3 | `ecma3/String/e15_5_4_4_1` | 99.5% | 188 | 189 | 1 |  |
| 4 | `ecma3/GlobalObject/e15_1_2_5_1` | 99.4% | 528 | 531 | 3 |  |
| 5 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321 | 323 | 2 |  |
| 6 | `ecma3/GlobalObject/e15_1_2_2_1` | 99.3% | 274 | 276 | 2 |  |
| 7 | `as3/Vector/vectorIndexRangeExceptions` | 99.2% | 1260 | 1270 | 10 |  |
| 8 | `ecma3/GlobalObject/e15_1_2_3_1` | 98.9% | 184 | 186 | 2 |  |
| 9 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474 | 481 | 7 |  |
| 10 | `e4x/Expressions/e11_5_1` | 98.5% | 65 | 66 | 1 |  |
| 11 | `e4x/XML/e13_4_3_8` | 97.6% | 40 | 41 | 1 |  |
| 12 | `e4x/Expressions/e11_2_1` | 97.5% | 39 | 40 | 1 |  |
| 13 | `e4x/XMLList/e13_5_4_4` | 97.4% | 38 | 39 | 1 |  |
| 14 | `e4x/XMLList/e13_5_2` | 97.3% | 36 | 37 | 1 |  |
| 15 | `e4x/XML/e13_4_2` | 97.2% | 35 | 36 | 1 |  |
| 16 | `ecma3/JSON/e15_12_1` | 97.2% | 35 | 36 | 1 |  |
| 17 | `e4x/XML/e13_4_3` | 97.1% | 34 | 35 | 1 |  |
| 18 | `e4x/Types/e9_1_1_1` | 96.9% | 31 | 32 | 1 |  |
| 19 | `e4x/XML/e13_4_3_7` | 96.8% | 30 | 31 | 1 |  |
| 20 | `e4x/XML/e13_4_4_6` | 96.8% | 30 | 31 | 1 |  |
| 21 | `ecma3/GlobalObject/e15_1_2_6` | 96.8% | 60 | 62 | 2 |  |
| 22 | `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | 96.6% | 28 | 29 | 1 |  |
| 23 | `e4x/XMLList/e13_5_4_13` | 96.4% | 27 | 28 | 1 |  |
| 24 | `e4x/XMLList/e13_5_4_2` | 96.4% | 27 | 28 | 1 |  |
| 25 | `ecma3/GlobalObject/e15_1_2_7` | 96.4% | 53 | 55 | 2 |  |
| 26 | `e4x/XMLList/e13_5_1` | 96.2% | 25 | 26 | 1 |  |
| 27 | `ecma3/Number/e15_7_4_2_4` | 96.1% | 49 | 51 | 2 |  |
| 28 | `e4x/XML/e13_4_4_16` | 96.0% | 24 | 25 | 1 |  |
| 29 | `e4x/QName/e13_3_2` | 95.9% | 47 | 49 | 2 |  |
| 30 | `e4x/Expressions/e11_2_2` | 95.8% | 23 | 24 | 1 |  |
| 31 | `e4x/XMLList/e13_5_4_16` | 95.8% | 23 | 24 | 1 |  |
| 32 | `e4x/Namespace/e13_2_2` | 95.5% | 21 | 22 | 1 |  |
| 33 | `e4x/QName/e13_3_1` | 95.5% | 21 | 22 | 1 |  |
| 34 | `e4x/XML/e13_4_4_24` | 95.5% | 21 | 22 | 1 |  |
| 35 | `e4x/XML/e13_4_4_27` | 95.2% | 20 | 21 | 1 |  |
| 36 | `as3/Vector/initializer_expressions` | 95.1% | 39 | 41 | 2 |  |
| 37 | `e4x/Types/e9_1_1_9` | 95.0% | 19 | 20 | 1 |  |
| 38 | `e4x/XML/e13_4_4_39` | 95.0% | 19 | 20 | 1 |  |
| 39 | `e4x/Expressions/e11_6_1` | 94.7% | 18 | 19 | 1 |  |
| 40 | `e4x/Namespace/e13_2_1` | 94.7% | 18 | 19 | 1 |  |
| 41 | `e4x/Types/e9_2_1_2` | 94.7% | 18 | 19 | 1 |  |
| 42 | `e4x/XML/e13_4_4_29/v10` | 94.7% | 18 | 19 | 1 |  |
| 43 | `e4x/XML/e13_4_4_29/v9` | 94.7% | 18 | 19 | 1 |  |
| 44 | `e4x/XML/e13_4_4_31` | 94.7% | 18 | 19 | 1 |  |
| 45 | `e4x/XML/e13_4_4_4` | 94.7% | 18 | 19 | 1 |  |
| 46 | `e4x/XMLList/e13_5_4_12` | 94.7% | 18 | 19 | 1 |  |
| 47 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89 | 94 | 5 |  |
| 48 | `e4x/Expressions/e11_4_1` | 94.4% | 17 | 18 | 1 |  |
| 49 | `e4x/Namespace/e13_2_5` | 94.4% | 34 | 36 | 2 |  |
| 50 | `e4x/XML/e13_4_1` | 94.4% | 17 | 18 | 1 |  |
| 51 | `ecma3/Expressions/e11_4_1` | 94.4% | 17 | 18 | 1 |  |
| 52 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16 | 17 | 1 |  |
| 53 | `e4x/Expressions/e11_1_5` | 94.1% | 16 | 17 | 1 |  |
| 54 | `e4x/XML/e13_4_4_23` | 94.1% | 16 | 17 | 1 |  |
| 55 | `e4x/XML/e13_4_4_35` | 94.1% | 16 | 17 | 1 |  |
| 56 | `e4x/XML/e13_4_4_38` | 94.1% | 16 | 17 | 1 |  |
| 57 | `ecma3/JSON/e15_12_3` | 93.9% | 31 | 33 | 2 |  |
| 58 | `e4x/XML/e13_4_4_15` | 93.8% | 15 | 16 | 1 |  |
| 59 | `e4x/XML/e13_4_4_18` | 93.8% | 15 | 16 | 1 |  |
| 60 | `e4x/XML/e13_4_4_19` | 93.8% | 15 | 16 | 1 |  |
| 61 | `e4x/XML/e13_4_4_21` | 93.8% | 15 | 16 | 1 |  |
| 62 | `e4x/XML/e13_4_4_3/v10` | 93.8% | 15 | 16 | 1 |  |
| 63 | `e4x/XML/e13_4_4_3/v21` | 93.8% | 15 | 16 | 1 |  |
| 64 | `e4x/XML/e13_4_4_3/v9` | 93.8% | 15 | 16 | 1 |  |
| 65 | `e4x/XMLList/e13_5_4_3` | 93.8% | 15 | 16 | 1 |  |
| 66 | `regress/bug_687838` | 93.7% | 104 | 111 | 7 |  |
| 67 | `e4x/Expressions/e11_2_4` | 93.3% | 14 | 15 | 1 |  |
| 68 | `e4x/Expressions/e11_6_2` | 93.3% | 14 | 15 | 1 |  |
| 69 | `e4x/XML/e13_4_4_12` | 93.3% | 14 | 15 | 1 |  |
| 70 | `e4x/XML/e13_4_4_22` | 93.3% | 14 | 15 | 1 |  |
| 71 | `e4x/XML/e13_4_4_25` | 93.3% | 14 | 15 | 1 |  |
| 72 | `e4x/Statements/e12_2` | 92.9% | 13 | 14 | 1 |  |
| 73 | `e4x/XML/e13_4_4_9` | 92.9% | 13 | 14 | 1 |  |
| 74 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13 | 14 | 1 |  |
| 75 | `as3/Vector/some` | 92.3% | 12 | 13 | 1 |  |
| 76 | `e4x/QName/e13_3_5` | 92.3% | 12 | 13 | 1 |  |
| 77 | `e4x/TypeConversion/e10_2_1_2` | 92.3% | 12 | 13 | 1 |  |
| 78 | `e4x/XMLList/e13_5_4_11` | 92.3% | 12 | 13 | 1 |  |
| 79 | `ecma3/String/e15_5_2` | 92.0% | 69 | 75 | 6 |  |
| 80 | `as3/Vector/map` | 91.7% | 11 | 12 | 1 |  |
| 81 | `e4x/XML/e13_4_4_11` | 91.7% | 11 | 12 | 1 |  |
| 82 | `e4x/XML/e13_4_4_14` | 91.7% | 11 | 12 | 1 |  |
| 83 | `e4x/XML/e13_4_4_34` | 91.7% | 11 | 12 | 1 |  |
| 84 | `e4x/XML/e13_4_4_37` | 91.7% | 11 | 12 | 1 |  |
| 85 | `e4x/XML/e13_4_4_5` | 91.7% | 11 | 12 | 1 |  |
| 86 | `e4x/XMLList/e13_5_4_20` | 91.7% | 11 | 12 | 1 |  |
| 87 | `e4x/XMLList/e13_5_4_21` | 91.7% | 11 | 12 | 1 |  |
| 88 | `as3/ShellClasses/DictionarySubclass` | 90.9% | 20 | 22 | 2 |  |
| 89 | `e4x/Types/e9_1_1_6` | 90.9% | 10 | 11 | 1 |  |
| 90 | `e4x/Types/e9_2_1_1` | 90.9% | 10 | 11 | 1 |  |
| 91 | `e4x/Types/e9_2_1_9` | 90.9% | 10 | 11 | 1 |  |
| 92 | `e4x/XML/e13_4_3_4` | 90.9% | 10 | 11 | 1 |  |
| 93 | `e4x/XML/e13_4_3_9` | 90.9% | 10 | 11 | 1 |  |
| 94 | `e4x/XML/e13_4_4_10` | 90.9% | 10 | 11 | 1 |  |
| 95 | `e4x/XML/e13_4_4_20` | 90.9% | 10 | 11 | 1 |  |
| 96 | `e4x/XML/misc_errors` | 90.9% | 30 | 33 | 3 |  |
| 97 | `e4x/XMLList/e13_5_4_14` | 90.9% | 10 | 11 | 1 |  |
| 98 | `e4x/XMLList/e13_5_4_5` | 90.9% | 10 | 11 | 1 |  |
| 99 | `e4x/XMLList/e13_5_4_8` | 90.9% | 10 | 11 | 1 |  |
| 100 | `ecma3/String/e15_5_4_5_6_rt` | 90.9% | 10 | 11 | 1 |  |
| 101 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28 | 31 | 3 |  |
| 102 | `as3/Vector/concat` | 90.0% | 9 | 10 | 1 |  |
| 103 | `e4x/Expressions/e11_2_3` | 90.0% | 9 | 10 | 1 |  |
| 104 | `e4x/XML/e13_4_3_6` | 90.0% | 9 | 10 | 1 |  |
| 105 | `e4x/XMLList/e13_5_4_9` | 90.0% | 9 | 10 | 1 |  |
| 106 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9 | 10 | 1 |  |
| 107 | `ecma3/ObjectObjects/e15_2_4_2` | 90.0% | 9 | 10 | 1 |  |
| 108 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54 | 60 | 6 |  |
| 109 | `as3/ByteArray/ByteArray` | 89.9% | 382 | 425 | 43 |  |
| 110 | `ecma3/Number/toLocaleString_rt` | 89.6% | 43 | 48 | 5 |  |
| 111 | `e4x/XML/e13_4_4_17` | 89.5% | 17 | 19 | 2 |  |
| 112 | `ecma3/TypeConversion/e9_4_1` | 89.5% | 17 | 19 | 2 |  |
| 113 | `ecma3/TypeConversion/e9_4_2` | 89.5% | 17 | 19 | 2 |  |
| 114 | `ecma3/Expressions/e11_1_4` | 89.3% | 25 | 28 | 3 |  |
| 115 | `as3/Vector/filter` | 88.9% | 8 | 9 | 1 |  |
| 116 | `e4x/TypeConversion/e10_4` | 88.9% | 8 | 9 | 1 |  |
| 117 | `e4x/XML/e13_4_4_32/v10` | 88.9% | 8 | 9 | 1 |  |
| 118 | `ecma3/Number/e15_7_4_2_1_rt` | 88.9% | 8 | 9 | 1 |  |
| 119 | `ecma3/JSON/AS3Types` | 88.5% | 23 | 26 | 3 |  |
| 120 | `as3/Vector/nested` | 87.5% | 7 | 8 | 1 |  |
| 121 | `e4x/Expressions/e11_1_3` | 87.5% | 7 | 8 | 1 |  |
| 122 | `e4x/TypeConversion/e10_4_1` | 87.5% | 7 | 8 | 1 |  |
| 123 | `e4x/XML/e13_4_3_2` | 87.5% | 7 | 8 | 1 |  |
| 124 | `e4x/XML/e13_4_3_3` | 87.5% | 7 | 8 | 1 |  |
| 125 | `ecma3/String/e15_5_4_2_rt` | 87.5% | 7 | 8 | 1 |  |
| 126 | `e4x/Expressions/e11_1_1` | 87.2% | 34 | 39 | 5 |  |
| 127 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 85.7% | 6 | 7 | 1 |  |
| 128 | `as3/Vector/map_initializers` | 85.7% | 6 | 7 | 1 |  |
| 129 | `e4x/Expressions/e11_3_2` | 85.7% | 6 | 7 | 1 |  |
| 130 | `e4x/TypeConversion/e10_3` | 85.7% | 6 | 7 | 1 |  |
| 131 | `e4x/XML/e13_4_4_13` | 85.7% | 6 | 7 | 1 |  |
| 132 | `e4x/XML/e13_4_4_40` | 85.7% | 6 | 7 | 1 |  |
| 133 | `e4x/XML/e13_4_4_7` | 85.7% | 6 | 7 | 1 |  |
| 134 | `e4x/XML/e13_4_4_8` | 85.7% | 6 | 7 | 1 |  |
| 135 | `e4x/XML/kXMLPrefixNotBoundErr` | 85.7% | 6 | 7 | 1 |  |
| 136 | `e4x/XMLList/e13_5_4_10` | 85.7% | 6 | 7 | 1 |  |
| 137 | `ecma3/Number/e15_7_4_3_1_rt` | 85.7% | 6 | 7 | 1 |  |
| 138 | `ecma3/String/e15_5_4_3_1` | 85.7% | 6 | 7 | 1 |  |
| 139 | `ecma3/Types/e8_6_1` | 85.7% | 6 | 7 | 1 |  |
| 140 | `e4x/XML/e13_4_4_28` | 84.6% | 11 | 13 | 2 |  |
| 141 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 83.3% | 5 | 6 | 1 |  |
| 142 | `as3/Vector/foreach` | 83.3% | 5 | 6 | 1 |  |
| 143 | `as3/Vector/some_initializers` | 83.3% | 5 | 6 | 1 |  |
| 144 | `e4x/Expressions/e11_6_3` | 83.3% | 5 | 6 | 1 |  |
| 145 | `e4x/Regress/regress-271545` | 83.3% | 5 | 6 | 1 |  |
| 146 | `e4x/Types/e9_1_1_2` | 83.3% | 5 | 6 | 1 |  |
| 147 | `e4x/XML/e13_4_4_26` | 83.3% | 5 | 6 | 1 |  |
| 148 | `e4x/XML/e13_4_4_33` | 83.3% | 5 | 6 | 1 |  |
| 149 | `e4x/XMLList/e13_5_4_6` | 83.3% | 5 | 6 | 1 |  |
| 150 | `e4x/XMLList/e13_5_4_7` | 83.3% | 5 | 6 | 1 |  |
| 151 | `ecma3/Array/e15_4_4_10` | 83.3% | 5 | 6 | 1 |  |
| 152 | `ecma3/JSON/e15_12_2` | 83.3% | 10 | 12 | 2 |  |
| 153 | `ecma3/String/e15_5_4_2_1` | 83.3% | 5 | 6 | 1 |  |
| 154 | `ecma3/Unicode/u0000_BasicLatin` | 81.0% | 17 | 21 | 4 |  |
| 155 | `as3/Vector/filter_initializers` | 80.0% | 4 | 5 | 1 |  |
| 156 | `as3/Vector/foreach_initializers` | 80.0% | 4 | 5 | 1 |  |
| 157 | `e4x/Expressions/kXMLBadQNameErr` | 80.0% | 4 | 5 | 1 |  |
| 158 | `e4x/Statements/e12_3` | 80.0% | 4 | 5 | 1 |  |
| 159 | `e4x/TypeConversion/e10_1_2` | 80.0% | 4 | 5 | 1 |  |
| 160 | `e4x/TypeConversion/e10_2_1` | 80.0% | 4 | 5 | 1 |  |
| 161 | `e4x/TypeConversion/e10_2_1_1` | 80.0% | 4 | 5 | 1 |  |
| 162 | `e4x/Types/e9_1_1_3` | 80.0% | 4 | 5 | 1 |  |
| 163 | `e4x/XML/e13_4_3_1` | 80.0% | 4 | 5 | 1 |  |
| 164 | `e4x/XML/e13_4_3_5` | 80.0% | 4 | 5 | 1 |  |
| 165 | `e4x/XML/kXMLUnterminatedElementTagErr` | 80.0% | 4 | 5 | 1 |  |
| 166 | `e4x/XMLList/e13_5_3_1` | 80.0% | 4 | 5 | 1 |  |
| 167 | `e4x/XMLList/e13_5_4_17` | 80.0% | 8 | 10 | 2 |  |
| 168 | `e4x/XMLList/e13_5_4_19` | 80.0% | 4 | 5 | 1 |  |
| 169 | `e4x/XMLList/e13_5_4_22` | 80.0% | 4 | 5 | 1 |  |
| 170 | `ecma3/Array/e15_4_2_3` | 80.0% | 4 | 5 | 1 |  |
| 171 | `ecma3/ObjectObjects/toLocaleString_rt` | 80.0% | 4 | 5 | 1 |  |
| 172 | `ecma3/Array/e15_4_1` | 78.6% | 11 | 14 | 3 |  |
| 173 | `e4x/XML/e13_4_4_32/v9` | 77.8% | 7 | 9 | 2 |  |
| 174 | `ecma3/Unicode/u0080_Latin_1Supplement` | 76.2% | 16 | 21 | 5 |  |
| 175 | `ecma3/Unicode/u0100_LatinExtended_A` | 76.2% | 16 | 21 | 5 |  |
| 176 | `ecma3/Unicode/u0180_LatinExtended_B` | 76.2% | 16 | 21 | 5 |  |
| 177 | `ecma3/Unicode/u0250_IPAExtensions` | 76.2% | 16 | 21 | 5 |  |
| 178 | `ecma3/Unicode/u02B0_SpacingModifierLetters` | 76.2% | 16 | 21 | 5 |  |
| 179 | `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | 76.2% | 16 | 21 | 5 |  |
| 180 | `ecma3/Unicode/u0370_GreekandCoptic` | 76.2% | 16 | 21 | 5 |  |
| 181 | `ecma3/Unicode/u0400_Cyrillic` | 76.2% | 32 | 42 | 10 |  |
| 182 | `ecma3/Unicode/u0500_CyrillicSupplementary` | 76.2% | 16 | 21 | 5 |  |
| 183 | `ecma3/Unicode/u0530_Armenian` | 76.2% | 16 | 21 | 5 |  |
| 184 | `ecma3/Unicode/u0590_Hebrew` | 76.2% | 16 | 21 | 5 |  |
| 185 | `ecma3/Unicode/u0600_Arabic` | 76.2% | 32 | 42 | 10 |  |
| 186 | `ecma3/Unicode/u0700_Syriac` | 76.2% | 16 | 21 | 5 |  |
| 187 | `ecma3/Unicode/u0780_Thaana` | 76.2% | 16 | 21 | 5 |  |
| 188 | `ecma3/Unicode/u0900_Devanagari` | 76.2% | 16 | 21 | 5 |  |
| 189 | `ecma3/Unicode/u0980_Bengali` | 76.2% | 16 | 21 | 5 |  |
| 190 | `ecma3/Unicode/u0A00_Gurmukhi` | 76.2% | 16 | 21 | 5 |  |
| 191 | `ecma3/Unicode/u0A80_Gujarati` | 76.2% | 16 | 21 | 5 |  |
| 192 | `ecma3/Unicode/u0B00_Oriya` | 76.2% | 16 | 21 | 5 |  |
| 193 | `ecma3/Unicode/u0B80_Tamil` | 76.2% | 16 | 21 | 5 |  |
| 194 | `ecma3/Unicode/u0C00_Telugu` | 76.2% | 16 | 21 | 5 |  |
| 195 | `ecma3/Unicode/u0C80_Kannada` | 76.2% | 16 | 21 | 5 |  |
| 196 | `ecma3/Unicode/u0D00_Malayalam` | 76.2% | 16 | 21 | 5 |  |
| 197 | `ecma3/Unicode/u0D80_Sinhala` | 76.2% | 16 | 21 | 5 |  |
| 198 | `ecma3/Unicode/u0E00_Thai` | 76.2% | 16 | 21 | 5 |  |
| 199 | `ecma3/Unicode/u0E80_Lao` | 76.2% | 16 | 21 | 5 |  |
| 200 | `ecma3/Unicode/u0F00_Tibetan` | 76.2% | 32 | 42 | 10 |  |
| 201 | `ecma3/Unicode/u1000_Myanmar` | 76.2% | 16 | 21 | 5 |  |
| 202 | `ecma3/Unicode/u10A0_Georgian` | 76.2% | 16 | 21 | 5 |  |
| 203 | `ecma3/Unicode/u1100_HangulJamo` | 76.2% | 32 | 42 | 10 |  |
| 204 | `ecma3/Unicode/u1200_Ethiopic` | 76.2% | 32 | 42 | 10 |  |
| 205 | `ecma3/Unicode/u13A0_Cherokee` | 76.2% | 16 | 21 | 5 |  |
| 206 | `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | 76.2% | 48 | 63 | 15 |  |
| 207 | `ecma3/Unicode/u1680_Ogham` | 76.2% | 16 | 21 | 5 |  |
| 208 | `ecma3/Unicode/u16A0_Runic` | 76.2% | 16 | 21 | 5 |  |
| 209 | `ecma3/Unicode/u1700_Tagalog` | 76.2% | 16 | 21 | 5 |  |
| 210 | `ecma3/Unicode/u1720_Hanunoo` | 76.2% | 16 | 21 | 5 |  |
| 211 | `ecma3/Unicode/u1740_Buhid` | 76.2% | 16 | 21 | 5 |  |
| 212 | `ecma3/Unicode/u1760_Tagbanwa` | 76.2% | 16 | 21 | 5 |  |
| 213 | `ecma3/Unicode/u1780_Khmer` | 76.2% | 16 | 21 | 5 |  |
| 214 | `ecma3/Unicode/u1800_Mongolian` | 76.2% | 16 | 21 | 5 |  |
| 215 | `ecma3/Unicode/u1E00_LatinExtendedAdditional` | 76.2% | 32 | 42 | 10 |  |
| 216 | `ecma3/Unicode/u1F00_GreekExtended` | 76.2% | 32 | 42 | 10 |  |
| 217 | `ecma3/Unicode/u2000_GeneralPunctuation` | 76.2% | 16 | 21 | 5 |  |
| 218 | `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | 76.2% | 16 | 21 | 5 |  |
| 219 | `ecma3/Unicode/u20A0_CurrencySymbols` | 76.2% | 16 | 21 | 5 |  |
| 220 | `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | 76.2% | 16 | 21 | 5 |  |
| 221 | `ecma3/Unicode/u2100_LetterlikeSymbols` | 76.2% | 16 | 21 | 5 |  |
| 222 | `ecma3/Unicode/u2150_NumberForms` | 76.2% | 16 | 21 | 5 |  |
| 223 | `ecma3/Unicode/u2190_Arrows` | 76.2% | 16 | 21 | 5 |  |
| 224 | `ecma3/Unicode/u2200_MathematicalOperators` | 76.2% | 32 | 42 | 10 |  |
| 225 | `ecma3/Unicode/u2300_MiscellaneousTechnical` | 76.2% | 32 | 42 | 10 |  |
| 226 | `ecma3/Unicode/u2400_ControlPictures` | 76.2% | 16 | 21 | 5 |  |
| 227 | `ecma3/Unicode/u2440_OpticalCharacterRecognition` | 76.2% | 16 | 21 | 5 |  |
| 228 | `ecma3/Unicode/u2460_EnclosedAlphanumerics` | 76.2% | 16 | 21 | 5 |  |
| 229 | `ecma3/Unicode/u2500_BoxDrawing` | 76.2% | 16 | 21 | 5 |  |
| 230 | `ecma3/Unicode/u2580_BlockElements` | 76.2% | 16 | 21 | 5 |  |
| 231 | `ecma3/Unicode/u25A0_GeometricShapes` | 76.2% | 16 | 21 | 5 |  |
| 232 | `ecma3/Unicode/u2600_MiscellaneousSymbols` | 76.2% | 32 | 42 | 10 |  |
| 233 | `ecma3/Unicode/u2700_Dingbats` | 76.2% | 16 | 21 | 5 |  |
| 234 | `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | 76.2% | 16 | 21 | 5 |  |
| 235 | `ecma3/Unicode/u27F0_SupplementalArrows_A` | 76.2% | 16 | 21 | 5 |  |
| 236 | `ecma3/Unicode/u2800_BraillePatterns` | 76.2% | 32 | 42 | 10 |  |
| 237 | `ecma3/Unicode/u2900_SupplementalArrows_B` | 76.2% | 16 | 21 | 5 |  |
| 238 | `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | 76.2% | 16 | 21 | 5 |  |
| 239 | `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | 76.2% | 32 | 42 | 10 |  |
| 240 | `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | 76.2% | 16 | 21 | 5 |  |
| 241 | `ecma3/Unicode/u2F00_KangxiRadicals` | 76.2% | 16 | 21 | 5 |  |
| 242 | `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | 76.2% | 16 | 21 | 5 |  |
| 243 | `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | 76.2% | 16 | 21 | 5 |  |
| 244 | `ecma3/Unicode/u3040_Hiragana` | 76.2% | 16 | 21 | 5 |  |
| 245 | `ecma3/Unicode/u30A0_Katakana` | 76.2% | 16 | 21 | 5 |  |
| 246 | `ecma3/Unicode/u3100_Bopomofo` | 76.2% | 16 | 21 | 5 |  |
| 247 | `ecma3/Unicode/u3130_HangulCompatibilityJamo` | 76.2% | 16 | 21 | 5 |  |
| 248 | `ecma3/Unicode/u3190_Kanbun` | 76.2% | 16 | 21 | 5 |  |
| 249 | `ecma3/Unicode/u31A0_BopomofoExtended` | 76.2% | 16 | 21 | 5 |  |
| 250 | `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | 76.2% | 16 | 21 | 5 |  |
| 251 | `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | 76.2% | 32 | 42 | 10 |  |
| 252 | `ecma3/Unicode/u3300_CJKCompatibility` | 76.2% | 32 | 42 | 10 |  |
| 253 | `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | 76.2% | 432 | 567 | 135 |  |
| 254 | `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | 76.2% | 48 | 63 | 15 |  |
| 255 | `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | 76.2% | 272 | 357 | 85 |  |
| 256 | `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | 76.2% | 272 | 357 | 85 |  |
| 257 | `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | 76.2% | 272 | 357 | 85 |  |
| 258 | `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | 76.2% | 272 | 357 | 85 |  |
| 259 | `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | 76.2% | 272 | 357 | 85 |  |
| 260 | `ecma3/Unicode/uA000_YiSyllables` | 76.2% | 80 | 105 | 25 |  |
| 261 | `ecma3/Unicode/uA490_YiRadicals` | 76.2% | 16 | 21 | 5 |  |
| 262 | `ecma3/Unicode/uAC00_HangulSyllables` | 76.2% | 720 | 945 | 225 |  |
| 263 | `ecma3/Unicode/uE000_PrivateUseArea` | 76.2% | 416 | 546 | 130 |  |
| 264 | `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | 76.2% | 48 | 63 | 15 |  |
| 265 | `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | 76.2% | 16 | 21 | 5 |  |
| 266 | `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | 76.2% | 48 | 63 | 15 |  |
| 267 | `ecma3/Unicode/uFE00_VariationSelectors` | 76.2% | 16 | 21 | 5 |  |
| 268 | `ecma3/Unicode/uFE20_CombiningHalfMarks` | 76.2% | 16 | 21 | 5 |  |
| 269 | `ecma3/Unicode/uFE30_CJKCompatibilityForms` | 76.2% | 16 | 21 | 5 |  |
| 270 | `ecma3/Unicode/uFE50_SmallFormVariants` | 76.2% | 16 | 21 | 5 |  |
| 271 | `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | 76.2% | 16 | 21 | 5 |  |
| 272 | `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | 76.2% | 16 | 21 | 5 |  |
| 273 | `ecma3/Unicode/uFFF0_Specials` | 76.2% | 16 | 21 | 5 |  |
| 274 | `e4x/Namespace/e13_2_4_2` | 75.0% | 3 | 4 | 1 |  |
| 275 | `e4x/QName/e13_3_4_2` | 75.0% | 3 | 4 | 1 |  |
| 276 | `e4x/Regress/regress-278112` | 75.0% | 3 | 4 | 1 |  |
| 277 | `e4x/XML/e13_4_4_36` | 75.0% | 12 | 16 | 4 |  |
| 278 | `ecma3/Array/e15_4_3_1_2` | 75.0% | 3 | 4 | 1 |  |
| 279 | `ecma3/Boolean/e15_6_4__1` | 75.0% | 3 | 4 | 1 |  |
| 280 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 75.0% | 3 | 4 | 1 |  |
| 281 | `ecma3/FunctionObjects/e15_3_4_rt` | 75.0% | 3 | 4 | 1 |  |
| 282 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 75.0% | 3 | 4 | 1 |  |
| 283 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6 | 8 | 2 |  |
| 284 | `ecma3/Statements/eforin_001` | 75.0% | 12 | 16 | 4 |  |
| 285 | `ecma3/String/localeCompare_rt` | 75.0% | 3 | 4 | 1 |  |
| 286 | `ecma3/String/e15_5_5_1` | 70.0% | 7 | 10 | 3 |  |
| 287 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2 | 3 | 1 |  |
| 288 | `e4x/Namespace/e13_2_3_1` | 66.7% | 2 | 3 | 1 |  |
| 289 | `e4x/Namespace/e13_2_4_1` | 66.7% | 2 | 3 | 1 |  |
| 290 | `e4x/QName/e13_3_3_1` | 66.7% | 2 | 3 | 1 |  |
| 291 | `e4x/TypeConversion/bug153363` | 66.7% | 2 | 3 | 1 |  |
| 292 | `e4x/TypeConversion/bug153363_2` | 66.7% | 2 | 3 | 1 |  |
| 293 | `e4x/TypeConversion/e10_1_1` | 66.7% | 2 | 3 | 1 |  |
| 294 | `e4x/XML/e13_4_4_1` | 66.7% | 2 | 3 | 1 |  |
| 295 | `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | 66.7% | 2 | 3 | 1 |  |
| 296 | `e4x/XML/kXMLMarkupMustBeWellFormedErr` | 66.7% | 2 | 3 | 1 |  |
| 297 | `e4x/XMLList/e13_5_4_1` | 66.7% | 2 | 3 | 1 |  |
| 298 | `e4x/XMLList/e13_5_4_15` | 66.7% | 2 | 3 | 1 |  |
| 299 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 66.7% | 4 | 6 | 2 |  |
| 300 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 66.7% | 2 | 3 | 1 |  |
| 301 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 66.7% | 2 | 3 | 1 |  |
| 302 | `ecma3/Number/e15_7_4__1_rt` | 66.7% | 2 | 3 | 1 |  |
| 303 | `ecma3/Number/e15_7_4_rt` | 66.7% | 2 | 3 | 1 |  |
| 304 | `ecma3/Unicode/utf8count` | 66.7% | 2 | 3 | 1 |  |
| 305 | `regress/bug_550958` | 66.7% | 2 | 3 | 1 |  |
| 306 | `ecma3/JSON/adhoc` | 65.0% | 26 | 40 | 14 |  |
| 307 | `e4x/XML/e13_4_4_30` | 63.6% | 7 | 11 | 4 |  |
| 308 | `ecma3/Expressions/e11_2_1_1` | 63.4% | 161 | 254 | 93 |  |
| 309 | `regress/bug_420755` | 63.0% | 17 | 27 | 10 |  |
| 310 | `regress/bug_654807_swf13` | 60.0% | 102 | 170 | 68 |  |
| 311 | `e4x/Statements/e12_1` | 58.8% | 10 | 17 | 7 |  |
| 312 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 58.3% | 21 | 36 | 15 |  |
| 313 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 53.8% | 7 | 13 | 6 |  |
| 314 | `ecma3/String/e15_5_4_4_4_rt` | 53.8% | 28 | 52 | 24 |  |
| 315 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 316 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 53.1% | 17 | 32 | 15 |  |
| 317 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 318 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 319 | `as3/Definitions/Classes/ClassDef/InternalClass` | 53.1% | 17 | 32 | 15 |  |
| 320 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 53.1% | 17 | 32 | 15 |  |
| 321 | `e4x/Expressions/e11_1_2` | 52.2% | 12 | 23 | 11 |  |
| 322 | `as3/Types/Int/intMaxValue` | 50.0% | 2 | 4 | 2 |  |
| 323 | `as3/Types/Int/intMinValue` | 50.0% | 2 | 4 | 2 |  |
| 324 | `as3/Vector/bug_678952` | 50.0% | 1 | 2 | 1 |  |
| 325 | `e4x/QName/e13_3_4_1` | 50.0% | 1 | 2 | 1 |  |
| 326 | `e4x/Regress/b121219` | 50.0% | 1 | 2 | 1 |  |
| 327 | `e4x/Regress/error1085` | 50.0% | 1 | 2 | 1 |  |
| 328 | `e4x/Regress/regress-257679` | 50.0% | 1 | 2 | 1 |  |
| 329 | `e4x/Regress/regress-263934` | 50.0% | 1 | 2 | 1 |  |
| 330 | `e4x/Regress/regress-263936` | 50.0% | 1 | 2 | 1 |  |
| 331 | `e4x/Regress/regress-264369` | 50.0% | 1 | 2 | 1 |  |
| 332 | `e4x/Regress/regress-277650` | 50.0% | 1 | 2 | 1 |  |
| 333 | `e4x/Regress/regress-277664` | 50.0% | 1 | 2 | 1 |  |
| 334 | `e4x/Regress/regress-277683` | 50.0% | 1 | 2 | 1 |  |
| 335 | `e4x/Regress/regress-277779` | 50.0% | 1 | 2 | 1 |  |
| 336 | `e4x/TypeConversion/e10_2_2` | 50.0% | 1 | 2 | 1 |  |
| 337 | `e4x/TypeConversion/e10_3_1` | 50.0% | 1 | 2 | 1 |  |
| 338 | `e4x/Types/e9_1_1_10` | 50.0% | 1 | 2 | 1 |  |
| 339 | `e4x/Types/e9_1_1_11` | 50.0% | 1 | 2 | 1 |  |
| 340 | `e4x/Types/e9_1_1_12` | 50.0% | 1 | 2 | 1 |  |
| 341 | `e4x/Types/e9_1_1_13` | 50.0% | 1 | 2 | 1 |  |
| 342 | `e4x/Types/e9_1_1_4` | 50.0% | 1 | 2 | 1 |  |
| 343 | `e4x/Types/e9_1_1_5` | 50.0% | 1 | 2 | 1 |  |
| 344 | `e4x/Types/e9_1_1_7` | 50.0% | 1 | 2 | 1 |  |
| 345 | `e4x/Types/e9_1_1_8` | 50.0% | 1 | 2 | 1 |  |
| 346 | `e4x/Types/e9_2_1_10` | 50.0% | 1 | 2 | 1 |  |
| 347 | `e4x/Types/e9_2_1_3` | 50.0% | 1 | 2 | 1 |  |
| 348 | `e4x/Types/e9_2_1_4` | 50.0% | 1 | 2 | 1 |  |
| 349 | `e4x/Types/e9_2_1_5` | 50.0% | 1 | 2 | 1 |  |
| 350 | `e4x/Types/e9_2_1_6` | 50.0% | 1 | 2 | 1 |  |
| 351 | `e4x/Types/e9_2_1_7` | 50.0% | 1 | 2 | 1 |  |
| 352 | `e4x/Types/e9_2_1_8` | 50.0% | 1 | 2 | 1 |  |
| 353 | `e4x/XML/bug157597` | 50.0% | 1 | 2 | 1 |  |
| 354 | `e4x/XML/bug157597_2` | 50.0% | 1 | 2 | 1 |  |
| 355 | `e4x/XML/bug157735` | 50.0% | 1 | 2 | 1 |  |
| 356 | `e4x/XML/bug158506` | 50.0% | 1 | 2 | 1 |  |
| 357 | `e4x/XMLList/bug157735` | 50.0% | 1 | 2 | 1 |  |
| 358 | `ecma3/Array/e15_4_4_5_3` | 50.0% | 28 | 56 | 28 |  |
| 359 | `ecma3/Boolean/e15_6_3` | 50.0% | 1 | 2 | 1 |  |
| 360 | `ecma3/Boolean/e15_6_4` | 50.0% | 1 | 2 | 1 |  |
| 361 | `ecma3/FunctionObjects/e15_3_3_1_3` | 50.0% | 1 | 2 | 1 |  |
| 362 | `ecma3/JSON/e15_12_0` | 50.0% | 2 | 4 | 2 |  |
| 363 | `ecma3/JSON/regress` | 50.0% | 3 | 6 | 3 |  |
| 364 | `ecma3/Number/e15_7_3` | 50.0% | 1 | 2 | 1 |  |
| 365 | `ecma3/Number/e15_7_3_1_1` | 50.0% | 1 | 2 | 1 |  |
| 366 | `ecma3/Number/e15_7_3_3_3` | 50.0% | 1 | 2 | 1 |  |
| 367 | `ecma3/Number/e15_7_3_4_3` | 50.0% | 1 | 2 | 1 |  |
| 368 | `ecma3/ObjectObjects/hasOwnProperty` | 50.0% | 5 | 10 | 5 |  |
| 369 | `ecma3/String/e15_5_3` | 50.0% | 1 | 2 | 1 |  |
| 370 | `ecma3/String/e15_5_4` | 50.0% | 3 | 6 | 3 |  |
| 371 | `recursion/pcre_find_firstassertedchar` | 50.0% | 1 | 2 | 1 |  |
| 372 | `recursion/pcre_find_fixedlength` | 50.0% | 10 | 20 | 10 |  |
| 373 | `recursion/pcre_is_anchored` | 50.0% | 1 | 2 | 1 |  |
| 374 | `recursion/pcre_is_startline` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

**2 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `as3/AMF/AMFSerializer` | 18.1s |  |
| 2 | `ecma3/Exceptions/bug127913` | 18.9s |  |

## Runtime Errors

**16 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/Definitions/Super/SuperInForLoop` | exit code 1 | 5.9s |  |
| 2 | `as3/Definitions/Super/SuperProps` | exit code 1 | 6.1s |  |
| 3 | `misc/bug_508617` | exit code 1 | 6.1s |  |
| 4 | `mops/lf32` | exit code 1 | 25.8s |  |
| 5 | `mops/lf64` | exit code 1 | 6.3s |  |
| 6 | `mops/li16` | exit code 1 | 6.2s |  |
| 7 | `mops/li32` | exit code 1 | 6.2s |  |
| 8 | `mops/li8` | exit code 1 | 6.2s |  |
| 9 | `mops/lix16` | exit code 1 | 6.1s |  |
| 10 | `mops/lix8` | exit code 1 | 6.1s |  |
| 11 | `mops/sf32` | exit code 1 | 6.2s |  |
| 12 | `mops/sf64` | exit code 1 | 6.3s |  |
| 13 | `mops/si16` | exit code 1 | 6.2s |  |
| 14 | `mops/si32` | exit code 1 | 6.2s |  |
| 15 | `mops/si8` | exit code 1 | 6.2s |  |
| 16 | `regress/bug_483783` | exit code 1 | 5.9s |  |

## Timeouts

**3 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/ByteArray/ByteArray_bug662851_32bit` | runtime timeout (>10s) | 35.9s |  |
| 2 | `as3/ByteArray/ByteArray_bug662851_64bit` | runtime timeout (>10s) | 35.9s |  |
| 3 | `mops/mops_basics` | runtime timeout (>10s) | 37.5s |  |

## All Output Mismatches

**681 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `ecma3/Array/e15_4_2_1_3` | 99.9% | 1030/1031 | 1030 | 1031 |  |
| 2 | `as3/Array/insertremove` | 99.7% | 30766/30870 | 30870 | 30870 |  |
| 3 | `ecma3/String/e15_5_4_4_1` | 99.5% | 188/189 | 188 | 189 |  |
| 4 | `ecma3/GlobalObject/e15_1_2_5_1` | 99.4% | 528/531 | 531 | 531 |  |
| 5 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321/323 | 323 | 323 |  |
| 6 | `ecma3/GlobalObject/e15_1_2_2_1` | 99.3% | 274/276 | 276 | 276 |  |
| 7 | `as3/Vector/vectorIndexRangeExceptions` | 99.2% | 1260/1270 | 1270 | 1270 |  |
| 8 | `ecma3/GlobalObject/e15_1_2_3_1` | 98.9% | 184/186 | 186 | 186 |  |
| 9 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474/481 | 481 | 481 |  |
| 10 | `e4x/Expressions/e11_5_1` | 98.5% | 65/66 | 65 | 66 |  |
| 11 | `e4x/XML/e13_4_3_8` | 97.6% | 40/41 | 40 | 41 |  |
| 12 | `e4x/Expressions/e11_2_1` | 97.5% | 39/40 | 39 | 40 |  |
| 13 | `e4x/XMLList/e13_5_4_4` | 97.4% | 38/39 | 38 | 39 |  |
| 14 | `e4x/XMLList/e13_5_2` | 97.3% | 36/37 | 36 | 37 |  |
| 15 | `e4x/XML/e13_4_2` | 97.2% | 35/36 | 35 | 36 |  |
| 16 | `ecma3/JSON/e15_12_1` | 97.2% | 35/36 | 36 | 36 |  |
| 17 | `e4x/XML/e13_4_3` | 97.1% | 34/35 | 34 | 35 |  |
| 18 | `e4x/Types/e9_1_1_1` | 96.9% | 31/32 | 31 | 32 |  |
| 19 | `e4x/XML/e13_4_3_7` | 96.8% | 30/31 | 30 | 31 |  |
| 20 | `e4x/XML/e13_4_4_6` | 96.8% | 30/31 | 30 | 31 |  |
| 21 | `ecma3/GlobalObject/e15_1_2_6` | 96.8% | 60/62 | 62 | 62 |  |
| 22 | `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | 96.6% | 28/29 | 28 | 29 |  |
| 23 | `e4x/XMLList/e13_5_4_13` | 96.4% | 27/28 | 27 | 28 |  |
| 24 | `e4x/XMLList/e13_5_4_2` | 96.4% | 27/28 | 27 | 28 |  |
| 25 | `ecma3/GlobalObject/e15_1_2_7` | 96.4% | 53/55 | 55 | 55 |  |
| 26 | `e4x/XMLList/e13_5_1` | 96.2% | 25/26 | 25 | 26 |  |
| 27 | `ecma3/Number/e15_7_4_2_4` | 96.1% | 49/51 | 51 | 51 |  |
| 28 | `e4x/XML/e13_4_4_16` | 96.0% | 24/25 | 24 | 25 |  |
| 29 | `e4x/QName/e13_3_2` | 95.9% | 47/49 | 48 | 49 |  |
| 30 | `e4x/Expressions/e11_2_2` | 95.8% | 23/24 | 23 | 24 |  |
| 31 | `e4x/XMLList/e13_5_4_16` | 95.8% | 23/24 | 23 | 24 |  |
| 32 | `e4x/Namespace/e13_2_2` | 95.5% | 21/22 | 21 | 22 |  |
| 33 | `e4x/QName/e13_3_1` | 95.5% | 21/22 | 21 | 22 |  |
| 34 | `e4x/XML/e13_4_4_24` | 95.5% | 21/22 | 21 | 22 |  |
| 35 | `e4x/XML/e13_4_4_27` | 95.2% | 20/21 | 20 | 21 |  |
| 36 | `as3/Vector/initializer_expressions` | 95.1% | 39/41 | 40 | 41 |  |
| 37 | `e4x/Types/e9_1_1_9` | 95.0% | 19/20 | 19 | 20 |  |
| 38 | `e4x/XML/e13_4_4_39` | 95.0% | 19/20 | 19 | 20 |  |
| 39 | `e4x/Expressions/e11_6_1` | 94.7% | 18/19 | 18 | 19 |  |
| 40 | `e4x/Namespace/e13_2_1` | 94.7% | 18/19 | 18 | 19 |  |
| 41 | `e4x/Types/e9_2_1_2` | 94.7% | 18/19 | 18 | 19 |  |
| 42 | `e4x/XML/e13_4_4_29/v10` | 94.7% | 18/19 | 18 | 19 |  |
| 43 | `e4x/XML/e13_4_4_29/v9` | 94.7% | 18/19 | 18 | 19 |  |
| 44 | `e4x/XML/e13_4_4_31` | 94.7% | 18/19 | 18 | 19 |  |
| 45 | `e4x/XML/e13_4_4_4` | 94.7% | 18/19 | 18 | 19 |  |
| 46 | `e4x/XMLList/e13_5_4_12` | 94.7% | 18/19 | 18 | 19 |  |
| 47 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89/94 | 94 | 94 |  |
| 48 | `e4x/Expressions/e11_4_1` | 94.4% | 17/18 | 17 | 18 |  |
| 49 | `e4x/Namespace/e13_2_5` | 94.4% | 34/36 | 36 | 36 |  |
| 50 | `e4x/XML/e13_4_1` | 94.4% | 17/18 | 17 | 18 |  |
| 51 | `ecma3/Expressions/e11_4_1` | 94.4% | 17/18 | 18 | 18 |  |
| 52 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16/17 | 17 | 17 |  |
| 53 | `e4x/Expressions/e11_1_5` | 94.1% | 16/17 | 16 | 17 |  |
| 54 | `e4x/XML/e13_4_4_23` | 94.1% | 16/17 | 16 | 17 |  |
| 55 | `e4x/XML/e13_4_4_35` | 94.1% | 16/17 | 16 | 17 |  |
| 56 | `e4x/XML/e13_4_4_38` | 94.1% | 16/17 | 16 | 17 |  |
| 57 | `ecma3/JSON/e15_12_3` | 93.9% | 31/33 | 33 | 33 |  |
| 58 | `e4x/XML/e13_4_4_15` | 93.8% | 15/16 | 15 | 16 |  |
| 59 | `e4x/XML/e13_4_4_18` | 93.8% | 15/16 | 15 | 16 |  |
| 60 | `e4x/XML/e13_4_4_19` | 93.8% | 15/16 | 15 | 16 |  |
| 61 | `e4x/XML/e13_4_4_21` | 93.8% | 15/16 | 15 | 16 |  |
| 62 | `e4x/XML/e13_4_4_3/v10` | 93.8% | 15/16 | 15 | 16 |  |
| 63 | `e4x/XML/e13_4_4_3/v21` | 93.8% | 15/16 | 15 | 16 |  |
| 64 | `e4x/XML/e13_4_4_3/v9` | 93.8% | 15/16 | 15 | 16 |  |
| 65 | `e4x/XMLList/e13_5_4_3` | 93.8% | 15/16 | 15 | 16 |  |
| 66 | `regress/bug_687838` | 93.7% | 104/111 | 111 | 111 |  |
| 67 | `e4x/Expressions/e11_2_4` | 93.3% | 14/15 | 14 | 15 |  |
| 68 | `e4x/Expressions/e11_6_2` | 93.3% | 14/15 | 14 | 15 |  |
| 69 | `e4x/XML/e13_4_4_12` | 93.3% | 14/15 | 14 | 15 |  |
| 70 | `e4x/XML/e13_4_4_22` | 93.3% | 14/15 | 14 | 15 |  |
| 71 | `e4x/XML/e13_4_4_25` | 93.3% | 14/15 | 14 | 15 |  |
| 72 | `e4x/Statements/e12_2` | 92.9% | 13/14 | 13 | 14 |  |
| 73 | `e4x/XML/e13_4_4_9` | 92.9% | 13/14 | 13 | 14 |  |
| 74 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13/14 | 14 | 14 |  |
| 75 | `as3/Vector/some` | 92.3% | 12/13 | 13 | 13 |  |
| 76 | `e4x/QName/e13_3_5` | 92.3% | 12/13 | 12 | 13 |  |
| 77 | `e4x/TypeConversion/e10_2_1_2` | 92.3% | 12/13 | 12 | 13 |  |
| 78 | `e4x/XMLList/e13_5_4_11` | 92.3% | 12/13 | 12 | 13 |  |
| 79 | `ecma3/String/e15_5_2` | 92.0% | 69/75 | 75 | 75 |  |
| 80 | `as3/Vector/map` | 91.7% | 11/12 | 12 | 12 |  |
| 81 | `e4x/XML/e13_4_4_11` | 91.7% | 11/12 | 11 | 12 |  |
| 82 | `e4x/XML/e13_4_4_14` | 91.7% | 11/12 | 11 | 12 |  |
| 83 | `e4x/XML/e13_4_4_34` | 91.7% | 11/12 | 11 | 12 |  |
| 84 | `e4x/XML/e13_4_4_37` | 91.7% | 11/12 | 11 | 12 |  |
| 85 | `e4x/XML/e13_4_4_5` | 91.7% | 11/12 | 11 | 12 |  |
| 86 | `e4x/XMLList/e13_5_4_20` | 91.7% | 11/12 | 11 | 12 |  |
| 87 | `e4x/XMLList/e13_5_4_21` | 91.7% | 11/12 | 11 | 12 |  |
| 88 | `as3/ShellClasses/DictionarySubclass` | 90.9% | 20/22 | 22 | 22 |  |
| 89 | `e4x/Types/e9_1_1_6` | 90.9% | 10/11 | 10 | 11 |  |
| 90 | `e4x/Types/e9_2_1_1` | 90.9% | 10/11 | 10 | 11 |  |
| 91 | `e4x/Types/e9_2_1_9` | 90.9% | 10/11 | 10 | 11 |  |
| 92 | `e4x/XML/e13_4_3_4` | 90.9% | 10/11 | 10 | 11 |  |
| 93 | `e4x/XML/e13_4_3_9` | 90.9% | 10/11 | 10 | 11 |  |
| 94 | `e4x/XML/e13_4_4_10` | 90.9% | 10/11 | 10 | 11 |  |
| 95 | `e4x/XML/e13_4_4_20` | 90.9% | 10/11 | 10 | 11 |  |
| 96 | `e4x/XML/misc_errors` | 90.9% | 30/33 | 32 | 33 |  |
| 97 | `e4x/XMLList/e13_5_4_14` | 90.9% | 10/11 | 10 | 11 |  |
| 98 | `e4x/XMLList/e13_5_4_5` | 90.9% | 10/11 | 10 | 11 |  |
| 99 | `e4x/XMLList/e13_5_4_8` | 90.9% | 10/11 | 10 | 11 |  |
| 100 | `ecma3/String/e15_5_4_5_6_rt` | 90.9% | 10/11 | 10 | 11 |  |
| 101 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28/31 | 31 | 31 |  |
| 102 | `as3/Vector/concat` | 90.0% | 9/10 | 9 | 10 |  |
| 103 | `e4x/Expressions/e11_2_3` | 90.0% | 9/10 | 9 | 10 |  |
| 104 | `e4x/XML/e13_4_3_6` | 90.0% | 9/10 | 9 | 10 |  |
| 105 | `e4x/XMLList/e13_5_4_9` | 90.0% | 9/10 | 9 | 10 |  |
| 106 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9/10 | 10 | 10 |  |
| 107 | `ecma3/ObjectObjects/e15_2_4_2` | 90.0% | 9/10 | 10 | 10 |  |
| 108 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54/60 | 60 | 60 |  |
| 109 | `as3/ByteArray/ByteArray` | 89.9% | 382/425 | 382 | 425 |  |
| 110 | `ecma3/Number/toLocaleString_rt` | 89.6% | 43/48 | 48 | 48 |  |
| 111 | `e4x/XML/e13_4_4_17` | 89.5% | 17/19 | 18 | 19 |  |
| 112 | `ecma3/TypeConversion/e9_4_1` | 89.5% | 17/19 | 19 | 19 |  |
| 113 | `ecma3/TypeConversion/e9_4_2` | 89.5% | 17/19 | 19 | 19 |  |
| 114 | `ecma3/Expressions/e11_1_4` | 89.3% | 25/28 | 28 | 28 |  |
| 115 | `as3/Vector/filter` | 88.9% | 8/9 | 9 | 9 |  |
| 116 | `e4x/TypeConversion/e10_4` | 88.9% | 8/9 | 8 | 9 |  |
| 117 | `e4x/XML/e13_4_4_32/v10` | 88.9% | 8/9 | 8 | 9 |  |
| 118 | `ecma3/Number/e15_7_4_2_1_rt` | 88.9% | 8/9 | 9 | 9 |  |
| 119 | `ecma3/JSON/AS3Types` | 88.5% | 23/26 | 24 | 26 |  |
| 120 | `as3/Vector/nested` | 87.5% | 7/8 | 8 | 8 |  |
| 121 | `e4x/Expressions/e11_1_3` | 87.5% | 7/8 | 7 | 8 |  |
| 122 | `e4x/TypeConversion/e10_4_1` | 87.5% | 7/8 | 7 | 8 |  |
| 123 | `e4x/XML/e13_4_3_2` | 87.5% | 7/8 | 7 | 8 |  |
| 124 | `e4x/XML/e13_4_3_3` | 87.5% | 7/8 | 7 | 8 |  |
| 125 | `ecma3/String/e15_5_4_2_rt` | 87.5% | 7/8 | 8 | 8 |  |
| 126 | `e4x/Expressions/e11_1_1` | 87.2% | 34/39 | 38 | 39 |  |
| 127 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 85.7% | 6/7 | 7 | 7 |  |
| 128 | `as3/Vector/map_initializers` | 85.7% | 6/7 | 7 | 7 |  |
| 129 | `e4x/Expressions/e11_3_2` | 85.7% | 6/7 | 6 | 7 |  |
| 130 | `e4x/TypeConversion/e10_3` | 85.7% | 6/7 | 6 | 7 |  |
| 131 | `e4x/XML/e13_4_4_13` | 85.7% | 6/7 | 6 | 7 |  |
| 132 | `e4x/XML/e13_4_4_40` | 85.7% | 6/7 | 6 | 7 |  |
| 133 | `e4x/XML/e13_4_4_7` | 85.7% | 6/7 | 6 | 7 |  |
| 134 | `e4x/XML/e13_4_4_8` | 85.7% | 6/7 | 6 | 7 |  |
| 135 | `e4x/XML/kXMLPrefixNotBoundErr` | 85.7% | 6/7 | 6 | 7 |  |
| 136 | `e4x/XMLList/e13_5_4_10` | 85.7% | 6/7 | 6 | 7 |  |
| 137 | `ecma3/Number/e15_7_4_3_1_rt` | 85.7% | 6/7 | 7 | 7 |  |
| 138 | `ecma3/String/e15_5_4_3_1` | 85.7% | 6/7 | 7 | 7 |  |
| 139 | `ecma3/Types/e8_6_1` | 85.7% | 6/7 | 7 | 7 |  |
| 140 | `e4x/XML/e13_4_4_28` | 84.6% | 11/13 | 12 | 13 |  |
| 141 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 83.3% | 5/6 | 5 | 6 |  |
| 142 | `as3/Vector/foreach` | 83.3% | 5/6 | 6 | 6 |  |
| 143 | `as3/Vector/some_initializers` | 83.3% | 5/6 | 6 | 6 |  |
| 144 | `e4x/Expressions/e11_6_3` | 83.3% | 5/6 | 5 | 6 |  |
| 145 | `e4x/Regress/regress-271545` | 83.3% | 5/6 | 5 | 6 |  |
| 146 | `e4x/Types/e9_1_1_2` | 83.3% | 5/6 | 5 | 6 |  |
| 147 | `e4x/XML/e13_4_4_26` | 83.3% | 5/6 | 5 | 6 |  |
| 148 | `e4x/XML/e13_4_4_33` | 83.3% | 5/6 | 5 | 6 |  |
| 149 | `e4x/XMLList/e13_5_4_6` | 83.3% | 5/6 | 5 | 6 |  |
| 150 | `e4x/XMLList/e13_5_4_7` | 83.3% | 5/6 | 5 | 6 |  |
| 151 | `ecma3/Array/e15_4_4_10` | 83.3% | 5/6 | 5 | 6 |  |
| 152 | `ecma3/JSON/e15_12_2` | 83.3% | 10/12 | 12 | 12 |  |
| 153 | `ecma3/String/e15_5_4_2_1` | 83.3% | 5/6 | 6 | 6 |  |
| 154 | `ecma3/Unicode/u0000_BasicLatin` | 81.0% | 17/21 | 21 | 21 |  |
| 155 | `as3/Vector/filter_initializers` | 80.0% | 4/5 | 5 | 5 |  |
| 156 | `as3/Vector/foreach_initializers` | 80.0% | 4/5 | 5 | 5 |  |
| 157 | `e4x/Expressions/kXMLBadQNameErr` | 80.0% | 4/5 | 4 | 5 |  |
| 158 | `e4x/Statements/e12_3` | 80.0% | 4/5 | 4 | 5 |  |
| 159 | `e4x/TypeConversion/e10_1_2` | 80.0% | 4/5 | 4 | 5 |  |
| 160 | `e4x/TypeConversion/e10_2_1` | 80.0% | 4/5 | 4 | 5 |  |
| 161 | `e4x/TypeConversion/e10_2_1_1` | 80.0% | 4/5 | 4 | 5 |  |
| 162 | `e4x/Types/e9_1_1_3` | 80.0% | 4/5 | 4 | 5 |  |
| 163 | `e4x/XML/e13_4_3_1` | 80.0% | 4/5 | 4 | 5 |  |
| 164 | `e4x/XML/e13_4_3_5` | 80.0% | 4/5 | 4 | 5 |  |
| 165 | `e4x/XML/kXMLUnterminatedElementTagErr` | 80.0% | 4/5 | 4 | 5 |  |
| 166 | `e4x/XMLList/e13_5_3_1` | 80.0% | 4/5 | 4 | 5 |  |
| 167 | `e4x/XMLList/e13_5_4_17` | 80.0% | 8/10 | 9 | 10 |  |
| 168 | `e4x/XMLList/e13_5_4_19` | 80.0% | 4/5 | 4 | 5 |  |
| 169 | `e4x/XMLList/e13_5_4_22` | 80.0% | 4/5 | 4 | 5 |  |
| 170 | `ecma3/Array/e15_4_2_3` | 80.0% | 4/5 | 5 | 5 |  |
| 171 | `ecma3/ObjectObjects/toLocaleString_rt` | 80.0% | 4/5 | 5 | 5 |  |
| 172 | `ecma3/Array/e15_4_1` | 78.6% | 11/14 | 14 | 14 |  |
| 173 | `e4x/XML/e13_4_4_32/v9` | 77.8% | 7/9 | 8 | 9 |  |
| 174 | `ecma3/Unicode/u0080_Latin_1Supplement` | 76.2% | 16/21 | 21 | 21 |  |
| 175 | `ecma3/Unicode/u0100_LatinExtended_A` | 76.2% | 16/21 | 21 | 21 |  |
| 176 | `ecma3/Unicode/u0180_LatinExtended_B` | 76.2% | 16/21 | 21 | 21 |  |
| 177 | `ecma3/Unicode/u0250_IPAExtensions` | 76.2% | 16/21 | 21 | 21 |  |
| 178 | `ecma3/Unicode/u02B0_SpacingModifierLetters` | 76.2% | 16/21 | 21 | 21 |  |
| 179 | `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | 76.2% | 16/21 | 21 | 21 |  |
| 180 | `ecma3/Unicode/u0370_GreekandCoptic` | 76.2% | 16/21 | 21 | 21 |  |
| 181 | `ecma3/Unicode/u0400_Cyrillic` | 76.2% | 32/42 | 42 | 42 |  |
| 182 | `ecma3/Unicode/u0500_CyrillicSupplementary` | 76.2% | 16/21 | 21 | 21 |  |
| 183 | `ecma3/Unicode/u0530_Armenian` | 76.2% | 16/21 | 21 | 21 |  |
| 184 | `ecma3/Unicode/u0590_Hebrew` | 76.2% | 16/21 | 21 | 21 |  |
| 185 | `ecma3/Unicode/u0600_Arabic` | 76.2% | 32/42 | 42 | 42 |  |
| 186 | `ecma3/Unicode/u0700_Syriac` | 76.2% | 16/21 | 21 | 21 |  |
| 187 | `ecma3/Unicode/u0780_Thaana` | 76.2% | 16/21 | 21 | 21 |  |
| 188 | `ecma3/Unicode/u0900_Devanagari` | 76.2% | 16/21 | 21 | 21 |  |
| 189 | `ecma3/Unicode/u0980_Bengali` | 76.2% | 16/21 | 21 | 21 |  |
| 190 | `ecma3/Unicode/u0A00_Gurmukhi` | 76.2% | 16/21 | 21 | 21 |  |
| 191 | `ecma3/Unicode/u0A80_Gujarati` | 76.2% | 16/21 | 21 | 21 |  |
| 192 | `ecma3/Unicode/u0B00_Oriya` | 76.2% | 16/21 | 21 | 21 |  |
| 193 | `ecma3/Unicode/u0B80_Tamil` | 76.2% | 16/21 | 21 | 21 |  |
| 194 | `ecma3/Unicode/u0C00_Telugu` | 76.2% | 16/21 | 21 | 21 |  |
| 195 | `ecma3/Unicode/u0C80_Kannada` | 76.2% | 16/21 | 21 | 21 |  |
| 196 | `ecma3/Unicode/u0D00_Malayalam` | 76.2% | 16/21 | 21 | 21 |  |
| 197 | `ecma3/Unicode/u0D80_Sinhala` | 76.2% | 16/21 | 21 | 21 |  |
| 198 | `ecma3/Unicode/u0E00_Thai` | 76.2% | 16/21 | 21 | 21 |  |
| 199 | `ecma3/Unicode/u0E80_Lao` | 76.2% | 16/21 | 21 | 21 |  |
| 200 | `ecma3/Unicode/u0F00_Tibetan` | 76.2% | 32/42 | 42 | 42 |  |
| 201 | `ecma3/Unicode/u1000_Myanmar` | 76.2% | 16/21 | 21 | 21 |  |
| 202 | `ecma3/Unicode/u10A0_Georgian` | 76.2% | 16/21 | 21 | 21 |  |
| 203 | `ecma3/Unicode/u1100_HangulJamo` | 76.2% | 32/42 | 42 | 42 |  |
| 204 | `ecma3/Unicode/u1200_Ethiopic` | 76.2% | 32/42 | 42 | 42 |  |
| 205 | `ecma3/Unicode/u13A0_Cherokee` | 76.2% | 16/21 | 21 | 21 |  |
| 206 | `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | 76.2% | 48/63 | 63 | 63 |  |
| 207 | `ecma3/Unicode/u1680_Ogham` | 76.2% | 16/21 | 21 | 21 |  |
| 208 | `ecma3/Unicode/u16A0_Runic` | 76.2% | 16/21 | 21 | 21 |  |
| 209 | `ecma3/Unicode/u1700_Tagalog` | 76.2% | 16/21 | 21 | 21 |  |
| 210 | `ecma3/Unicode/u1720_Hanunoo` | 76.2% | 16/21 | 21 | 21 |  |
| 211 | `ecma3/Unicode/u1740_Buhid` | 76.2% | 16/21 | 21 | 21 |  |
| 212 | `ecma3/Unicode/u1760_Tagbanwa` | 76.2% | 16/21 | 21 | 21 |  |
| 213 | `ecma3/Unicode/u1780_Khmer` | 76.2% | 16/21 | 21 | 21 |  |
| 214 | `ecma3/Unicode/u1800_Mongolian` | 76.2% | 16/21 | 21 | 21 |  |
| 215 | `ecma3/Unicode/u1E00_LatinExtendedAdditional` | 76.2% | 32/42 | 42 | 42 |  |
| 216 | `ecma3/Unicode/u1F00_GreekExtended` | 76.2% | 32/42 | 42 | 42 |  |
| 217 | `ecma3/Unicode/u2000_GeneralPunctuation` | 76.2% | 16/21 | 21 | 21 |  |
| 218 | `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | 76.2% | 16/21 | 21 | 21 |  |
| 219 | `ecma3/Unicode/u20A0_CurrencySymbols` | 76.2% | 16/21 | 21 | 21 |  |
| 220 | `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | 76.2% | 16/21 | 21 | 21 |  |
| 221 | `ecma3/Unicode/u2100_LetterlikeSymbols` | 76.2% | 16/21 | 21 | 21 |  |
| 222 | `ecma3/Unicode/u2150_NumberForms` | 76.2% | 16/21 | 21 | 21 |  |
| 223 | `ecma3/Unicode/u2190_Arrows` | 76.2% | 16/21 | 21 | 21 |  |
| 224 | `ecma3/Unicode/u2200_MathematicalOperators` | 76.2% | 32/42 | 42 | 42 |  |
| 225 | `ecma3/Unicode/u2300_MiscellaneousTechnical` | 76.2% | 32/42 | 42 | 42 |  |
| 226 | `ecma3/Unicode/u2400_ControlPictures` | 76.2% | 16/21 | 21 | 21 |  |
| 227 | `ecma3/Unicode/u2440_OpticalCharacterRecognition` | 76.2% | 16/21 | 21 | 21 |  |
| 228 | `ecma3/Unicode/u2460_EnclosedAlphanumerics` | 76.2% | 16/21 | 21 | 21 |  |
| 229 | `ecma3/Unicode/u2500_BoxDrawing` | 76.2% | 16/21 | 21 | 21 |  |
| 230 | `ecma3/Unicode/u2580_BlockElements` | 76.2% | 16/21 | 21 | 21 |  |
| 231 | `ecma3/Unicode/u25A0_GeometricShapes` | 76.2% | 16/21 | 21 | 21 |  |
| 232 | `ecma3/Unicode/u2600_MiscellaneousSymbols` | 76.2% | 32/42 | 42 | 42 |  |
| 233 | `ecma3/Unicode/u2700_Dingbats` | 76.2% | 16/21 | 21 | 21 |  |
| 234 | `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | 76.2% | 16/21 | 21 | 21 |  |
| 235 | `ecma3/Unicode/u27F0_SupplementalArrows_A` | 76.2% | 16/21 | 21 | 21 |  |
| 236 | `ecma3/Unicode/u2800_BraillePatterns` | 76.2% | 32/42 | 42 | 42 |  |
| 237 | `ecma3/Unicode/u2900_SupplementalArrows_B` | 76.2% | 16/21 | 21 | 21 |  |
| 238 | `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | 76.2% | 16/21 | 21 | 21 |  |
| 239 | `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | 76.2% | 32/42 | 42 | 42 |  |
| 240 | `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | 76.2% | 16/21 | 21 | 21 |  |
| 241 | `ecma3/Unicode/u2F00_KangxiRadicals` | 76.2% | 16/21 | 21 | 21 |  |
| 242 | `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | 76.2% | 16/21 | 21 | 21 |  |
| 243 | `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | 76.2% | 16/21 | 21 | 21 |  |
| 244 | `ecma3/Unicode/u3040_Hiragana` | 76.2% | 16/21 | 21 | 21 |  |
| 245 | `ecma3/Unicode/u30A0_Katakana` | 76.2% | 16/21 | 21 | 21 |  |
| 246 | `ecma3/Unicode/u3100_Bopomofo` | 76.2% | 16/21 | 21 | 21 |  |
| 247 | `ecma3/Unicode/u3130_HangulCompatibilityJamo` | 76.2% | 16/21 | 21 | 21 |  |
| 248 | `ecma3/Unicode/u3190_Kanbun` | 76.2% | 16/21 | 21 | 21 |  |
| 249 | `ecma3/Unicode/u31A0_BopomofoExtended` | 76.2% | 16/21 | 21 | 21 |  |
| 250 | `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | 76.2% | 16/21 | 21 | 21 |  |
| 251 | `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | 76.2% | 32/42 | 42 | 42 |  |
| 252 | `ecma3/Unicode/u3300_CJKCompatibility` | 76.2% | 32/42 | 42 | 42 |  |
| 253 | `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | 76.2% | 432/567 | 567 | 567 |  |
| 254 | `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | 76.2% | 48/63 | 63 | 63 |  |
| 255 | `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | 76.2% | 272/357 | 357 | 357 |  |
| 256 | `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | 76.2% | 272/357 | 357 | 357 |  |
| 257 | `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | 76.2% | 272/357 | 357 | 357 |  |
| 258 | `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | 76.2% | 272/357 | 357 | 357 |  |
| 259 | `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | 76.2% | 272/357 | 357 | 357 |  |
| 260 | `ecma3/Unicode/uA000_YiSyllables` | 76.2% | 80/105 | 105 | 105 |  |
| 261 | `ecma3/Unicode/uA490_YiRadicals` | 76.2% | 16/21 | 21 | 21 |  |
| 262 | `ecma3/Unicode/uAC00_HangulSyllables` | 76.2% | 720/945 | 945 | 945 |  |
| 263 | `ecma3/Unicode/uE000_PrivateUseArea` | 76.2% | 416/546 | 546 | 546 |  |
| 264 | `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | 76.2% | 48/63 | 63 | 63 |  |
| 265 | `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | 76.2% | 16/21 | 21 | 21 |  |
| 266 | `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | 76.2% | 48/63 | 63 | 63 |  |
| 267 | `ecma3/Unicode/uFE00_VariationSelectors` | 76.2% | 16/21 | 21 | 21 |  |
| 268 | `ecma3/Unicode/uFE20_CombiningHalfMarks` | 76.2% | 16/21 | 21 | 21 |  |
| 269 | `ecma3/Unicode/uFE30_CJKCompatibilityForms` | 76.2% | 16/21 | 21 | 21 |  |
| 270 | `ecma3/Unicode/uFE50_SmallFormVariants` | 76.2% | 16/21 | 21 | 21 |  |
| 271 | `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | 76.2% | 16/21 | 21 | 21 |  |
| 272 | `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | 76.2% | 16/21 | 21 | 21 |  |
| 273 | `ecma3/Unicode/uFFF0_Specials` | 76.2% | 16/21 | 21 | 21 |  |
| 274 | `e4x/Namespace/e13_2_4_2` | 75.0% | 3/4 | 3 | 4 |  |
| 275 | `e4x/QName/e13_3_4_2` | 75.0% | 3/4 | 3 | 4 |  |
| 276 | `e4x/Regress/regress-278112` | 75.0% | 3/4 | 3 | 4 |  |
| 277 | `e4x/XML/e13_4_4_36` | 75.0% | 12/16 | 15 | 16 |  |
| 278 | `ecma3/Array/e15_4_3_1_2` | 75.0% | 3/4 | 4 | 4 |  |
| 279 | `ecma3/Boolean/e15_6_4__1` | 75.0% | 3/4 | 4 | 4 |  |
| 280 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 281 | `ecma3/FunctionObjects/e15_3_4_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 282 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 283 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6/8 | 8 | 8 |  |
| 284 | `ecma3/Statements/eforin_001` | 75.0% | 12/16 | 16 | 16 |  |
| 285 | `ecma3/String/localeCompare_rt` | 75.0% | 3/4 | 4 | 4 |  |
| 286 | `ecma3/String/e15_5_5_1` | 70.0% | 7/10 | 10 | 10 |  |
| 287 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2/3 | 3 | 3 |  |
| 288 | `e4x/Namespace/e13_2_3_1` | 66.7% | 2/3 | 2 | 3 |  |
| 289 | `e4x/Namespace/e13_2_4_1` | 66.7% | 2/3 | 2 | 3 |  |
| 290 | `e4x/QName/e13_3_3_1` | 66.7% | 2/3 | 2 | 3 |  |
| 291 | `e4x/TypeConversion/bug153363` | 66.7% | 2/3 | 2 | 3 |  |
| 292 | `e4x/TypeConversion/bug153363_2` | 66.7% | 2/3 | 2 | 3 |  |
| 293 | `e4x/TypeConversion/e10_1_1` | 66.7% | 2/3 | 2 | 3 |  |
| 294 | `e4x/XML/e13_4_4_1` | 66.7% | 2/3 | 2 | 3 |  |
| 295 | `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | 66.7% | 2/3 | 2 | 3 |  |
| 296 | `e4x/XML/kXMLMarkupMustBeWellFormedErr` | 66.7% | 2/3 | 2 | 3 |  |
| 297 | `e4x/XMLList/e13_5_4_1` | 66.7% | 2/3 | 2 | 3 |  |
| 298 | `e4x/XMLList/e13_5_4_15` | 66.7% | 2/3 | 2 | 3 |  |
| 299 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 66.7% | 4/6 | 6 | 6 |  |
| 300 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 301 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 302 | `ecma3/Number/e15_7_4__1_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 303 | `ecma3/Number/e15_7_4_rt` | 66.7% | 2/3 | 3 | 3 |  |
| 304 | `ecma3/Unicode/utf8count` | 66.7% | 2/3 | 3 | 3 |  |
| 305 | `regress/bug_550958` | 66.7% | 2/3 | 2 | 3 |  |
| 306 | `ecma3/JSON/adhoc` | 65.0% | 26/40 | 40 | 40 |  |
| 307 | `e4x/XML/e13_4_4_30` | 63.6% | 7/11 | 10 | 11 |  |
| 308 | `ecma3/Expressions/e11_2_1_1` | 63.4% | 161/254 | 254 | 254 |  |
| 309 | `regress/bug_420755` | 63.0% | 17/27 | 27 | 27 |  |
| 310 | `regress/bug_654807_swf13` | 60.0% | 102/170 | 170 | 170 |  |
| 311 | `e4x/Statements/e12_1` | 58.8% | 10/17 | 16 | 17 |  |
| 312 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 58.3% | 21/36 | 21 | 36 |  |
| 313 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 53.8% | 7/13 | 13 | 13 |  |
| 314 | `ecma3/String/e15_5_4_4_4_rt` | 53.8% | 28/52 | 28 | 52 |  |
| 315 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 316 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 53.1% | 17/32 | 17 | 32 |  |
| 317 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 318 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 319 | `as3/Definitions/Classes/ClassDef/InternalClass` | 53.1% | 17/32 | 17 | 32 |  |
| 320 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 53.1% | 17/32 | 17 | 32 |  |
| 321 | `e4x/Expressions/e11_1_2` | 52.2% | 12/23 | 23 | 20 |  |
| 322 | `as3/Types/Int/intMaxValue` | 50.0% | 2/4 | 4 | 4 |  |
| 323 | `as3/Types/Int/intMinValue` | 50.0% | 2/4 | 4 | 4 |  |
| 324 | `as3/Vector/bug_678952` | 50.0% | 1/2 | 2 | 2 |  |
| 325 | `e4x/QName/e13_3_4_1` | 50.0% | 1/2 | 1 | 2 |  |
| 326 | `e4x/Regress/b121219` | 50.0% | 1/2 | 1 | 2 |  |
| 327 | `e4x/Regress/error1085` | 50.0% | 1/2 | 1 | 2 |  |
| 328 | `e4x/Regress/regress-257679` | 50.0% | 1/2 | 1 | 2 |  |
| 329 | `e4x/Regress/regress-263934` | 50.0% | 1/2 | 1 | 2 |  |
| 330 | `e4x/Regress/regress-263936` | 50.0% | 1/2 | 1 | 2 |  |
| 331 | `e4x/Regress/regress-264369` | 50.0% | 1/2 | 1 | 2 |  |
| 332 | `e4x/Regress/regress-277650` | 50.0% | 1/2 | 1 | 2 |  |
| 333 | `e4x/Regress/regress-277664` | 50.0% | 1/2 | 1 | 2 |  |
| 334 | `e4x/Regress/regress-277683` | 50.0% | 1/2 | 1 | 2 |  |
| 335 | `e4x/Regress/regress-277779` | 50.0% | 1/2 | 1 | 2 |  |
| 336 | `e4x/TypeConversion/e10_2_2` | 50.0% | 1/2 | 1 | 2 |  |
| 337 | `e4x/TypeConversion/e10_3_1` | 50.0% | 1/2 | 1 | 2 |  |
| 338 | `e4x/Types/e9_1_1_10` | 50.0% | 1/2 | 1 | 2 |  |
| 339 | `e4x/Types/e9_1_1_11` | 50.0% | 1/2 | 1 | 2 |  |
| 340 | `e4x/Types/e9_1_1_12` | 50.0% | 1/2 | 1 | 2 |  |
| 341 | `e4x/Types/e9_1_1_13` | 50.0% | 1/2 | 1 | 2 |  |
| 342 | `e4x/Types/e9_1_1_4` | 50.0% | 1/2 | 1 | 2 |  |
| 343 | `e4x/Types/e9_1_1_5` | 50.0% | 1/2 | 1 | 2 |  |
| 344 | `e4x/Types/e9_1_1_7` | 50.0% | 1/2 | 1 | 2 |  |
| 345 | `e4x/Types/e9_1_1_8` | 50.0% | 1/2 | 1 | 2 |  |
| 346 | `e4x/Types/e9_2_1_10` | 50.0% | 1/2 | 1 | 2 |  |
| 347 | `e4x/Types/e9_2_1_3` | 50.0% | 1/2 | 1 | 2 |  |
| 348 | `e4x/Types/e9_2_1_4` | 50.0% | 1/2 | 1 | 2 |  |
| 349 | `e4x/Types/e9_2_1_5` | 50.0% | 1/2 | 1 | 2 |  |
| 350 | `e4x/Types/e9_2_1_6` | 50.0% | 1/2 | 1 | 2 |  |
| 351 | `e4x/Types/e9_2_1_7` | 50.0% | 1/2 | 1 | 2 |  |
| 352 | `e4x/Types/e9_2_1_8` | 50.0% | 1/2 | 1 | 2 |  |
| 353 | `e4x/XML/bug157597` | 50.0% | 1/2 | 1 | 2 |  |
| 354 | `e4x/XML/bug157597_2` | 50.0% | 1/2 | 1 | 2 |  |
| 355 | `e4x/XML/bug157735` | 50.0% | 1/2 | 1 | 2 |  |
| 356 | `e4x/XML/bug158506` | 50.0% | 1/2 | 1 | 2 |  |
| 357 | `e4x/XMLList/bug157735` | 50.0% | 1/2 | 1 | 2 |  |
| 358 | `ecma3/Array/e15_4_4_5_3` | 50.0% | 28/56 | 56 | 56 |  |
| 359 | `ecma3/Boolean/e15_6_3` | 50.0% | 1/2 | 2 | 2 |  |
| 360 | `ecma3/Boolean/e15_6_4` | 50.0% | 1/2 | 2 | 2 |  |
| 361 | `ecma3/FunctionObjects/e15_3_3_1_3` | 50.0% | 1/2 | 2 | 2 |  |
| 362 | `ecma3/JSON/e15_12_0` | 50.0% | 2/4 | 4 | 4 |  |
| 363 | `ecma3/JSON/regress` | 50.0% | 3/6 | 6 | 5 |  |
| 364 | `ecma3/Number/e15_7_3` | 50.0% | 1/2 | 2 | 2 |  |
| 365 | `ecma3/Number/e15_7_3_1_1` | 50.0% | 1/2 | 2 | 2 |  |
| 366 | `ecma3/Number/e15_7_3_3_3` | 50.0% | 1/2 | 2 | 2 |  |
| 367 | `ecma3/Number/e15_7_3_4_3` | 50.0% | 1/2 | 2 | 2 |  |
| 368 | `ecma3/ObjectObjects/hasOwnProperty` | 50.0% | 5/10 | 10 | 10 |  |
| 369 | `ecma3/String/e15_5_3` | 50.0% | 1/2 | 2 | 2 |  |
| 370 | `ecma3/String/e15_5_4` | 50.0% | 3/6 | 6 | 6 |  |
| 371 | `recursion/pcre_find_firstassertedchar` | 50.0% | 1/2 | 2 | 2 |  |
| 372 | `recursion/pcre_find_fixedlength` | 50.0% | 10/20 | 20 | 20 |  |
| 373 | `recursion/pcre_is_anchored` | 50.0% | 1/2 | 2 | 2 |  |
| 374 | `recursion/pcre_is_startline` | 50.0% | 1/2 | 2 | 2 |  |
| 375 | `as3/Definitions/Classes/ClassDef/PublicClass` | 47.7% | 21/44 | 21 | 44 |  |
| 376 | `as3/Definitions/Classes/ClassDef/PublicDynamicClass` | 47.7% | 21/44 | 21 | 44 |  |
| 377 | `regress/bug_539328` | 46.7% | 7/15 | 8 | 15 |  |
| 378 | `as3/Definitions/Classes/ClassDef/FinalPublicClass` | 42.5% | 17/40 | 17 | 40 |  |
| 379 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass` | 42.5% | 17/40 | 17 | 40 |  |
| 380 | `e4x/XMLList/e13_5_4_18` | 40.0% | 2/5 | 4 | 5 |  |
| 381 | `e4x/Expressions/e11_1_4` | 38.9% | 14/36 | 36 | 34 |  |
| 382 | `as3/Expressions/QualifiedReferences/WildcardOperator` | 33.3% | 1/3 | 3 | 3 |  |
| 383 | `ecma3/Exceptions/exception_011_rt` | 33.3% | 1/3 | 1 | 3 |  |
| 384 | `ecma3/Expressions/e11_6_1_3` | 33.3% | 3/9 | 9 | 9 |  |
| 385 | `ecma3/FunctionObjects/ecall_1` | 33.3% | 1/3 | 3 | 3 |  |
| 386 | `ecma3/String/esplit_002` | 31.9% | 30/94 | 30 | 94 |  |
| 387 | `regress/bug_654807_swf12` | 31.8% | 54/170 | 170 | 170 |  |
| 388 | `e4x/Expressions/e11_3_1` | 29.4% | 10/34 | 34 | 20 |  |
| 389 | `ecma3/Array/e15_4_1_1` | 28.6% | 2/7 | 2 | 7 |  |
| 390 | `e4x/XML/e13_4_4_2` | 26.7% | 4/15 | 13 | 15 |  |
| 391 | `as3/String/localeCompare_585791/v9` | 25.0% | 2/8 | 8 | 8 |  |
| 392 | `as3/Types/Number/e` | 25.0% | 2/8 | 8 | 8 |  |
| 393 | `as3/Types/Number/ln10` | 25.0% | 2/8 | 8 | 8 |  |
| 394 | `as3/Types/Number/ln2` | 25.0% | 2/8 | 8 | 8 |  |
| 395 | `as3/Types/Number/pi` | 25.0% | 2/8 | 8 | 8 |  |
| 396 | `as3/Types/Number/sqrt2` | 25.0% | 2/8 | 8 | 8 |  |
| 397 | `ecma3/Array/e15_4_4` | 25.0% | 1/4 | 4 | 4 |  |
| 398 | `as3/Types/Number/log10e` | 22.2% | 2/9 | 9 | 9 |  |
| 399 | `as3/Types/Number/log2e` | 22.2% | 2/9 | 9 | 9 |  |
| 400 | `as3/Types/Number/sqrt1_2` | 22.2% | 2/9 | 9 | 9 |  |
| 401 | `ecma3/NativeObjects/e15_2_rt` | 22.2% | 2/9 | 8 | 9 |  |
| 402 | `as3/Array/bug_535446` | 20.0% | 2/10 | 10 | 10 |  |
| 403 | `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp` | 18.8% | 3/16 | 3 | 16 |  |
| 404 | `ecma3/String/e15_5_4_4_2` | 18.2% | 6/33 | 6 | 33 |  |
| 405 | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 16.7% | 1/6 | 6 | 6 |  |
| 406 | `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp` | 13.6% | 3/22 | 3 | 22 |  |
| 407 | `e4x/Regress/regress-524214` | 9.1% | 1/11 | 11 | 3 |  |
| 408 | `ecma3/GlobalObject/e15_1_2_4` | 4.9% | 48/983 | 983 | 983 |  |
| 409 | `ecma3/Number/e15_7_4_6_1` | 3.8% | 1/26 | 1 | 26 |  |
| 410 | `as3/Types/Number/e15_7_4_6_1/swf14` | 3.4% | 1/29 | 1 | 29 |  |
| 411 | `as3/Types/Number/e15_7_4_6_1/swf15` | 3.4% | 1/29 | 1 | 29 |  |
| 412 | `as3/ByteArray/ByteArrayLzma` | 1.8% | 7/397 | 12 | 397 |  |
| 413 | `ecma3/String/e15_5_4_6_2_rt` | 0.4% | 1/232 | 1 | 232 |  |
| 414 | `as3/Array/length_mods` | 0.0% | 0/20 | 9 | 20 |  |
| 415 | `as3/ByteArray/ByteArrayLzmaThirdParty` | 0.0% | 0/2 | 0 | 2 |  |
| 416 | `as3/Definitions/Classes/ClassDef/Bug118272Package` | 0.0% | 0/6 | 6 | 6 |  |
| 417 | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 418 | `as3/Expressions/deleteOperator/deleteFixedFunction` | 0.0% | 0/1 | 1 | 1 |  |
| 419 | `as3/Expressions/deleteOperator/deleteFixedVar` | 0.0% | 0/1 | 1 | 1 |  |
| 420 | `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | 0.0% | 0/1 | 1 | 1 |  |
| 421 | `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | 0.0% | 0/1 | 1 | 1 |  |
| 422 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | 0.0% | 0/2 | 1 | 2 |  |
| 423 | `as3/RuntimeErrors/Error1052InvalidUriPassed` | 0.0% | 0/1 | 1 | 1 |  |
| 424 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 425 | `as3/RuntimeErrors/Error1066Function-body-NotAllowed` | 0.0% | 0/1 | 1 | 1 |  |
| 426 | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | 0.0% | 0/1 | 0 | 1 |  |
| 427 | `as3/RuntimeErrors/Error1075MathNotAFunction` | 0.0% | 0/1 | 1 | 1 |  |
| 428 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 429 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 0.0% | 0/1 | 1 | 1 |  |
| 430 | `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | 0.0% | 0/2 | 2 | 2 |  |
| 431 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | 0.0% | 0/3 | 0 | 3 |  |
| 432 | `as3/RuntimeErrors/Error1117InvalidXmlName` | 0.0% | 0/2 | 1 | 2 |  |
| 433 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | 0.0% | 0/2 | 1 | 2 |  |
| 434 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | 0.0% | 0/1 | 1 | 1 |  |
| 435 | `as3/Statements/Exceptions/MultipleCatchBlocksURI` | 0.0% | 0/1 | 1 | 1 |  |
| 436 | `as3/Types/Number/abs` | 0.0% | 0/41 | 0 | 41 |  |
| 437 | `as3/Types/Number/acos` | 0.0% | 0/29 | 0 | 29 |  |
| 438 | `as3/Types/Number/asin` | 0.0% | 0/34 | 0 | 34 |  |
| 439 | `as3/Types/Number/atan` | 0.0% | 0/33 | 0 | 33 |  |
| 440 | `as3/Types/Number/atan2` | 0.0% | 0/72 | 0 | 72 |  |
| 441 | `as3/Types/Number/ceil` | 0.0% | 0/49 | 0 | 49 |  |
| 442 | `as3/Types/Number/cos` | 0.0% | 0/29 | 0 | 29 |  |
| 443 | `as3/Types/Number/exp` | 0.0% | 0/30 | 0 | 30 |  |
| 444 | `as3/Types/Number/floor` | 0.0% | 0/46 | 0 | 46 |  |
| 445 | `as3/Types/Number/log` | 0.0% | 0/32 | 0 | 32 |  |
| 446 | `as3/Types/Number/max` | 0.0% | 0/54 | 0 | 54 |  |
| 447 | `as3/Types/Number/min` | 0.0% | 0/54 | 0 | 54 |  |
| 448 | `as3/Types/Number/pow` | 0.0% | 0/96 | 0 | 96 |  |
| 449 | `as3/Types/Number/random` | 0.0% | 0/4 | 0 | 4 |  |
| 450 | `as3/Types/Number/round` | 0.0% | 0/54 | 0 | 54 |  |
| 451 | `as3/Types/Number/sin` | 0.0% | 0/28 | 0 | 28 |  |
| 452 | `as3/Types/Number/sqrt` | 0.0% | 0/69 | 0 | 69 |  |
| 453 | `as3/Types/Number/tan` | 0.0% | 0/28 | 0 | 28 |  |
| 454 | `as3/Types/Number/visibility/v16` | 0.0% | 0/9 | 0 | 9 |  |
| 455 | `as3/Vector/nonindexproperty/v10` | 0.0% | 0/51 | 0 | 51 |  |
| 456 | `as3/Vector/nonindexproperty/v11` | 0.0% | 0/55 | 0 | 55 |  |
| 457 | `e4x/Global/e13_1_2_1` | 0.0% | 0/10 | 0 | 10 |  |
| 458 | `e4x/Global/isXMLNameTypeErr` | 0.0% | 0/5 | 2 | 5 |  |
| 459 | `e4x/Regress/regress-263935` | 0.0% | 0/2 | 2 | 2 |  |
| 460 | `ecma3/Array/e15_4_3_2` | 0.0% | 0/1 | 1 | 1 |  |
| 461 | `ecma3/Array/e15_4_4_13` | 0.0% | 0/7 | 0 | 7 |  |
| 462 | `ecma3/Array/e15_4_4_4_1` | 0.0% | 0/1046 | 0 | 1046 |  |
| 463 | `ecma3/Array/e15_4_4_4_2` | 0.0% | 0/4 | 0 | 4 |  |
| 464 | `ecma3/Array/e15_4_4_5` | 0.0% | 0/15 | 0 | 15 |  |
| 465 | `ecma3/Boolean/e15_6_3_1` | 0.0% | 0/2 | 2 | 2 |  |
| 466 | `ecma3/Boolean/e15_6_3_1_2` | 0.0% | 0/1 | 1 | 1 |  |
| 467 | `ecma3/Boolean/e15_6_3_1_3` | 0.0% | 0/1 | 1 | 1 |  |
| 468 | `ecma3/Date/e15_9_1_1_1` | 0.0% | 0/686 | 0 | 686 |  |
| 469 | `ecma3/Date/e15_9_1_1_2` | 0.0% | 0/685 | 0 | 685 |  |
| 470 | `ecma3/Date/e15_9_2_1` | 0.0% | 0/24 | 0 | 24 |  |
| 471 | `ecma3/Date/e15_9_2_2_1` | 0.0% | 0/24 | 0 | 24 |  |
| 472 | `ecma3/Date/e15_9_2_2_2` | 0.0% | 0/20 | 0 | 20 |  |
| 473 | `ecma3/Date/e15_9_2_2_3` | 0.0% | 0/15 | 0 | 15 |  |
| 474 | `ecma3/Date/e15_9_2_2_4` | 0.0% | 0/3 | 0 | 3 |  |
| 475 | `ecma3/Date/e15_9_2_2_5` | 0.0% | 0/4 | 0 | 4 |  |
| 476 | `ecma3/Date/e15_9_2_2_6` | 0.0% | 0/4 | 0 | 4 |  |
| 477 | `ecma3/Date/e15_9_3_1_1` | 0.0% | 0/648 | 0 | 648 |  |
| 478 | `ecma3/Date/e15_9_3_1_2` | 0.0% | 0/90 | 0 | 90 |  |
| 479 | `ecma3/Date/e15_9_3_1_3` | 0.0% | 0/54 | 0 | 54 |  |
| 480 | `ecma3/Date/e15_9_3_1_4` | 0.0% | 0/90 | 0 | 90 |  |
| 481 | `ecma3/Date/e15_9_3_1_5` | 0.0% | 0/36 | 0 | 36 |  |
| 482 | `ecma3/Date/e15_9_3_2_1` | 0.0% | 0/90 | 0 | 90 |  |
| 483 | `ecma3/Date/e15_9_3_2_2` | 0.0% | 0/54 | 0 | 54 |  |
| 484 | `ecma3/Date/e15_9_3_2_3` | 0.0% | 0/72 | 0 | 72 |  |
| 485 | `ecma3/Date/e15_9_3_2_4` | 0.0% | 0/54 | 0 | 54 |  |
| 486 | `ecma3/Date/e15_9_3_2_5` | 0.0% | 0/36 | 0 | 36 |  |
| 487 | `ecma3/Date/e15_9_3_8_1` | 0.0% | 0/90 | 0 | 90 |  |
| 488 | `ecma3/Date/e15_9_3_8_2` | 0.0% | 0/90 | 0 | 90 |  |
| 489 | `ecma3/Date/e15_9_3_8_3` | 0.0% | 0/108 | 0 | 108 |  |
| 490 | `ecma3/Date/e15_9_3_8_4` | 0.0% | 0/72 | 0 | 72 |  |
| 491 | `ecma3/Date/e15_9_3_8_5` | 0.0% | 0/108 | 0 | 108 |  |
| 492 | `ecma3/Date/e15_9_4_2` | 0.0% | 0/391 | 0 | 391 |  |
| 493 | `ecma3/Date/e15_9_4_2_1` | 0.0% | 0/4 | 0 | 4 |  |
| 494 | `ecma3/Date/e15_9_4_3` | 0.0% | 0/40 | 0 | 40 |  |
| 495 | `ecma3/Date/e15_9_5` | 0.0% | 0/1 | 0 | 1 |  |
| 496 | `ecma3/Date/e15_9_5_1` | 0.0% | 0/1 | 0 | 1 |  |
| 497 | `ecma3/Date/e15_9_5_10` | 0.0% | 0/121 | 0 | 121 |  |
| 498 | `ecma3/Date/e15_9_5_10_10` | 0.0% | 0/33 | 0 | 33 |  |
| 499 | `ecma3/Date/e15_9_5_10_11` | 0.0% | 0/95 | 0 | 95 |  |
| 500 | `ecma3/Date/e15_9_5_10_12` | 0.0% | 0/64 | 0 | 64 |  |
| 501 | `ecma3/Date/e15_9_5_10_13` | 0.0% | 0/33 | 0 | 33 |  |
| 502 | `ecma3/Date/e15_9_5_10_3` | 0.0% | 0/31 | 0 | 31 |  |
| 503 | `ecma3/Date/e15_9_5_10_4` | 0.0% | 0/31 | 0 | 31 |  |
| 504 | `ecma3/Date/e15_9_5_10_5` | 0.0% | 0/31 | 0 | 31 |  |
| 505 | `ecma3/Date/e15_9_5_10_6` | 0.0% | 0/32 | 0 | 32 |  |
| 506 | `ecma3/Date/e15_9_5_10_7` | 0.0% | 0/31 | 0 | 31 |  |
| 507 | `ecma3/Date/e15_9_5_10_8` | 0.0% | 0/33 | 0 | 33 |  |
| 508 | `ecma3/Date/e15_9_5_10_9` | 0.0% | 0/33 | 0 | 33 |  |
| 509 | `ecma3/Date/e15_9_5_11` | 0.0% | 0/33 | 0 | 33 |  |
| 510 | `ecma3/Date/e15_9_5_11_1` | 0.0% | 0/55 | 0 | 55 |  |
| 511 | `ecma3/Date/e15_9_5_11_3` | 0.0% | 0/55 | 0 | 55 |  |
| 512 | `ecma3/Date/e15_9_5_11_4` | 0.0% | 0/55 | 0 | 55 |  |
| 513 | `ecma3/Date/e15_9_5_11_5` | 0.0% | 0/55 | 0 | 55 |  |
| 514 | `ecma3/Date/e15_9_5_11_6` | 0.0% | 0/55 | 0 | 55 |  |
| 515 | `ecma3/Date/e15_9_5_11_7` | 0.0% | 0/55 | 0 | 55 |  |
| 516 | `ecma3/Date/e15_9_5_12` | 0.0% | 0/33 | 0 | 33 |  |
| 517 | `ecma3/Date/e15_9_5_12_3` | 0.0% | 0/67 | 0 | 67 |  |
| 518 | `ecma3/Date/e15_9_5_12_4` | 0.0% | 0/67 | 0 | 67 |  |
| 519 | `ecma3/Date/e15_9_5_12_5` | 0.0% | 0/67 | 0 | 67 |  |
| 520 | `ecma3/Date/e15_9_5_12_6` | 0.0% | 0/55 | 0 | 55 |  |
| 521 | `ecma3/Date/e15_9_5_12_7` | 0.0% | 0/67 | 0 | 67 |  |
| 522 | `ecma3/Date/e15_9_5_12_8` | 0.0% | 0/2 | 0 | 2 |  |
| 523 | `ecma3/Date/e15_9_5_13` | 0.0% | 0/33 | 0 | 33 |  |
| 524 | `ecma3/Date/e15_9_5_13_1` | 0.0% | 0/36 | 0 | 36 |  |
| 525 | `ecma3/Date/e15_9_5_13_2` | 0.0% | 0/36 | 0 | 36 |  |
| 526 | `ecma3/Date/e15_9_5_13_3` | 0.0% | 0/36 | 0 | 36 |  |
| 527 | `ecma3/Date/e15_9_5_13_4` | 0.0% | 0/36 | 0 | 36 |  |
| 528 | `ecma3/Date/e15_9_5_13_5` | 0.0% | 0/36 | 0 | 36 |  |
| 529 | `ecma3/Date/e15_9_5_13_6` | 0.0% | 0/60 | 0 | 60 |  |
| 530 | `ecma3/Date/e15_9_5_13_7` | 0.0% | 0/60 | 0 | 60 |  |
| 531 | `ecma3/Date/e15_9_5_13_8` | 0.0% | 0/2 | 0 | 2 |  |
| 532 | `ecma3/Date/e15_9_5_14` | 0.0% | 0/44 | 0 | 44 |  |
| 533 | `ecma3/Date/e15_9_5_15` | 0.0% | 0/58 | 0 | 58 |  |
| 534 | `ecma3/Date/e15_9_5_15_1` | 0.0% | 0/33 | 0 | 33 |  |
| 535 | `ecma3/Date/e15_9_5_16` | 0.0% | 0/51 | 0 | 51 |  |
| 536 | `ecma3/Date/e15_9_5_17` | 0.0% | 0/51 | 0 | 51 |  |
| 537 | `ecma3/Date/e15_9_5_17_1` | 0.0% | 0/33 | 0 | 33 |  |
| 538 | `ecma3/Date/e15_9_5_18` | 0.0% | 0/51 | 0 | 51 |  |
| 539 | `ecma3/Date/e15_9_5_19` | 0.0% | 0/51 | 0 | 51 |  |
| 540 | `ecma3/Date/e15_9_5_2` | 0.0% | 0/15 | 0 | 15 |  |
| 541 | `ecma3/Date/e15_9_5_20` | 0.0% | 0/79 | 0 | 79 |  |
| 542 | `ecma3/Date/e15_9_5_21_1` | 0.0% | 0/9 | 0 | 9 |  |
| 543 | `ecma3/Date/e15_9_5_21_2` | 0.0% | 0/1 | 0 | 1 |  |
| 544 | `ecma3/Date/e15_9_5_21_3` | 0.0% | 0/1 | 0 | 1 |  |
| 545 | `ecma3/Date/e15_9_5_21_4` | 0.0% | 0/1 | 0 | 1 |  |
| 546 | `ecma3/Date/e15_9_5_21_5` | 0.0% | 0/1 | 0 | 1 |  |
| 547 | `ecma3/Date/e15_9_5_21_6` | 0.0% | 0/1 | 0 | 1 |  |
| 548 | `ecma3/Date/e15_9_5_21_7` | 0.0% | 0/1 | 0 | 1 |  |
| 549 | `ecma3/Date/e15_9_5_21_8` | 0.0% | 0/2 | 0 | 2 |  |
| 550 | `ecma3/Date/e15_9_5_22_1` | 0.0% | 0/68 | 0 | 68 |  |
| 551 | `ecma3/Date/e15_9_5_22_2` | 0.0% | 0/11 | 0 | 11 |  |
| 552 | `ecma3/Date/e15_9_5_22_3` | 0.0% | 0/11 | 0 | 11 |  |
| 553 | `ecma3/Date/e15_9_5_22_4` | 0.0% | 0/11 | 0 | 11 |  |
| 554 | `ecma3/Date/e15_9_5_22_5` | 0.0% | 0/11 | 0 | 11 |  |
| 555 | `ecma3/Date/e15_9_5_22_6` | 0.0% | 0/11 | 0 | 11 |  |
| 556 | `ecma3/Date/e15_9_5_22_7` | 0.0% | 0/11 | 0 | 11 |  |
| 557 | `ecma3/Date/e15_9_5_22_8` | 0.0% | 0/2 | 0 | 2 |  |
| 558 | `ecma3/Date/e15_9_5_23_1` | 0.0% | 0/18 | 0 | 18 |  |
| 559 | `ecma3/Date/e15_9_5_23_10` | 0.0% | 0/18 | 0 | 18 |  |
| 560 | `ecma3/Date/e15_9_5_23_11` | 0.0% | 0/18 | 0 | 18 |  |
| 561 | `ecma3/Date/e15_9_5_23_12` | 0.0% | 0/18 | 0 | 18 |  |
| 562 | `ecma3/Date/e15_9_5_23_13` | 0.0% | 0/18 | 0 | 18 |  |
| 563 | `ecma3/Date/e15_9_5_23_14` | 0.0% | 0/18 | 0 | 18 |  |
| 564 | `ecma3/Date/e15_9_5_23_15` | 0.0% | 0/18 | 0 | 18 |  |
| 565 | `ecma3/Date/e15_9_5_23_16` | 0.0% | 0/18 | 0 | 18 |  |
| 566 | `ecma3/Date/e15_9_5_23_17` | 0.0% | 0/18 | 0 | 18 |  |
| 567 | `ecma3/Date/e15_9_5_23_18` | 0.0% | 0/18 | 0 | 18 |  |
| 568 | `ecma3/Date/e15_9_5_23_2` | 0.0% | 0/26 | 0 | 26 |  |
| 569 | `ecma3/Date/e15_9_5_23_3_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 570 | `ecma3/Date/e15_9_5_23_4` | 0.0% | 0/44 | 0 | 44 |  |
| 571 | `ecma3/Date/e15_9_5_23_5` | 0.0% | 0/44 | 0 | 44 |  |
| 572 | `ecma3/Date/e15_9_5_23_6` | 0.0% | 0/44 | 0 | 44 |  |
| 573 | `ecma3/Date/e15_9_5_23_7` | 0.0% | 0/44 | 0 | 44 |  |
| 574 | `ecma3/Date/e15_9_5_23_8` | 0.0% | 0/42 | 0 | 42 |  |
| 575 | `ecma3/Date/e15_9_5_23_9` | 0.0% | 0/42 | 0 | 42 |  |
| 576 | `ecma3/Date/e15_9_5_24_1` | 0.0% | 0/16 | 0 | 16 |  |
| 577 | `ecma3/Date/e15_9_5_24_2` | 0.0% | 0/16 | 0 | 16 |  |
| 578 | `ecma3/Date/e15_9_5_24_3` | 0.0% | 0/16 | 0 | 16 |  |
| 579 | `ecma3/Date/e15_9_5_24_4` | 0.0% | 0/16 | 0 | 16 |  |
| 580 | `ecma3/Date/e15_9_5_24_5` | 0.0% | 0/16 | 0 | 16 |  |
| 581 | `ecma3/Date/e15_9_5_24_6` | 0.0% | 0/16 | 0 | 16 |  |
| 582 | `ecma3/Date/e15_9_5_24_7` | 0.0% | 0/16 | 0 | 16 |  |
| 583 | `ecma3/Date/e15_9_5_24_8` | 0.0% | 0/16 | 0 | 16 |  |
| 584 | `ecma3/Date/e15_9_5_25_1` | 0.0% | 0/153 | 0 | 153 |  |
| 585 | `ecma3/Date/e15_9_5_26_1` | 0.0% | 0/119 | 0 | 119 |  |
| 586 | `ecma3/Date/e15_9_5_27_1` | 0.0% | 0/119 | 0 | 119 |  |
| 587 | `ecma3/Date/e15_9_5_28_1` | 0.0% | 0/136 | 0 | 136 |  |
| 588 | `ecma3/Date/e15_9_5_29_1` | 0.0% | 0/119 | 0 | 119 |  |
| 589 | `ecma3/Date/e15_9_5_2_1` | 0.0% | 0/15 | 0 | 15 |  |
| 590 | `ecma3/Date/e15_9_5_2_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 591 | `ecma3/Date/e15_9_5_3` | 0.0% | 0/15 | 0 | 15 |  |
| 592 | `ecma3/Date/e15_9_5_30_1` | 0.0% | 0/144 | 0 | 144 |  |
| 593 | `ecma3/Date/e15_9_5_31_1` | 0.0% | 0/126 | 0 | 126 |  |
| 594 | `ecma3/Date/e15_9_5_32_1` | 0.0% | 0/180 | 0 | 180 |  |
| 595 | `ecma3/Date/e15_9_5_33_1` | 0.0% | 0/54 | 0 | 54 |  |
| 596 | `ecma3/Date/e15_9_5_34_1` | 0.0% | 0/164 | 0 | 164 |  |
| 597 | `ecma3/Date/e15_9_5_35_1` | 0.0% | 0/54 | 0 | 54 |  |
| 598 | `ecma3/Date/e15_9_5_36_1` | 0.0% | 0/54 | 0 | 54 |  |
| 599 | `ecma3/Date/e15_9_5_36_2` | 0.0% | 0/54 | 0 | 54 |  |
| 600 | `ecma3/Date/e15_9_5_36_3` | 0.0% | 0/54 | 0 | 54 |  |
| 601 | `ecma3/Date/e15_9_5_36_4` | 0.0% | 0/54 | 0 | 54 |  |
| 602 | `ecma3/Date/e15_9_5_36_5` | 0.0% | 0/162 | 0 | 162 |  |
| 603 | `ecma3/Date/e15_9_5_36_6` | 0.0% | 0/108 | 0 | 108 |  |
| 604 | `ecma3/Date/e15_9_5_36_7` | 0.0% | 0/54 | 0 | 54 |  |
| 605 | `ecma3/Date/e15_9_5_37_1` | 0.0% | 0/360 | 0 | 360 |  |
| 606 | `ecma3/Date/e15_9_5_37_2` | 0.0% | 0/54 | 0 | 54 |  |
| 607 | `ecma3/Date/e15_9_5_37_3` | 0.0% | 0/36 | 0 | 36 |  |
| 608 | `ecma3/Date/e15_9_5_37_4` | 0.0% | 0/54 | 0 | 54 |  |
| 609 | `ecma3/Date/e15_9_5_37_5` | 0.0% | 0/54 | 0 | 54 |  |
| 610 | `ecma3/Date/e15_9_5_3_1_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 611 | `ecma3/Date/e15_9_5_3_2` | 0.0% | 0/30 | 0 | 30 |  |
| 612 | `ecma3/Date/e15_9_5_4` | 0.0% | 0/16 | 0 | 16 |  |
| 613 | `ecma3/Date/e15_9_5_42` | 0.0% | 0/15 | 0 | 15 |  |
| 614 | `ecma3/Date/e15_9_5_4_1` | 0.0% | 0/30 | 0 | 30 |  |
| 615 | `ecma3/Date/e15_9_5_4_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 616 | `ecma3/Date/e15_9_5_5` | 0.0% | 0/15 | 0 | 15 |  |
| 617 | `ecma3/Date/e15_9_5_6` | 0.0% | 0/15 | 0 | 15 |  |
| 618 | `ecma3/Date/e15_9_5_7` | 0.0% | 0/16 | 0 | 16 |  |
| 619 | `ecma3/Exceptions/date_002_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 620 | `ecma3/Exceptions/date_004_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 621 | `ecma3/Exceptions/exception_001_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 622 | `ecma3/Exceptions/exception_002_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 623 | `ecma3/Exceptions/expression_005_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 624 | `ecma3/Exceptions/number_001_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 625 | `ecma3/Exceptions/number_002_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 626 | `ecma3/Exceptions/string_001_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 627 | `ecma3/Exceptions/string_002_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 628 | `ecma3/Expressions/e11_2_2_10_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 629 | `ecma3/FunctionObjects/e15_3_1_1_2_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 630 | `ecma3/FunctionObjects/e15_3_1_1_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 631 | `ecma3/FunctionObjects/e15_3_2_1_2_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 632 | `ecma3/FunctionObjects/e15_3_2_1_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 633 | `ecma3/FunctionObjects/e15_3_3_2` | 0.0% | 0/1 | 1 | 1 |  |
| 634 | `ecma3/FunctionObjects/e15_3_5_3_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 635 | `ecma3/GlobalObject/decodeURI` | 0.0% | 0/38 | 0 | 38 |  |
| 636 | `ecma3/GlobalObject/decodeURIComponent` | 0.0% | 0/24 | 0 | 24 |  |
| 637 | `ecma3/GlobalObject/e15_1_2_1_2_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 638 | `ecma3/GlobalObject/e15_1_3` | 0.0% | 0/2 | 2 | 2 |  |
| 639 | `ecma3/GlobalObject/encodeURI` | 0.0% | 0/39 | 0 | 39 |  |
| 640 | `ecma3/GlobalObject/encodeURIComponent` | 0.0% | 0/23 | 0 | 23 |  |
| 641 | `ecma3/Number/e15_7_3_2_2` | 0.0% | 0/2 | 2 | 2 |  |
| 642 | `ecma3/Number/e15_7_3_2_3` | 0.0% | 0/2 | 2 | 2 |  |
| 643 | `ecma3/Number/e15_7_3_3_2` | 0.0% | 0/2 | 2 | 2 |  |
| 644 | `ecma3/Number/e15_7_3_4_2` | 0.0% | 0/2 | 2 | 2 |  |
| 645 | `ecma3/Number/e15_7_3_5_2` | 0.0% | 0/2 | 2 | 2 |  |
| 646 | `ecma3/Number/e15_7_3_5_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 647 | `ecma3/Number/e15_7_3_6_2` | 0.0% | 0/2 | 2 | 2 |  |
| 648 | `ecma3/Number/e15_7_3_6_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 649 | `ecma3/Number/e15_7_4_2_2_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 650 | `ecma3/Number/eregress_121952` | 0.0% | 0/12 | 0 | 12 |  |
| 651 | `ecma3/ObjectObjects/class_006` | 0.0% | 0/1 | 1 | 1 |  |
| 652 | `ecma3/ObjectObjects/e15_2_3_1_2` | 0.0% | 0/1 | 1 | 1 |  |
| 653 | `ecma3/ObjectObjects/e15_2_3_1_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 654 | `ecma3/ObjectObjects/e15_2_3_rt` | 0.0% | 0/2 | 2 | 2 |  |
| 655 | `ecma3/Statements/e12_10` | 0.0% | 0/1 | 1 | 1 |  |
| 656 | `ecma3/Statements/eforin_002` | 0.0% | 0/10 | 10 | 10 |  |
| 657 | `ecma3/String/concat` | 0.0% | 0/21 | 0 | 21 |  |
| 658 | `ecma3/String/e15_5_3_1_3` | 0.0% | 0/1 | 1 | 1 |  |
| 659 | `ecma3/String/e15_5_4_10_1_rt` | 0.0% | 0/24 | 0 | 24 |  |
| 660 | `ecma3/String/e15_5_4_11_1` | 0.0% | 0/387 | 0 | 387 |  |
| 661 | `ecma3/String/e15_5_4_11_5` | 0.0% | 0/131 | 0 | 131 |  |
| 662 | `ecma3/String/e15_5_4_12_1` | 0.0% | 0/387 | 0 | 387 |  |
| 663 | `ecma3/String/e15_5_4_13` | 0.0% | 0/17 | 0 | 17 |  |
| 664 | `ecma3/String/e15_5_4_4_3` | 0.0% | 0/18 | 0 | 18 |  |
| 665 | `ecma3/String/e15_5_4_5_2` | 0.0% | 0/31 | 0 | 31 |  |
| 666 | `ecma3/String/e15_5_4_5_3` | 0.0% | 0/28 | 0 | 28 |  |
| 667 | `ecma3/String/e15_5_4_5_5` | 0.0% | 0/269 | 0 | 269 |  |
| 668 | `ecma3/String/e15_5_4_7_2` | 0.0% | 0/72 | 0 | 72 |  |
| 669 | `ecma3/String/e15_5_4_8_1_rt` | 0.0% | 0/30 | 0 | 30 |  |
| 670 | `ecma3/String/e15_5_4_9_1_rt` | 0.0% | 0/22 | 0 | 22 |  |
| 671 | `ecma3/String/ematch_004` | 0.0% | 0/8 | 0 | 8 |  |
| 672 | `ecma3/String/substr` | 0.0% | 0/24 | 0 | 24 |  |
| 673 | `ecma3/String/toLocaleLowerCase` | 0.0% | 0/387 | 0 | 387 |  |
| 674 | `ecma3/String/toLocaleLowerCase5` | 0.0% | 0/131 | 0 | 131 |  |
| 675 | `ecma3/String/toLocaleUpperCase5` | 0.0% | 0/387 | 0 | 387 |  |
| 676 | `recursion/pcre_could_be_empty_branch` | 0.0% | 0/1 | 1 | 1 |  |
| 677 | `regress/bug_538107` | 0.0% | 0/2 | 0 | 2 |  |
| 678 | `regress/bug_551587_2_swf10` | 0.0% | 0/2 | 0 | 2 |  |
| 679 | `regress/bug_551587_2_swf11` | 0.0% | 0/2 | 0 | 2 |  |
| 680 | `regress/bug_558863_swf11` | 0.0% | 0/1 | 1 | 1 |  |
| 681 | `regress/bug_609416_swf11` | 0.0% | 0/1 | 0 | 1 |  |
