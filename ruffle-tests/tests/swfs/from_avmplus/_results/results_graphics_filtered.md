# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 20:03 UTC

**Git SHA**: `b4d4457f16`

**Run Duration**: 191m 9s

**Filtered**: 0 tests ignored out of 1574 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1574 |
| Passing | **1490** (94.7%) |
| Ruffle-matched | 51 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1541** (97.9%) |
| Failing | 33 |
| Total expected lines | 85996 |
| Matching lines | 85300 (99.2%) |
| Mismatched lines | 696 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 29 | 87.9% |
| Runtime Error | 4 | 12.1% |

## Passing Tests

**1490 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `as3/AMF/AMFSerializer` | 225 | 9.3s |  |
| 2 | `as3/Array/regress_524122_swf10` | 1 | 7.5s |  |
| 3 | `as3/Array/regress_524122_swf11` | 1 | 7.6s |  |
| 4 | `as3/Array/regress_636535` | 6 | 7.6s |  |
| 5 | `as3/Array/regress_733384` | 24 | 7.6s |  |
| 6 | `as3/ByteArray/ByteArray` | 425 | 9.0s |  |
| 7 | `as3/ByteArray/ByteArrayLzma` | 397 | 8.9s |  |
| 8 | `as3/ByteArray/ByteArrayLzmaThirdParty` | 2 | 8.0s |  |
| 9 | `as3/ByteArray/ByteArray_bug662851_32bit` | 4 | 7.6s |  |
| 10 | `as3/ByteArray/ByteArray_bug662851_64bit` | 2 | 7.3s |  |
| 11 | `as3/Definitions/Classes/ClassDef/Bug118272Package` | 6 | 7.6s |  |
| 12 | `as3/Definitions/Classes/ClassDef/Bug162570` | 5 | 7.6s |  |
| 13 | `as3/Definitions/Classes/ClassDef/DefaultClass` | 15 | 7.8s |  |
| 14 | `as3/Definitions/Classes/ClassDef/DefaultClassPrototype` | 18 | 8.0s |  |
| 15 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 32 | 8.0s |  |
| 16 | `as3/Definitions/Classes/ClassDef/DynamicClass` | 15 | 8.0s |  |
| 17 | `as3/Definitions/Classes/ClassDef/DynamicClassHasOwnProperty` | 1 | 7.8s |  |
| 18 | `as3/Definitions/Classes/ClassDef/DynamicClassMeth` | 2 | 7.9s |  |
| 19 | `as3/Definitions/Classes/ClassDef/DynamicClassProp` | 12 | 7.9s |  |
| 20 | `as3/Definitions/Classes/ClassDef/DynamicClassPrototype` | 18 | 8.1s |  |
| 21 | `as3/Definitions/Classes/ClassDef/DynamicClassSameMethPropName` | 4 | 8.0s |  |
| 22 | `as3/Definitions/Classes/ClassDef/FinalClassPrototype` | 18 | 8.0s |  |
| 23 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 32 | 8.3s |  |
| 24 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 32 | 7.5s |  |
| 25 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 36 | 8.4s |  |
| 26 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 32 | 7.6s |  |
| 27 | `as3/Definitions/Classes/ClassDef/FinalPublicClass` | 40 | 8.3s |  |
| 28 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass` | 40 | 8.4s |  |
| 29 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClassMethodAndProp` | 20 | 8.2s |  |
| 30 | `as3/Definitions/Classes/ClassDef/IntClassWithStrParamCons` | 4 | 8.2s |  |
| 31 | `as3/Definitions/Classes/ClassDef/InternalClass` | 32 | 7.8s |  |
| 32 | `as3/Definitions/Classes/ClassDef/InternalClassPrototype` | 18 | 8.5s |  |
| 33 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 32 | 8.5s |  |
| 34 | `as3/Definitions/Classes/ClassDef/PrivateStaticClassMethodAndProp` | 14 | 8.3s |  |
| 35 | `as3/Definitions/Classes/ClassDef/PublicClass` | 44 | 8.6s |  |
| 36 | `as3/Definitions/Classes/ClassDef/PublicClassMethodAndProp` | 20 | 8.3s |  |
| 37 | `as3/Definitions/Classes/ClassDef/PublicClassPrototype` | 18 | 8.4s |  |
| 38 | `as3/Definitions/Classes/ClassDef/PublicDynamicClass` | 44 | 8.4s |  |
| 39 | `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp` | 22 | 8.1s |  |
| 40 | `as3/Definitions/Classes/ClassDef/StatClassSameNamePackage` | 0 | 2.0s |  |
| 41 | `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp` | 16 | 8.3s |  |
| 42 | `as3/Definitions/Classes/ClassDef/bug113887` | 2 | 8.2s |  |
| 43 | `as3/Definitions/Classes/ClassDef/dynfinClassCons` | 1 | 8.0s |  |
| 44 | `as3/Definitions/Classes/ClassDef/dynfinClassDefCons` | 1 | 7.9s |  |
| 45 | `as3/Definitions/Classes/ClassDef/dynfinClassWithMultiStrParamCons` | 3 | 8.0s |  |
| 46 | `as3/Definitions/Classes/ClassDef/dynfinClassWithParamCons` | 1 | 8.0s |  |
| 47 | `as3/Definitions/Classes/ClassDef/dynfinClassWithStrParamCons` | 4 | 7.8s |  |
| 48 | `as3/Definitions/Classes/ClassDef/finClassNoParamCons` | 1 | 7.8s |  |
| 49 | `as3/Definitions/Classes/ClassDef/finalClassDefCons` | 1 | 3.5s |  |
| 50 | `as3/Definitions/Classes/ClassDef/finalClassWithParamCons` | 1 | 3.6s |  |
| 51 | `as3/Definitions/Classes/ClassDef/intClassDefCons` | 1 | 8.3s |  |
| 52 | `as3/Definitions/Classes/ClassDef/intClassNoParamCons` | 1 | 8.3s |  |
| 53 | `as3/Definitions/Classes/ClassDef/intClassWithParamCons` | 1 | 8.1s |  |
| 54 | `as3/Definitions/Classes/ClassDef/publicClassConsNoParam` | 1 | 8.1s |  |
| 55 | `as3/Definitions/Classes/ClassDef/publicClassDefCons` | 4 | 8.1s |  |
| 56 | `as3/Definitions/Classes/ClassDef/publicClassWithParamCons` | 1 | 8.0s |  |
| 57 | `as3/Definitions/Classes/ClassDef/testClassInitializers` | 3 | 8.1s |  |
| 58 | `as3/Definitions/Classes/ClassDef/testdynfinpublicClassInitializers` | 3 | 8.0s |  |
| 59 | `as3/Definitions/Classes/ClassDef/testinternalClassInitializers` | 3 | 8.0s |  |
| 60 | `as3/Definitions/Classes/Ext/AccNSStatMethSubClassMeth` | 6 | 8.0s |  |
| 61 | `as3/Definitions/Classes/Ext/AccNSStatPropSubClassMeth` | 6 | 8.0s |  |
| 62 | `as3/Definitions/Classes/Ext/AccStatMethIntermediateSubClassMeth` | 4 | 8.0s |  |
| 63 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMeth` | 6 | 8.0s |  |
| 64 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | 1 | 8.1s |  |
| 65 | `as3/Definitions/Classes/Ext/AccStatMethSubClassStatMeth` | 4 | 8.0s |  |
| 66 | `as3/Definitions/Classes/Ext/AccStatPropIntermediateSubClassMeth` | 6 | 8.1s |  |
| 67 | `as3/Definitions/Classes/Ext/AccStatPropSubClassInit` | 6 | 7.8s |  |
| 68 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 6 | 7.9s |  |
| 69 | `as3/Definitions/Classes/Ext/AccStatPropSubClassStatMeth` | 6 | 8.0s |  |
| 70 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | 3 | 8.1s |  |
| 71 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClassWIntermediate` | 3 | 8.1s |  |
| 72 | `as3/Definitions/Classes/Ext/DynExtDefaultClass` | 23 | 8.8s |  |
| 73 | `as3/Definitions/Classes/Ext/DynExtDefaultClassFin` | 21 | 8.3s |  |
| 74 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPub` | 40 | 8.7s |  |
| 75 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPubStat` | 24 | 8.4s |  |
| 76 | `as3/Definitions/Classes/Ext/DynExtDefaultClassStat` | 21 | 8.2s |  |
| 77 | `as3/Definitions/Classes/Ext/DynExtDynamicClass` | 16 | 8.0s |  |
| 78 | `as3/Definitions/Classes/Ext/DynExtDynamicClassFin` | 20 | 8.1s |  |
| 79 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPub` | 18 | 8.0s |  |
| 80 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPubStat` | 16 | 8.1s |  |
| 81 | `as3/Definitions/Classes/Ext/DynExtDynamicClassStat` | 22 | 8.2s |  |
| 82 | `as3/Definitions/Classes/Ext/DynExtInternalClass` | 21 | 8.6s |  |
| 83 | `as3/Definitions/Classes/Ext/DynExtPublicClass` | 8 | 8.1s |  |
| 84 | `as3/Definitions/Classes/Ext/DynExtPublicClassFin` | 24 | 8.3s |  |
| 85 | `as3/Definitions/Classes/Ext/DynExtPublicClassPub` | 16 | 8.1s |  |
| 86 | `as3/Definitions/Classes/Ext/DynExtPublicClassPubStat` | 14 | 8.2s |  |
| 87 | `as3/Definitions/Classes/Ext/DynExtPublicClassStat` | 14 | 8.2s |  |
| 88 | `as3/Definitions/Classes/Ext/ExtDefaultClass` | 20 | 8.6s |  |
| 89 | `as3/Definitions/Classes/Ext/ExtDefaultClassPub` | 14 | 8.2s |  |
| 90 | `as3/Definitions/Classes/Ext/ExtDefaultClassPubStat` | 26 | 8.4s |  |
| 91 | `as3/Definitions/Classes/Ext/ExtDefaultClassStat` | 25 | 8.4s |  |
| 92 | `as3/Definitions/Classes/Ext/ExtDefaultProtClass` | 20 | 8.6s |  |
| 93 | `as3/Definitions/Classes/Ext/ExtDynamicClass` | 19 | 8.2s |  |
| 94 | `as3/Definitions/Classes/Ext/ExtDynamicClassPub` | 21 | 8.2s |  |
| 95 | `as3/Definitions/Classes/Ext/ExtDynamicClassPubStat` | 26 | 8.3s |  |
| 96 | `as3/Definitions/Classes/Ext/ExtDynamicClassStat` | 24 | 8.3s |  |
| 97 | `as3/Definitions/Classes/Ext/ExtError` | 40 | 8.2s |  |
| 98 | `as3/Definitions/Classes/Ext/ExtInternalClass` | 20 | 8.7s |  |
| 99 | `as3/Definitions/Classes/Ext/ExtPublicClass` | 7 | 8.3s |  |
| 100 | `as3/Definitions/Classes/Ext/ExtPublicClassFin` | 10 | 8.3s |  |
| 101 | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 6 | 8.3s |  |
| 102 | `as3/Definitions/Classes/Ext/ExtPublicClassPub` | 14 | 8.4s |  |
| 103 | `as3/Definitions/Classes/Ext/ExtPublicClassStat` | 28 | 8.4s |  |
| 104 | `as3/Definitions/Classes/Ext/IntExtDefaultClass` | 22 | 8.3s |  |
| 105 | `as3/Definitions/Classes/Ext/IntExtDynamicClass` | 20 | 8.3s |  |
| 106 | `as3/Definitions/Classes/Ext/IntExtInternalClass` | 20 | 8.4s |  |
| 107 | `as3/Definitions/Classes/Ext/IntExtPublicClass` | 20 | 8.3s |  |
| 108 | `as3/Definitions/Classes/Ext/PubExtDefaultClass` | 19 | 7.8s |  |
| 109 | `as3/Definitions/Classes/Ext/PubExtDefaultClassFin` | 16 | 7.8s |  |
| 110 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPub` | 20 | 7.9s |  |
| 111 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPubStat` | 29 | 8.1s |  |
| 112 | `as3/Definitions/Classes/Ext/PubExtDefaultClassStat` | 27 | 8.1s |  |
| 113 | `as3/Definitions/Classes/Ext/PubExtDynamicClass` | 18 | 7.8s |  |
| 114 | `as3/Definitions/Classes/Ext/PubExtDynamicClassFin` | 18 | 7.8s |  |
| 115 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPub` | 20 | 7.9s |  |
| 116 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPubStat` | 29 | 8.0s |  |
| 117 | `as3/Definitions/Classes/Ext/PubExtDynamicClassStat` | 29 | 7.3s |  |
| 118 | `as3/Definitions/Classes/Ext/PubExtInternalClass` | 17 | 8.1s |  |
| 119 | `as3/Definitions/Classes/Ext/PubExtPublicClass` | 12 | 8.0s |  |
| 120 | `as3/Definitions/Classes/Ext/PubExtPublicClassFin` | 16 | 8.0s |  |
| 121 | `as3/Definitions/Classes/Ext/PubExtPublicClassStat` | 27 | 8.2s |  |
| 122 | `as3/Definitions/Classes/Ext/PubFinExtDefaultClass` | 22 | 8.2s |  |
| 123 | `as3/Definitions/Function/EmptyFunctionBody` | 24 | 7.9s |  |
| 124 | `as3/Definitions/Function/EmptyFunctionName` | 52 | 8.1s |  |
| 125 | `as3/Definitions/Function/FinalFunctionBody` | 12 | 7.8s |  |
| 126 | `as3/Definitions/Function/FinalFunctionName` | 28 | 7.8s |  |
| 127 | `as3/Definitions/Function/MultiOptArgFunction` | 12 | 7.9s |  |
| 128 | `as3/Definitions/Function/MultipleExtraArgFunction1` | 4 | 7.5s |  |
| 129 | `as3/Definitions/Function/MultipleExtraArgFunction2` | 4 | 7.5s |  |
| 130 | `as3/Definitions/Function/MultipleExtraArgFunction3` | 4 | 8.3s |  |
| 131 | `as3/Definitions/Function/NamespaceFunctionBody` | 12 | 8.3s |  |
| 132 | `as3/Definitions/Function/NamespaceFunctionName` | 28 | 7.9s |  |
| 133 | `as3/Definitions/Function/NoExtraArgFunction` | 4 | 7.8s |  |
| 134 | `as3/Definitions/Function/OneExtraArgFunction` | 20 | 3.7s |  |
| 135 | `as3/Definitions/Function/OneOptArgFunction` | 12 | 7.6s |  |
| 136 | `as3/Definitions/Function/OverrideFunctionBody` | 12 | 7.6s |  |
| 137 | `as3/Definitions/Function/OverrideFunctionName` | 28 | 7.8s |  |
| 138 | `as3/Definitions/Function/PrivateFunctionBody` | 12 | 7.6s |  |
| 139 | `as3/Definitions/Function/PrivateFunctionName` | 26 | 8.2s |  |
| 140 | `as3/Definitions/Function/PublicFunctionBody` | 24 | 8.4s |  |
| 141 | `as3/Definitions/Function/PublicFunctionName` | 54 | 8.4s |  |
| 142 | `as3/Definitions/Function/RestGlobal` | 17 | 7.8s |  |
| 143 | `as3/Definitions/Function/StaticFunctionBody` | 12 | 7.8s |  |
| 144 | `as3/Definitions/Function/StaticFunctionName` | 26 | 7.7s |  |
| 145 | `as3/Definitions/Function/StaticPrivateFunctionName` | 13 | 7.6s |  |
| 146 | `as3/Definitions/Function/StaticPublicFunctionName` | 13 | 7.7s |  |
| 147 | `as3/Definitions/Function/ThreeOptArgFunction` | 4 | 7.7s |  |
| 148 | `as3/Definitions/Function/VirtualFunctionBody` | 12 | 3.7s |  |
| 149 | `as3/Definitions/Function/VirtualFunctionName` | 28 | 7.2s |  |
| 150 | `as3/Definitions/Function/VoidEvaluation` | 3 | 7.6s |  |
| 151 | `as3/Definitions/Function/bug152222` | 2 | 7.5s |  |
| 152 | `as3/Definitions/Function/functionReturnTypes` | 319 | 9.3s |  |
| 153 | `as3/Definitions/Interfaces/Example_1_1_6` | 2 | 7.5s |  |
| 154 | `as3/Definitions/Interfaces/Example_9_3` | 4 | 7.5s |  |
| 155 | `as3/Definitions/Interfaces/ExtendMultipleInterfaces` | 8 | 7.7s |  |
| 156 | `as3/Definitions/Interfaces/GetSet` | 10 | 7.5s |  |
| 157 | `as3/Definitions/Interfaces/ImplementByExtension` | 6 | 6.7s |  |
| 158 | `as3/Definitions/Interfaces/ImplementMultipleInterfaces` | 8 | 6.4s |  |
| 159 | `as3/Definitions/Interfaces/InterfaceAsType` | 11 | 6.4s |  |
| 160 | `as3/Definitions/Interfaces/Lattice` | 7 | 6.3s |  |
| 161 | `as3/Definitions/Interfaces/bug127174` | 1 | 6.1s |  |
| 162 | `as3/Definitions/Super/SuperArgsCall` | 4 | 6.2s |  |
| 163 | `as3/Definitions/Super/SuperExprChainAccess` | 10 | 6.4s |  |
| 164 | `as3/Definitions/Super/SuperImplicitlyCalled` | 4 | 6.2s |  |
| 165 | `as3/Definitions/Super/SuperObject` | 1 | 6.2s |  |
| 166 | `as3/Definitions/Super/SuperObjectCall` | 1 | 6.1s |  |
| 167 | `as3/Definitions/Super/SuperRuntimeError` | 3 | 6.2s |  |
| 168 | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | 1 | 6.2s |  |
| 169 | `as3/Definitions/Variable/ConstVariables_custom1` | 17 | 6.3s |  |
| 170 | `as3/Definitions/Variable/ConstVariables_custom2` | 22 | 6.2s |  |
| 171 | `as3/Definitions/Variable/ModifyClassConstGlobally_rt` | 1 | 6.2s |  |
| 172 | `as3/Definitions/Variable/ModifyClassVariableInObjectInstance_rt` | 1 | 6.2s |  |
| 173 | `as3/Definitions/Variable/ModifyPackageConstGlobally_rt` | 1 | 6.2s |  |
| 174 | `as3/Definitions/Variable/ModifyVariables` | 25 | 6.3s |  |
| 175 | `as3/Definitions/Variable/ProtectedVariables` | 8 | 6.2s |  |
| 176 | `as3/Definitions/Variable/VarDefEmpty` | 44 | 6.5s |  |
| 177 | `as3/Definitions/Variable/VarDefOutside` | 20 | 6.1s |  |
| 178 | `as3/Definitions/Variable/VarDefOutsideNoVar` | 9 | 6.1s |  |
| 179 | `as3/Definitions/Variable/VarDefPrivate` | 44 | 6.5s |  |
| 180 | `as3/Definitions/Variable/VarDefPrivateStatic` | 44 | 6.7s |  |
| 181 | `as3/Definitions/Variable/VarDefPublic` | 44 | 6.5s |  |
| 182 | `as3/Definitions/Variable/VarDefPublicStatic` | 44 | 6.7s |  |
| 183 | `as3/Definitions/Variable/VarDefStatic` | 44 | 5.8s |  |
| 184 | `as3/Definitions/const/ConstAccessFromClass` | 1 | 6.1s |  |
| 185 | `as3/Definitions/const/ConstAccessWithinClass` | 1 | 6.1s |  |
| 186 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName` | 1 | 6.2s |  |
| 187 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName2` | 1 | 6.1s |  |
| 188 | `as3/Definitions/const/ConstAndFunctionArgWithSameName` | 1 | 6.1s |  |
| 189 | `as3/Definitions/const/ConstAndFunctionArgWithSameName2` | 1 | 6.0s |  |
| 190 | `as3/Definitions/const/ConstAsVarReplacement` | 1 | 6.1s |  |
| 191 | `as3/Definitions/const/ConstConditionalInitialization` | 1 | 6.7s |  |
| 192 | `as3/Definitions/const/ConstConditionalInitializationInClass` | 1 | 6.3s |  |
| 193 | `as3/Definitions/const/ConstConditionalInitializationInClass2` | 1 | 6.3s |  |
| 194 | `as3/Definitions/const/ConstConditionalInitializationInClass3_rt` | 1 | 6.1s |  |
| 195 | `as3/Definitions/const/ConstConditionalInitializationInFunc` | 1 | 6.1s |  |
| 196 | `as3/Definitions/const/ConstInPackage` | 1 | 6.2s |  |
| 197 | `as3/Definitions/const/ConstInPackage2` | 1 | 6.1s |  |
| 198 | `as3/Definitions/const/ConstInPackageWithClass` | 1 | 6.1s |  |
| 199 | `as3/Definitions/const/ConstInPackageWithFunction` | 1 | 6.1s |  |
| 200 | `as3/Definitions/const/ConstInitializationInsideConstructor` | 1 | 2.8s |  |
| 201 | `as3/Definitions/const/ConstInitializationOutsideClass_rt` | 1 | 6.1s |  |
| 202 | `as3/Definitions/const/ConstInsideClass` | 1 | 6.5s |  |
| 203 | `as3/Definitions/const/ConstKeyword` | 1 | 6.0s |  |
| 204 | `as3/Definitions/const/ConstReinit_rt` | 1 | 6.2s |  |
| 205 | `as3/Definitions/const/ConstVarAsClassProp` | 2 | 6.1s |  |
| 206 | `as3/Definitions/const/ConstVarInsideClassFunction` | 1 | 6.1s |  |
| 207 | `as3/Definitions/const/ConstVarInsideClassFunction2_rt` | 1 | 6.2s |  |
| 208 | `as3/Definitions/const/ConstVarInsideGlobalFunction` | 1 | 7.6s |  |
| 209 | `as3/Definitions/const/ConstVarInsideGlobalFunction2` | 1 | 7.6s |  |
| 210 | `as3/Definitions/const/ConstVarInsideGlobalFunction3` | 1 | 3.5s |  |
| 211 | `as3/Definitions/const/ConstVarInsideGlobalFunction4` | 1 | 7.7s |  |
| 212 | `as3/Definitions/const/ConstVarInsideGlobalFunction5_rt` | 1 | 7.8s |  |
| 213 | `as3/Definitions/const/ConstVarInsideGlobalFunction6` | 4 | 7.8s |  |
| 214 | `as3/Definitions/const/ConstWithinClass` | 1 | 7.8s |  |
| 215 | `as3/Definitions/const/ConstWithinPackage` | 1 | 3.6s |  |
| 216 | `as3/Definitions/const/GlobalConstInitialization2_rt` | 1 | 7.7s |  |
| 217 | `as3/Definitions/const/GlobalConstInitialization_rt` | 1 | 7.7s |  |
| 218 | `as3/Definitions/const/StaticConst` | 1 | 7.6s |  |
| 219 | `as3/Definitions/const/StaticConstInDerivedClass` | 1 | 7.5s |  |
| 220 | `as3/Definitions/const/StaticConstInitializationOutsideClass_rt` | 1 | 7.7s |  |
| 221 | `as3/Expressions/QualifiedReferences/AS3NSReferences` | 3 | 3.6s |  |
| 222 | `as3/Expressions/QualifiedReferences/DescendantOperator` | 3 | 7.7s |  |
| 223 | `as3/Expressions/QualifiedReferences/FilterOperator` | 2 | 7.8s |  |
| 224 | `as3/Expressions/QualifiedReferences/MultipleNamespaces` | 7 | 7.7s |  |
| 225 | `as3/Expressions/QualifiedReferences/NSSingleFunc` | 3 | 7.7s |  |
| 226 | `as3/Expressions/QualifiedReferences/ReturnNSReference` | 3 | 7.8s |  |
| 227 | `as3/Expressions/QualifiedReferences/ReturnNamespace` | 1 | 7.7s |  |
| 228 | `as3/Expressions/QualifiedReferences/WildcardOperator` | 3 | 7.8s |  |
| 229 | `as3/Expressions/asOperator/asOperator` | 75 | 8.2s |  |
| 230 | `as3/Expressions/asOperator/asOperatorConversions` | 48 | 8.0s |  |
| 231 | `as3/Expressions/asOperator/asOperatorMuliti` | 12 | 7.7s |  |
| 232 | `as3/Expressions/asOperator/asOperatorTypes` | 48 | 8.0s |  |
| 233 | `as3/Expressions/asOperator/asTypeError` | 2 | 7.9s |  |
| 234 | `as3/Expressions/deleteOperator/deleteArray` | 9 | 7.8s |  |
| 235 | `as3/Expressions/deleteOperator/deleteClass` | 1 | 7.7s |  |
| 236 | `as3/Expressions/deleteOperator/deleteFixedFunction` | 1 | 7.7s |  |
| 237 | `as3/Expressions/deleteOperator/deleteFixedVar` | 1 | 7.4s |  |
| 238 | `as3/Expressions/deleteOperator/deleteInstantiatedFunction` | 4 | 7.7s |  |
| 239 | `as3/Expressions/deleteOperator/deleteInstantiatedVar` | 2 | 7.7s |  |
| 240 | `as3/Expressions/deleteOperator/deleteNonexistentDynamicProperty` | 1 | 7.7s |  |
| 241 | `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | 1 | 7.8s |  |
| 242 | `as3/Expressions/deleteOperator/deleteNoninstantiatedFunction` | 2 | 7.6s |  |
| 243 | `as3/Expressions/deleteOperator/deleteNoninstantiatedVar` | 2 | 3.5s |  |
| 244 | `as3/Expressions/e11_2_2_1` | 4 | 7.7s |  |
| 245 | `as3/Expressions/e11_2_4` | 25 | 8.0s |  |
| 246 | `as3/Expressions/e11_4_3` | 86 | 8.3s |  |
| 247 | `as3/Expressions/e11_9_4` | 56 | 8.5s |  |
| 248 | `as3/Expressions/e11_9_5` | 56 | 4.3s |  |
| 249 | `as3/Expressions/indexProperties` | 36 | 8.2s |  |
| 250 | `as3/Expressions/isOperator/isOper` | 429 | 8.2s |  |
| 251 | `as3/Expressions/isOperator/isOperTypeError` | 2 | 7.8s |  |
| 252 | `as3/Expressions/logicalAssignment` | 16 | 7.8s |  |
| 253 | `as3/Expressions/logicalAssignment2` | 4 | 7.7s |  |
| 254 | `as3/Expressions/postfix` | 14 | 7.8s |  |
| 255 | `as3/Math/MathClass` | 2 | 3.5s |  |
| 256 | `as3/Math/MathUtils` | 7 | 7.7s |  |
| 257 | `as3/Math/e15_8_2_11_rest` | 6 | 7.7s |  |
| 258 | `as3/Math/e15_8_2_12_rest` | 12 | 7.8s |  |
| 259 | `as3/Math/op_divide_703238` | 9 | 7.7s |  |
| 260 | `as3/Math/op_subtract_703238` | 8 | 7.5s |  |
| 261 | `as3/MethodClosures/MethodClosure` | 1 | 7.6s |  |
| 262 | `as3/MethodClosures/MethodClosureFunc` | 1 | 7.6s |  |
| 263 | `as3/RegExp/bug_513020` | 2 | 7.6s |  |
| 264 | `as3/RegExp/eregress_122076` | 1 | 7.7s |  |
| 265 | `as3/RuntimeErrors/Error1002PrecisionArgOutOfRange` | 1 | 7.6s |  |
| 266 | `as3/RuntimeErrors/Error1003RadixArgOutOfRange` | 1 | 7.7s |  |
| 267 | `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | 1 | 7.7s |  |
| 268 | `as3/RuntimeErrors/Error1005ArrayIndexNotInteger` | 1 | 7.6s |  |
| 269 | `as3/RuntimeErrors/Error1006CallNonFunctionObject` | 2 | 7.6s |  |
| 270 | `as3/RuntimeErrors/Error1007InstantiationOnNonConstructor` | 1 | 7.6s |  |
| 271 | `as3/RuntimeErrors/Error1009CannotAccessPropOfNullRef` | 1 | 3.5s |  |
| 272 | `as3/RuntimeErrors/Error1010UndefinedTerm` | 1 | 7.6s |  |
| 273 | `as3/RuntimeErrors/Error1016DescendantsOpNotSupported` | 1 | 7.6s |  |
| 274 | `as3/RuntimeErrors/Error1034TypeCoercionFailed` | 1 | 7.6s |  |
| 275 | `as3/RuntimeErrors/Error1037CannotAssignMethod` | 1 | 7.7s |  |
| 276 | `as3/RuntimeErrors/Error1040InvalidRHSOfInstanceof` | 1 | 7.6s |  |
| 277 | `as3/RuntimeErrors/Error1041RHSOfIsMustBeClass` | 1 | 3.5s |  |
| 278 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | 2 | 7.6s |  |
| 279 | `as3/RuntimeErrors/Error1056CannotCreatePropInSealedClass` | 1 | 7.6s |  |
| 280 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | 1 | 7.6s |  |
| 281 | `as3/RuntimeErrors/Error1065VariableNotDefined` | 1 | 7.6s |  |
| 282 | `as3/RuntimeErrors/Error1066Function-body-NotAllowed` | 1 | 3.5s |  |
| 283 | `as3/RuntimeErrors/Error1069PropertyNotFound` | 1 | 7.5s |  |
| 284 | `as3/RuntimeErrors/Error1070MethodNotFound` | 1 | 7.7s |  |
| 285 | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | 1 | 7.7s |  |
| 286 | `as3/RuntimeErrors/Error1075MathNotAFunction` | 1 | 7.6s |  |
| 287 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | 1 | 7.6s |  |
| 288 | `as3/RuntimeErrors/Error1077IllegalReadOfWriteOnlyProp` | 1 | 7.7s |  |
| 289 | `as3/RuntimeErrors/Error1083XmlPrefixNotFound` | 1 | 7.7s |  |
| 290 | `as3/RuntimeErrors/Error1084XmlQNameProductionMismatch` | 1 | 7.6s |  |
| 291 | `as3/RuntimeErrors/Error1085XmlEndTagMissing` | 1 | 3.5s |  |
| 292 | `as3/RuntimeErrors/Error1086XmlMethodOnlyOnListWithOneItem` | 1 | 7.6s |  |
| 293 | `as3/RuntimeErrors/Error1087XmlAssignToIndexedXml` | 2 | 3.4s |  |
| 294 | `as3/RuntimeErrors/Error1088XmlDocNotWellFormed` | 1 | 7.6s |  |
| 295 | `as3/RuntimeErrors/Error1089XmlAssignToMoreThanOneItemList` | 2 | 7.6s |  |
| 296 | `as3/RuntimeErrors/Error1090XmlElementMalformed` | 1 | 3.4s |  |
| 297 | `as3/RuntimeErrors/Error1091XmlUnterminatedCdata` | 1 | 7.6s |  |
| 298 | `as3/RuntimeErrors/Error1093XmlUnterminatedDoctype` | 1 | 3.5s |  |
| 299 | `as3/RuntimeErrors/Error1094XmlUnterminatedComment` | 1 | 7.6s |  |
| 300 | `as3/RuntimeErrors/Error1097XmlUnterminatedProcessingInstr` | 1 | 7.8s |  |
| 301 | `as3/RuntimeErrors/Error1098XmlIllegalPrefixFoNoNamespace` | 1 | 3.6s |  |
| 302 | `as3/RuntimeErrors/Error1100RegExpFlagsArg` | 1 | 7.6s |  |
| 303 | `as3/RuntimeErrors/Error1104XmlDuplicateAttr` | 1 | 7.5s |  |
| 304 | `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | 2 | 7.6s |  |
| 305 | `as3/RuntimeErrors/Error1115NotAConstructor/v11` | 3 | 7.8s |  |
| 306 | `as3/RuntimeErrors/Error1116FunctionProtoApply2ndArgMustBeArr` | 1 | 7.5s |  |
| 307 | `as3/RuntimeErrors/Error1117InvalidXmlName` | 2 | 7.5s |  |
| 308 | `as3/RuntimeErrors/Error1118IllegalCyclicalLoop` | 2 | 7.6s |  |
| 309 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | 2 | 7.6s |  |
| 310 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | 1 | 7.5s |  |
| 311 | `as3/ShellClasses/Dictionary` | 22 | 7.7s |  |
| 312 | `as3/ShellClasses/DictionarySubclass` | 22 | 8.2s |  |
| 313 | `as3/Statements/Exceptions/MultipleCatchBlocks2` | 7 | 7.8s |  |
| 314 | `as3/Statements/Exceptions/MultipleCatchBlocksArgument` | 1 | 7.7s |  |
| 315 | `as3/Statements/Exceptions/MultipleCatchBlocksEval` | 1 | 3.7s |  |
| 316 | `as3/Statements/Exceptions/MultipleCatchBlocksRange` | 1 | 7.9s |  |
| 317 | `as3/Statements/Exceptions/MultipleCatchBlocksRefErrorCaughtWithError` | 1 | 7.6s |  |
| 318 | `as3/Statements/Exceptions/MultipleCatchBlocksReference` | 1 | 7.7s |  |
| 319 | `as3/Statements/Exceptions/MultipleCatchBlocksType` | 1 | 7.7s |  |
| 320 | `as3/Statements/Exceptions/MultipleCatchBlocksType1` | 1 | 7.6s |  |
| 321 | `as3/Statements/Exceptions/MultipleCatchBlocksType2` | 1 | 7.5s |  |
| 322 | `as3/Statements/Exceptions/MultipleCatchBlocksType3` | 1 | 7.5s |  |
| 323 | `as3/Statements/Exceptions/MultipleCatchBlocksType4` | 1 | 7.4s |  |
| 324 | `as3/Statements/Exceptions/MultipleCatchBlocksType5` | 1 | 1.6s |  |
| 325 | `as3/Statements/Exceptions/MultipleCatchBlocksType6` | 1 | 1.6s |  |
| 326 | `as3/Statements/Exceptions/MultipleCatchBlocksType7` | 1 | 7.6s |  |
| 327 | `as3/Statements/Exceptions/MultipleCatchBlocksURI` | 1 | 7.7s |  |
| 328 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArg1` | 1 | 7.6s |  |
| 329 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArgErrorCaughtByError` | 1 | 7.6s |  |
| 330 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDef1` | 1 | 7.6s |  |
| 331 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDefErrorCaughtWithError` | 1 | 7.6s |  |
| 332 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEval1` | 1 | 7.6s |  |
| 333 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEvalErrorCaughtByError` | 1 | 7.6s |  |
| 334 | `as3/Statements/Exceptions/MultipleCatchBlocksWithNoTypeErrorCatchBlock` | 1 | 7.7s |  |
| 335 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRange1` | 1 | 7.7s |  |
| 336 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRangeErrorCaughtByError` | 1 | 7.8s |  |
| 337 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRefError1` | 1 | 7.7s |  |
| 338 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntax` | 1 | 1.6s |  |
| 339 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntaxErrorCaughtByError` | 1 | 1.6s |  |
| 340 | `as3/Statements/Exceptions/MultipleCatchBlocksWithTwoType` | 2 | 7.7s |  |
| 341 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURI1` | 1 | 7.6s |  |
| 342 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURICaughtByError` | 1 | 7.0s |  |
| 343 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUninitialized1` | 1 | 7.9s |  |
| 344 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUnitializedCaughtWithError` | 1 | 7.8s |  |
| 345 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerify1` | 1 | 7.9s |  |
| 346 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerifyCaughtByError` | 1 | 1.1s |  |
| 347 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchBlocksTypeWithNoInnerCatchType` | 2 | 7.8s |  |
| 348 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchRefType` | 2 | 7.9s |  |
| 349 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideEighthCatch` | 2 | 8.0s |  |
| 350 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideFifthCatch` | 2 | 7.8s |  |
| 351 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSeventhCatch` | 2 | 3.8s |  |
| 352 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSixthCatch` | 2 | 3.8s |  |
| 353 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinally` | 2 | 7.8s |  |
| 354 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinallyExceptionBubbling` | 1 | 8.1s |  |
| 355 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatch` | 2 | 8.0s |  |
| 356 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatchWithoutMatchingCatch` | 2 | 8.0s |  |
| 357 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatch` | 2 | 7.9s |  |
| 358 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatchWithoutMatchingCatch` | 2 | 7.9s |  |
| 359 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatch` | 2 | 7.8s |  |
| 360 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatchWithoutMatchingCatch` | 1 | 7.8s |  |
| 361 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTry` | 1 | 7.9s |  |
| 362 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTryWithoutMatchingCatch` | 1 | 8.0s |  |
| 363 | `as3/Statements/Exceptions/TryCatchBlockPackage` | 1 | 7.7s |  |
| 364 | `as3/Statements/Exceptions/TryCatchBlockPackage2` | 1 | 7.7s |  |
| 365 | `as3/Statements/Exceptions/TryCatchBlockPackage3` | 1 | 3.6s |  |
| 366 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 7 | 7.8s |  |
| 367 | `as3/Statements/Exceptions/UserDefinedErrorsInPackage` | 1 | 7.7s |  |
| 368 | `as3/Statements/Exceptions/UserDefinedErrorsPackage` | 1 | 7.8s |  |
| 369 | `as3/Statements/Exceptions/UserDefinedErrorsPackage2` | 1 | 7.8s |  |
| 370 | `as3/Statements/Exceptions/UserDefinedErrorsPackage3` | 1 | 7.8s |  |
| 371 | `as3/Statements/Exceptions/UserDefinedErrorsPackageWithoutMatchingCatch` | 1 | 7.7s |  |
| 372 | `as3/Statements/e12_6_3_12` | 1 | 7.6s |  |
| 373 | `as3/Statements/for-each-in/eforeachin_001` | 8 | 8.0s |  |
| 374 | `as3/Statements/for-each-in/eforeachin_001_500476` | 2 | 7.4s |  |
| 375 | `as3/Statements/for-each-in/eforeachin_002` | 2 | 7.5s |  |
| 376 | `as3/Statements/switch/switch_000` | 3 | 7.4s |  |
| 377 | `as3/Statements/switch/switch_001` | 6 | 7.5s |  |
| 378 | `as3/Statements/switch/switch_002` | 5 | 7.5s |  |
| 379 | `as3/Statements/switch/switch_003` | 6 | 7.5s |  |
| 380 | `as3/String/localeCompare_585791/v12` | 8 | 7.5s |  |
| 381 | `as3/Types/Conversions/ExplicitConversions` | 54 | 7.8s |  |
| 382 | `as3/Types/Conversions/ImplicitConversions1_23` | 6 | 7.5s |  |
| 383 | `as3/Types/Conversions/ImplicitConversionsFalse` | 10 | 7.6s |  |
| 384 | `as3/Types/Conversions/ImplicitConversionsNaN` | 6 | 7.5s |  |
| 385 | `as3/Types/Conversions/ImplicitConversionsNeg1_23` | 10 | 7.6s |  |
| 386 | `as3/Types/Conversions/ImplicitConversionsNull` | 10 | 7.6s |  |
| 387 | `as3/Types/Conversions/ImplicitConversionsString` | 20 | 7.8s |  |
| 388 | `as3/Types/Conversions/ImplicitConversionsTrue` | 10 | 7.6s |  |
| 389 | `as3/Types/Conversions/ImplicitConversionsUndefined` | 11 | 7.7s |  |
| 390 | `as3/Types/Int/intConstructor` | 12 | 7.5s |  |
| 391 | `as3/Types/Int/intIs` | 12 | 7.5s |  |
| 392 | `as3/Types/Int/intMaxValue` | 4 | 7.5s |  |
| 393 | `as3/Types/Int/intMinValue` | 4 | 7.5s |  |
| 394 | `as3/Types/Int/intType` | 2 | 7.6s |  |
| 395 | `as3/Types/Int/signed_unsigned` | 6 | 7.4s |  |
| 396 | `as3/Types/Int/wraparound` | 16 | 3.5s |  |
| 397 | `as3/Types/Number/abs` | 41 | 7.8s |  |
| 398 | `as3/Types/Number/acos` | 29 | 7.7s |  |
| 399 | `as3/Types/Number/asin` | 34 | 7.8s |  |
| 400 | `as3/Types/Number/atan` | 33 | 7.8s |  |
| 401 | `as3/Types/Number/atan2` | 72 | 8.8s |  |
| 402 | `as3/Types/Number/ceil` | 49 | 7.9s |  |
| 403 | `as3/Types/Number/e` | 8 | 7.4s |  |
| 404 | `as3/Types/Number/exp` | 30 | 7.7s |  |
| 405 | `as3/Types/Number/floor` | 46 | 7.8s |  |
| 406 | `as3/Types/Number/ln10` | 8 | 7.1s |  |
| 407 | `as3/Types/Number/ln2` | 8 | 7.1s |  |
| 408 | `as3/Types/Number/log` | 32 | 7.8s |  |
| 409 | `as3/Types/Number/log10e` | 9 | 7.6s |  |
| 410 | `as3/Types/Number/log2e` | 9 | 7.2s |  |
| 411 | `as3/Types/Number/max` | 54 | 8.0s |  |
| 412 | `as3/Types/Number/min` | 54 | 8.2s |  |
| 413 | `as3/Types/Number/pi` | 8 | 7.7s |  |
| 414 | `as3/Types/Number/pow` | 96 | 9.5s |  |
| 415 | `as3/Types/Number/random` | 4 | 7.6s |  |
| 416 | `as3/Types/Number/round` | 54 | 8.1s |  |
| 417 | `as3/Types/Number/sin` | 28 | 7.7s |  |
| 418 | `as3/Types/Number/sqrt` | 69 | 7.8s |  |
| 419 | `as3/Types/Number/sqrt1_2` | 9 | 7.2s |  |
| 420 | `as3/Types/Number/sqrt2` | 8 | 7.2s |  |
| 421 | `as3/Types/Number/tan` | 28 | 7.7s |  |
| 422 | `as3/Types/Number/visibility/v15` | 34 | 7.8s |  |
| 423 | `as3/Types/Number/visibility/v16` | 9 | 7.7s |  |
| 424 | `as3/Types/uint/UintFunctionArg` | 17 | 7.8s |  |
| 425 | `as3/Types/uint/UintHex` | 1 | 7.5s |  |
| 426 | `as3/Types/uint/UintIs` | 12 | 7.7s |  |
| 427 | `as3/Types/uint/UintPublicClassMethodArg` | 24 | 8.2s |  |
| 428 | `as3/Types/uint/UintType` | 1 | 7.7s |  |
| 429 | `as3/Types/uint/UintVarAsClassProp` | 1 | 7.6s |  |
| 430 | `as3/Types/uint/UintVarOperationInFunc` | 1 | 7.5s |  |
| 431 | `as3/Types/uint/UintVarOperationInFuncRet` | 1 | 7.4s |  |
| 432 | `as3/Types/uint/UintVarOperations` | 17 | 7.9s |  |
| 433 | `as3/Vector/Vector_double_methods` | 11 | 7.9s |  |
| 434 | `as3/Vector/Vector_object_methods` | 12 | 7.8s |  |
| 435 | `as3/Vector/Vector_uint_methods` | 2 | 7.4s |  |
| 436 | `as3/Vector/bug504525/v10` | 1 | 7.4s |  |
| 437 | `as3/Vector/bug504525/v11` | 1 | 7.4s |  |
| 438 | `as3/Vector/bug_678952` | 2 | 7.5s |  |
| 439 | `as3/Vector/bug_683507` | 1 | 7.6s |  |
| 440 | `as3/Vector/concat` | 10 | 7.8s |  |
| 441 | `as3/Vector/concat_with_initializers` | 4 | 7.6s |  |
| 442 | `as3/Vector/constructor` | 18 | 8.0s |  |
| 443 | `as3/Vector/every` | 14 | 8.0s |  |
| 444 | `as3/Vector/every_initializers` | 5 | 7.4s |  |
| 445 | `as3/Vector/filter` | 9 | 8.1s |  |
| 446 | `as3/Vector/filter_initializers` | 5 | 7.7s |  |
| 447 | `as3/Vector/fixed_length` | 4 | 7.6s |  |
| 448 | `as3/Vector/foreach` | 6 | 3.5s |  |
| 449 | `as3/Vector/foreach_initializers` | 5 | 7.9s |  |
| 450 | `as3/Vector/get` | 7 | 7.6s |  |
| 451 | `as3/Vector/in` | 10 | 7.8s |  |
| 452 | `as3/Vector/in_initializers` | 10 | 7.7s |  |
| 453 | `as3/Vector/indexof` | 7 | 7.7s |  |
| 454 | `as3/Vector/indexof_initializers` | 7 | 7.8s |  |
| 455 | `as3/Vector/initializer_expressions` | 41 | 9.1s |  |
| 456 | `as3/Vector/initializer_large_vector` | 1 | 10.3s |  |
| 457 | `as3/Vector/initializer_ws` | 2 | 7.2s |  |
| 458 | `as3/Vector/insert_remove` | 542 | 7.8s |  |
| 459 | `as3/Vector/interface_method_return_type` | 5 | 8.0s |  |
| 460 | `as3/Vector/join` | 4 | 7.3s |  |
| 461 | `as3/Vector/join_initializers` | 4 | 5.4s |  |
| 462 | `as3/Vector/lastindexof` | 5 | 5.1s |  |
| 463 | `as3/Vector/lastindexof_initializers` | 7 | 5.3s |  |
| 464 | `as3/Vector/length` | 9 | 5.6s |  |
| 465 | `as3/Vector/length_initializers` | 3 | 5.1s |  |
| 466 | `as3/Vector/map` | 12 | 6.1s |  |
| 467 | `as3/Vector/map_initializers` | 7 | 5.4s |  |
| 468 | `as3/Vector/nested` | 8 | 6.9s |  |
| 469 | `as3/Vector/nested_initializers` | 5 | 5.1s |  |
| 470 | `as3/Vector/nonindexproperty/v10` | 51 | 5.9s |  |
| 471 | `as3/Vector/nonindexproperty/v11` | 55 | 5.8s |  |
| 472 | `as3/Vector/optimization_tests` | 14 | 6.1s |  |
| 473 | `as3/Vector/pop` | 12 | 5.3s |  |
| 474 | `as3/Vector/push` | 12 | 5.6s |  |
| 475 | `as3/Vector/put` | 8 | 5.7s |  |
| 476 | `as3/Vector/reverse` | 5 | 5.6s |  |
| 477 | `as3/Vector/reverse_initializers` | 4 | 5.5s |  |
| 478 | `as3/Vector/shift` | 12 | 5.4s |  |
| 479 | `as3/Vector/slice` | 1 | 6.0s |  |
| 480 | `as3/Vector/slice_initializers` | 5 | 5.4s |  |
| 481 | `as3/Vector/some` | 13 | 5.3s |  |
| 482 | `as3/Vector/some_initializers` | 6 | 5.3s |  |
| 483 | `as3/Vector/sort` | 9 | 5.6s |  |
| 484 | `as3/Vector/sort_initializers` | 1 | 5.4s |  |
| 485 | `as3/Vector/specialized_at_runtime` | 3 | 5.5s |  |
| 486 | `as3/Vector/splice` | 4 | 5.5s |  |
| 487 | `as3/Vector/static_initializer` | 4 | 5.5s |  |
| 488 | `as3/Vector/tostring` | 7 | 5.2s |  |
| 489 | `as3/Vector/tostring_initializer` | 5 | 5.0s |  |
| 490 | `as3/Vector/typechecking` | 10 | 5.6s |  |
| 491 | `as3/Vector/unshift` | 7 | 5.6s |  |
| 492 | `as3/Vector/vectorIndexRangeExceptions` | 1270 | 6.7s |  |
| 493 | `e4x/Expressions/e11_1_1` | 39 | 6.5s |  |
| 494 | `e4x/Expressions/e11_1_3` | 8 | 5.9s |  |
| 495 | `e4x/Expressions/e11_1_5` | 17 | 6.1s |  |
| 496 | `e4x/Expressions/e11_2_1` | 40 | 6.5s |  |
| 497 | `e4x/Expressions/e11_2_2` | 24 | 5.9s |  |
| 498 | `e4x/Expressions/e11_2_3` | 10 | 5.5s |  |
| 499 | `e4x/Expressions/e11_2_4` | 15 | 5.9s |  |
| 500 | `e4x/Expressions/e11_3_1` | 20 | 5.7s |  |
| 501 | `e4x/Expressions/e11_3_2` | 7 | 5.3s |  |
| 502 | `e4x/Expressions/e11_4_1` | 18 | 5.8s |  |
| 503 | `e4x/Expressions/e11_5_1` | 66 | 5.8s |  |
| 504 | `e4x/Expressions/e11_6_1` | 19 | 5.9s |  |
| 505 | `e4x/Expressions/e11_6_2` | 15 | 5.6s |  |
| 506 | `e4x/Expressions/e11_6_3` | 6 | 5.4s |  |
| 507 | `e4x/Expressions/kXMLBadQNameErr` | 5 | 5.3s |  |
| 508 | `e4x/Global/isXMLNameTypeErr` | 5 | 5.1s |  |
| 509 | `e4x/Namespace/e13_2_1` | 19 | 5.9s |  |
| 510 | `e4x/Namespace/e13_2_2` | 22 | 5.6s |  |
| 511 | `e4x/Namespace/e13_2_3_1` | 3 | 6.5s |  |
| 512 | `e4x/Namespace/e13_2_4_1` | 3 | 6.2s |  |
| 513 | `e4x/Namespace/e13_2_4_2` | 4 | 6.2s |  |
| 514 | `e4x/Namespace/e13_2_5` | 36 | 6.8s |  |
| 515 | `e4x/QName/e13_3_1` | 22 | 6.4s |  |
| 516 | `e4x/QName/e13_3_2` | 49 | 6.7s |  |
| 517 | `e4x/QName/e13_3_3_1` | 3 | 5.8s |  |
| 518 | `e4x/QName/e13_3_4_1` | 2 | 6.2s |  |
| 519 | `e4x/QName/e13_3_4_2` | 4 | 6.2s |  |
| 520 | `e4x/QName/e13_3_5` | 13 | 6.3s |  |
| 521 | `e4x/Regress/b121219` | 2 | 6.2s |  |
| 522 | `e4x/Regress/error1085` | 2 | 6.2s |  |
| 523 | `e4x/Regress/regress-257679` | 2 | 6.5s |  |
| 524 | `e4x/Regress/regress-263934` | 2 | 6.2s |  |
| 525 | `e4x/Regress/regress-263936` | 2 | 6.4s |  |
| 526 | `e4x/Regress/regress-264369` | 2 | 6.2s |  |
| 527 | `e4x/Regress/regress-271545` | 6 | 6.2s |  |
| 528 | `e4x/Regress/regress-277650` | 2 | 3.0s |  |
| 529 | `e4x/Regress/regress-277664` | 2 | 6.2s |  |
| 530 | `e4x/Regress/regress-277683` | 2 | 6.3s |  |
| 531 | `e4x/Regress/regress-277779` | 2 | 6.2s |  |
| 532 | `e4x/Regress/regress-278112` | 4 | 2.8s |  |
| 533 | `e4x/Statements/e12_2` | 14 | 6.3s |  |
| 534 | `e4x/Statements/e12_3` | 5 | 6.3s |  |
| 535 | `e4x/TypeConversion/bug153363` | 3 | 6.2s |  |
| 536 | `e4x/TypeConversion/bug153363_2` | 3 | 6.3s |  |
| 537 | `e4x/TypeConversion/e10_1_1` | 3 | 6.4s |  |
| 538 | `e4x/TypeConversion/e10_1_2` | 5 | 6.3s |  |
| 539 | `e4x/TypeConversion/e10_2_1` | 5 | 6.4s |  |
| 540 | `e4x/TypeConversion/e10_2_1_1` | 5 | 6.3s |  |
| 541 | `e4x/TypeConversion/e10_2_1_2` | 13 | 6.4s |  |
| 542 | `e4x/TypeConversion/e10_2_2` | 2 | 6.2s |  |
| 543 | `e4x/TypeConversion/e10_3` | 7 | 6.5s |  |
| 544 | `e4x/TypeConversion/e10_3_1` | 2 | 6.2s |  |
| 545 | `e4x/TypeConversion/e10_4` | 9 | 6.3s |  |
| 546 | `e4x/TypeConversion/e10_4_1` | 8 | 6.2s |  |
| 547 | `e4x/Types/e9_1_1_1` | 32 | 7.0s |  |
| 548 | `e4x/Types/e9_1_1_10` | 2 | 6.2s |  |
| 549 | `e4x/Types/e9_1_1_11` | 2 | 5.9s |  |
| 550 | `e4x/Types/e9_1_1_12` | 2 | 6.0s |  |
| 551 | `e4x/Types/e9_1_1_13` | 2 | 5.9s |  |
| 552 | `e4x/Types/e9_1_1_2` | 6 | 6.3s |  |
| 553 | `e4x/Types/e9_1_1_3` | 5 | 6.2s |  |
| 554 | `e4x/Types/e9_1_1_4` | 2 | 6.2s |  |
| 555 | `e4x/Types/e9_1_1_5` | 2 | 5.8s |  |
| 556 | `e4x/Types/e9_1_1_6` | 11 | 6.2s |  |
| 557 | `e4x/Types/e9_1_1_7` | 2 | 2.6s |  |
| 558 | `e4x/Types/e9_1_1_8` | 2 | 5.8s |  |
| 559 | `e4x/Types/e9_1_1_9` | 20 | 6.5s |  |
| 560 | `e4x/Types/e9_2_1_1` | 11 | 6.4s |  |
| 561 | `e4x/Types/e9_2_1_10` | 2 | 7.8s |  |
| 562 | `e4x/Types/e9_2_1_2` | 19 | 8.0s |  |
| 563 | `e4x/Types/e9_2_1_3` | 2 | 7.3s |  |
| 564 | `e4x/Types/e9_2_1_4` | 2 | 7.3s |  |
| 565 | `e4x/Types/e9_2_1_5` | 2 | 3.2s |  |
| 566 | `e4x/Types/e9_2_1_6` | 2 | 7.2s |  |
| 567 | `e4x/Types/e9_2_1_7` | 2 | 7.3s |  |
| 568 | `e4x/Types/e9_2_1_8` | 2 | 7.7s |  |
| 569 | `e4x/Types/e9_2_1_9` | 11 | 7.9s |  |
| 570 | `e4x/XML/bug157597` | 2 | 7.8s |  |
| 571 | `e4x/XML/bug157597_2` | 2 | 7.3s |  |
| 572 | `e4x/XML/bug157735` | 2 | 7.7s |  |
| 573 | `e4x/XML/bug158506` | 2 | 7.8s |  |
| 574 | `e4x/XML/e13_4_1` | 18 | 7.9s |  |
| 575 | `e4x/XML/e13_4_2` | 36 | 8.5s |  |
| 576 | `e4x/XML/e13_4_3` | 35 | 8.5s |  |
| 577 | `e4x/XML/e13_4_3_1` | 5 | 7.8s |  |
| 578 | `e4x/XML/e13_4_3_2` | 8 | 7.8s |  |
| 579 | `e4x/XML/e13_4_3_3` | 8 | 7.8s |  |
| 580 | `e4x/XML/e13_4_3_4` | 11 | 7.8s |  |
| 581 | `e4x/XML/e13_4_3_5` | 5 | 7.7s |  |
| 582 | `e4x/XML/e13_4_3_6` | 10 | 7.9s |  |
| 583 | `e4x/XML/e13_4_3_7` | 31 | 7.9s |  |
| 584 | `e4x/XML/e13_4_3_8` | 41 | 8.0s |  |
| 585 | `e4x/XML/e13_4_3_9` | 11 | 7.8s |  |
| 586 | `e4x/XML/e13_4_4_1` | 3 | 7.8s |  |
| 587 | `e4x/XML/e13_4_4_10` | 11 | 7.8s |  |
| 588 | `e4x/XML/e13_4_4_11` | 12 | 7.9s |  |
| 589 | `e4x/XML/e13_4_4_12` | 15 | 7.9s |  |
| 590 | `e4x/XML/e13_4_4_13` | 7 | 7.8s |  |
| 591 | `e4x/XML/e13_4_4_14` | 12 | 7.8s |  |
| 592 | `e4x/XML/e13_4_4_15` | 16 | 7.8s |  |
| 593 | `e4x/XML/e13_4_4_16` | 25 | 8.0s |  |
| 594 | `e4x/XML/e13_4_4_18` | 16 | 8.3s |  |
| 595 | `e4x/XML/e13_4_4_19` | 16 | 8.3s |  |
| 596 | `e4x/XML/e13_4_4_20` | 11 | 7.9s |  |
| 597 | `e4x/XML/e13_4_4_21` | 16 | 7.9s |  |
| 598 | `e4x/XML/e13_4_4_22` | 15 | 8.1s |  |
| 599 | `e4x/XML/e13_4_4_23` | 17 | 8.3s |  |
| 600 | `e4x/XML/e13_4_4_24` | 22 | 8.1s |  |
| 601 | `e4x/XML/e13_4_4_25` | 15 | 8.0s |  |
| 602 | `e4x/XML/e13_4_4_26` | 6 | 7.9s |  |
| 603 | `e4x/XML/e13_4_4_27` | 21 | 8.0s |  |
| 604 | `e4x/XML/e13_4_4_28` | 13 | 8.0s |  |
| 605 | `e4x/XML/e13_4_4_29/v10` | 19 | 8.5s |  |
| 606 | `e4x/XML/e13_4_4_29/v9` | 19 | 8.5s |  |
| 607 | `e4x/XML/e13_4_4_3/v10` | 16 | 8.3s |  |
| 608 | `e4x/XML/e13_4_4_3/v21` | 16 | 7.4s |  |
| 609 | `e4x/XML/e13_4_4_3/v9` | 16 | 8.2s |  |
| 610 | `e4x/XML/e13_4_4_31` | 19 | 8.0s |  |
| 611 | `e4x/XML/e13_4_4_32/v10` | 9 | 7.9s |  |
| 612 | `e4x/XML/e13_4_4_33` | 6 | 7.8s |  |
| 613 | `e4x/XML/e13_4_4_34` | 12 | 8.1s |  |
| 614 | `e4x/XML/e13_4_4_35` | 17 | 8.3s |  |
| 615 | `e4x/XML/e13_4_4_37` | 12 | 7.8s |  |
| 616 | `e4x/XML/e13_4_4_38` | 17 | 8.0s |  |
| 617 | `e4x/XML/e13_4_4_39` | 20 | 8.0s |  |
| 618 | `e4x/XML/e13_4_4_4` | 19 | 8.0s |  |
| 619 | `e4x/XML/e13_4_4_40` | 7 | 7.8s |  |
| 620 | `e4x/XML/e13_4_4_5` | 12 | 7.8s |  |
| 621 | `e4x/XML/e13_4_4_6` | 31 | 8.1s |  |
| 622 | `e4x/XML/e13_4_4_7` | 7 | 7.8s |  |
| 623 | `e4x/XML/e13_4_4_8` | 7 | 7.8s |  |
| 624 | `e4x/XML/e13_4_4_9` | 14 | 7.9s |  |
| 625 | `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | 3 | 7.8s |  |
| 626 | `e4x/XML/kXMLMarkupMustBeWellFormedErr` | 3 | 7.7s |  |
| 627 | `e4x/XML/kXMLPrefixNotBoundErr` | 7 | 7.8s |  |
| 628 | `e4x/XML/kXMLUnterminatedElementTagErr` | 5 | 7.8s |  |
| 629 | `e4x/XMLList/bug157735` | 2 | 7.7s |  |
| 630 | `e4x/XMLList/e13_5_1` | 26 | 7.9s |  |
| 631 | `e4x/XMLList/e13_5_2` | 37 | 8.1s |  |
| 632 | `e4x/XMLList/e13_5_3_1` | 5 | 7.7s |  |
| 633 | `e4x/XMLList/e13_5_4_1` | 3 | 7.7s |  |
| 634 | `e4x/XMLList/e13_5_4_10` | 7 | 7.7s |  |
| 635 | `e4x/XMLList/e13_5_4_11` | 13 | 7.7s |  |
| 636 | `e4x/XMLList/e13_5_4_12` | 19 | 7.8s |  |
| 637 | `e4x/XMLList/e13_5_4_13` | 28 | 7.9s |  |
| 638 | `e4x/XMLList/e13_5_4_14` | 11 | 7.8s |  |
| 639 | `e4x/XMLList/e13_5_4_15` | 3 | 7.7s |  |
| 640 | `e4x/XMLList/e13_5_4_16` | 24 | 8.0s |  |
| 641 | `e4x/XMLList/e13_5_4_17` | 10 | 7.7s |  |
| 642 | `e4x/XMLList/e13_5_4_19` | 5 | 7.7s |  |
| 643 | `e4x/XMLList/e13_5_4_2` | 28 | 8.2s |  |
| 644 | `e4x/XMLList/e13_5_4_20` | 12 | 7.8s |  |
| 645 | `e4x/XMLList/e13_5_4_21` | 12 | 7.9s |  |
| 646 | `e4x/XMLList/e13_5_4_22` | 5 | 7.7s |  |
| 647 | `e4x/XMLList/e13_5_4_3` | 16 | 7.9s |  |
| 648 | `e4x/XMLList/e13_5_4_4` | 39 | 8.6s |  |
| 649 | `e4x/XMLList/e13_5_4_5` | 11 | 7.9s |  |
| 650 | `e4x/XMLList/e13_5_4_6` | 6 | 7.8s |  |
| 651 | `e4x/XMLList/e13_5_4_7` | 6 | 7.8s |  |
| 652 | `e4x/XMLList/e13_5_4_8` | 11 | 8.0s |  |
| 653 | `e4x/XMLList/e13_5_4_9` | 10 | 7.8s |  |
| 654 | `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | 29 | 8.5s |  |
| 655 | `ecma3/Array/bug_630945` | 6 | 7.7s |  |
| 656 | `ecma3/Array/e15_4_1` | 14 | 7.8s |  |
| 657 | `ecma3/Array/e15_4_1_1` | 7 | 7.8s |  |
| 658 | `ecma3/Array/e15_4_1_2` | 16 | 7.9s |  |
| 659 | `ecma3/Array/e15_4_1_3` | 4 | 7.6s |  |
| 660 | `ecma3/Array/e15_4_2` | 9 | 7.7s |  |
| 661 | `ecma3/Array/e15_4_2_1_1` | 7 | 7.7s |  |
| 662 | `ecma3/Array/e15_4_2_1_2` | 1025 | 7.6s |  |
| 663 | `ecma3/Array/e15_4_2_1_3` | 1031 | 7.7s |  |
| 664 | `ecma3/Array/e15_4_2_2_1` | 17 | 7.8s |  |
| 665 | `ecma3/Array/e15_4_2_2_2` | 8 | 7.8s |  |
| 666 | `ecma3/Array/e15_4_2_3` | 5 | 7.7s |  |
| 667 | `ecma3/Array/e15_4_3` | 1 | 7.6s |  |
| 668 | `ecma3/Array/e15_4_3_1_2` | 4 | 7.7s |  |
| 669 | `ecma3/Array/e15_4_3_2` | 1 | 7.6s |  |
| 670 | `ecma3/Array/e15_4_4` | 4 | 7.7s |  |
| 671 | `ecma3/Array/e15_4_4_1` | 1 | 7.6s |  |
| 672 | `ecma3/Array/e15_4_4_10` | 6 | 7.8s |  |
| 673 | `ecma3/Array/e15_4_4_11` | 16 | 7.7s |  |
| 674 | `ecma3/Array/e15_4_4_12` | 4 | 7.5s |  |
| 675 | `ecma3/Array/e15_4_4_13` | 7 | 7.4s |  |
| 676 | `ecma3/Array/e15_4_4_2` | 13 | 7.4s |  |
| 677 | `ecma3/Array/e15_4_4_3_1` | 1 | 7.3s |  |
| 678 | `ecma3/Array/e15_4_4_4_001` | 9 | 7.5s |  |
| 679 | `ecma3/Array/e15_4_4_4_1` | 1046 | 7.9s |  |
| 680 | `ecma3/Array/e15_4_4_4_2` | 4 | 7.5s |  |
| 681 | `ecma3/Array/e15_4_4_5_1` | 53 | 7.5s |  |
| 682 | `ecma3/Array/e15_4_4_5_2` | 53 | 7.5s |  |
| 683 | `ecma3/Array/e15_4_4_5_3` | 56 | 7.5s |  |
| 684 | `ecma3/Array/e15_4_4_6` | 5 | 7.3s |  |
| 685 | `ecma3/Array/e15_4_4_6_1` | 1 | 7.3s |  |
| 686 | `ecma3/Array/e15_4_4_7` | 6 | 7.3s |  |
| 687 | `ecma3/Array/e15_4_4_8` | 4 | 7.3s |  |
| 688 | `ecma3/Array/e15_4_4_9` | 8 | 7.3s |  |
| 689 | `ecma3/Array/e15_4_4_9_1` | 1 | 2.9s |  |
| 690 | `ecma3/Array/e15_4_5_1_1` | 27 | 7.9s |  |
| 691 | `ecma3/Array/e15_4_5_1_2` | 13 | 7.4s |  |
| 692 | `ecma3/Array/e15_4_5_2_1` | 6 | 7.4s |  |
| 693 | `ecma3/Array/e15_4_5_2_2` | 11 | 7.5s |  |
| 694 | `ecma3/Array/e15_4__1` | 12 | 7.5s |  |
| 695 | `ecma3/Array/eregress_130451` | 7 | 7.5s |  |
| 696 | `ecma3/Array/general1` | 6 | 7.5s |  |
| 697 | `ecma3/Array/general2` | 2 | 7.5s |  |
| 698 | `ecma3/Array/general3` | 4 | 3.5s |  |
| 699 | `ecma3/Array/slice` | 2 | 7.5s |  |
| 700 | `ecma3/Array/sortOn` | 32 | 7.6s |  |
| 701 | `ecma3/Array/sparseArray` | 15 | 7.6s |  |
| 702 | `ecma3/Array/splice1` | 2 | 7.5s |  |
| 703 | `ecma3/Array/splice2` | 2 | 7.5s |  |
| 704 | `ecma3/Boolean/e15_6_1` | 20 | 7.5s |  |
| 705 | `ecma3/Boolean/e15_6_2` | 57 | 7.8s |  |
| 706 | `ecma3/Boolean/e15_6_3` | 2 | 7.4s |  |
| 707 | `ecma3/Boolean/e15_6_3_1` | 2 | 7.4s |  |
| 708 | `ecma3/Boolean/e15_6_3_1_1` | 1 | 7.4s |  |
| 709 | `ecma3/Boolean/e15_6_3_1_2` | 1 | 7.6s |  |
| 710 | `ecma3/Boolean/e15_6_3_1_3` | 1 | 7.7s |  |
| 711 | `ecma3/Boolean/e15_6_3_1_4` | 2 | 7.8s |  |
| 712 | `ecma3/Boolean/e15_6_3_1_5` | 1 | 7.7s |  |
| 713 | `ecma3/Boolean/e15_6_4` | 2 | 7.7s |  |
| 714 | `ecma3/Boolean/e15_6_4_1` | 1 | 7.7s |  |
| 715 | `ecma3/Boolean/e15_6_4_2_1` | 24 | 7.9s |  |
| 716 | `ecma3/Boolean/e15_6_4_2_2` | 3 | 7.6s |  |
| 717 | `ecma3/Boolean/e15_6_4_2_3` | 2 | 7.7s |  |
| 718 | `ecma3/Boolean/e15_6_4_3` | 22 | 7.5s |  |
| 719 | `ecma3/Boolean/e15_6_4_3_1` | 22 | 6.9s |  |
| 720 | `ecma3/Boolean/e15_6_4_3_2` | 3 | 7.3s |  |
| 721 | `ecma3/Boolean/e15_6_4_3_3` | 2 | 7.5s |  |
| 722 | `ecma3/Boolean/e15_6_4__1` | 4 | 7.7s |  |
| 723 | `ecma3/Boolean/ecma4_sealedtype_1_rt` | 1 | 7.7s |  |
| 724 | `ecma3/Boolean/ecma4_sealedtype_2_rt` | 1 | 7.7s |  |
| 725 | `ecma3/Boolean/ecma4_sealedtype_3_rt` | 1 | 7.7s |  |
| 726 | `ecma3/Boolean/ecma4_sealedtype_4_rt` | 1 | 7.8s |  |
| 727 | `ecma3/Boolean/ecma4_sealedtype_5_rt` | 1 | 7.8s |  |
| 728 | `ecma3/Boolean/ecma4_st_valueOf_1_rt` | 2 | 7.9s |  |
| 729 | `ecma3/Boolean/ecma4_st_valueOf_2_rt` | 2 | 7.8s |  |
| 730 | `ecma3/Boolean/ecma4_st_valueOf_3_rt` | 1 | 7.8s |  |
| 731 | `ecma3/Boolean/ecma4_st_valueOf_4_rt` | 1 | 7.8s |  |
| 732 | `ecma3/Boolean/ecma4_st_valueOf_5_rt` | 1 | 7.8s |  |
| 733 | `ecma3/Date/e15_9_1_1_1` | 686 | 8.9s |  |
| 734 | `ecma3/Date/e15_9_1_1_2` | 685 | 8.9s |  |
| 735 | `ecma3/Date/e15_9_2_1` | 24 | 9.2s |  |
| 736 | `ecma3/Date/e15_9_2_2_1` | 24 | 9.2s |  |
| 737 | `ecma3/Date/e15_9_2_2_2` | 20 | 9.1s |  |
| 738 | `ecma3/Date/e15_9_2_2_3` | 15 | 9.1s |  |
| 739 | `ecma3/Date/e15_9_2_2_4` | 3 | 8.9s |  |
| 740 | `ecma3/Date/e15_9_2_2_5` | 4 | 8.9s |  |
| 741 | `ecma3/Date/e15_9_2_2_6` | 4 | 8.8s |  |
| 742 | `ecma3/Date/e15_9_3_1_1` | 648 | 9.7s |  |
| 743 | `ecma3/Date/e15_9_3_1_2` | 90 | 9.1s |  |
| 744 | `ecma3/Date/e15_9_3_1_3` | 54 | 9.1s |  |
| 745 | `ecma3/Date/e15_9_3_1_4` | 90 | 9.1s |  |
| 746 | `ecma3/Date/e15_9_3_1_5` | 36 | 9.1s |  |
| 747 | `ecma3/Date/e15_9_3_2_1` | 90 | 9.2s |  |
| 748 | `ecma3/Date/e15_9_3_2_2` | 54 | 9.1s |  |
| 749 | `ecma3/Date/e15_9_3_2_3` | 72 | 9.1s |  |
| 750 | `ecma3/Date/e15_9_3_2_4` | 54 | 9.2s |  |
| 751 | `ecma3/Date/e15_9_3_2_5` | 36 | 9.2s |  |
| 752 | `ecma3/Date/e15_9_3_8_1` | 90 | 9.2s |  |
| 753 | `ecma3/Date/e15_9_3_8_2` | 90 | 9.2s |  |
| 754 | `ecma3/Date/e15_9_3_8_3` | 108 | 9.2s |  |
| 755 | `ecma3/Date/e15_9_3_8_4` | 72 | 9.2s |  |
| 756 | `ecma3/Date/e15_9_3_8_5` | 108 | 9.2s |  |
| 757 | `ecma3/Date/e15_9_4_2` | 391 | 9.3s |  |
| 758 | `ecma3/Date/e15_9_4_3` | 40 | 9.3s |  |
| 759 | `ecma3/Date/e15_9_5` | 1 | 9.1s |  |
| 760 | `ecma3/Date/e15_9_5_1` | 1 | 8.9s |  |
| 761 | `ecma3/Date/e15_9_5_10_12` | 64 | 8.9s |  |
| 762 | `ecma3/Date/e15_9_5_10_13` | 33 | 8.8s |  |
| 763 | `ecma3/Date/e15_9_5_10_3` | 31 | 4.6s |  |
| 764 | `ecma3/Date/e15_9_5_10_4` | 31 | 2.7s |  |
| 765 | `ecma3/Date/e15_9_5_10_5` | 31 | 2.8s |  |
| 766 | `ecma3/Date/e15_9_5_10_6` | 32 | 8.9s |  |
| 767 | `ecma3/Date/e15_9_5_10_7` | 31 | 4.7s |  |
| 768 | `ecma3/Date/e15_9_5_10_8` | 33 | 8.8s |  |
| 769 | `ecma3/Date/e15_9_5_10_9` | 33 | 8.8s |  |
| 770 | `ecma3/Date/e15_9_5_11_1` | 55 | 8.8s |  |
| 771 | `ecma3/Date/e15_9_5_11_3` | 55 | 8.8s |  |
| 772 | `ecma3/Date/e15_9_5_11_4` | 55 | 8.6s |  |
| 773 | `ecma3/Date/e15_9_5_11_5` | 55 | 2.7s |  |
| 774 | `ecma3/Date/e15_9_5_11_6` | 55 | 8.8s |  |
| 775 | `ecma3/Date/e15_9_5_11_7` | 55 | 8.8s |  |
| 776 | `ecma3/Date/e15_9_5_12_3` | 67 | 8.8s |  |
| 777 | `ecma3/Date/e15_9_5_12_4` | 67 | 8.7s |  |
| 778 | `ecma3/Date/e15_9_5_12_5` | 67 | 8.7s |  |
| 779 | `ecma3/Date/e15_9_5_12_6` | 55 | 8.9s |  |
| 780 | `ecma3/Date/e15_9_5_12_7` | 67 | 4.7s |  |
| 781 | `ecma3/Date/e15_9_5_12_8` | 2 | 8.8s |  |
| 782 | `ecma3/Date/e15_9_5_13_1` | 36 | 8.8s |  |
| 783 | `ecma3/Date/e15_9_5_13_2` | 36 | 8.8s |  |
| 784 | `ecma3/Date/e15_9_5_13_3` | 36 | 8.8s |  |
| 785 | `ecma3/Date/e15_9_5_13_4` | 36 | 8.6s |  |
| 786 | `ecma3/Date/e15_9_5_13_5` | 36 | 2.7s |  |
| 787 | `ecma3/Date/e15_9_5_13_6` | 60 | 8.9s |  |
| 788 | `ecma3/Date/e15_9_5_13_7` | 60 | 8.8s |  |
| 789 | `ecma3/Date/e15_9_5_13_8` | 2 | 8.8s |  |
| 790 | `ecma3/Date/e15_9_5_14` | 44 | 9.0s |  |
| 791 | `ecma3/Date/e15_9_5_15` | 58 | 8.9s |  |
| 792 | `ecma3/Date/e15_9_5_16` | 51 | 8.9s |  |
| 793 | `ecma3/Date/e15_9_5_17` | 51 | 8.9s |  |
| 794 | `ecma3/Date/e15_9_5_18` | 51 | 8.9s |  |
| 795 | `ecma3/Date/e15_9_5_19` | 51 | 4.7s |  |
| 796 | `ecma3/Date/e15_9_5_2` | 15 | 8.9s |  |
| 797 | `ecma3/Date/e15_9_5_20` | 79 | 9.0s |  |
| 798 | `ecma3/Date/e15_9_5_21_1` | 9 | 8.9s |  |
| 799 | `ecma3/Date/e15_9_5_21_2` | 1 | 8.8s |  |
| 800 | `ecma3/Date/e15_9_5_21_3` | 1 | 8.8s |  |
| 801 | `ecma3/Date/e15_9_5_21_4` | 1 | 2.7s |  |
| 802 | `ecma3/Date/e15_9_5_21_5` | 1 | 8.7s |  |
| 803 | `ecma3/Date/e15_9_5_21_6` | 1 | 8.7s |  |
| 804 | `ecma3/Date/e15_9_5_21_7` | 1 | 2.6s |  |
| 805 | `ecma3/Date/e15_9_5_21_8` | 2 | 8.9s |  |
| 806 | `ecma3/Date/e15_9_5_22_2` | 11 | 8.8s |  |
| 807 | `ecma3/Date/e15_9_5_22_3` | 11 | 4.5s |  |
| 808 | `ecma3/Date/e15_9_5_22_4` | 11 | 8.6s |  |
| 809 | `ecma3/Date/e15_9_5_22_5` | 11 | 2.7s |  |
| 810 | `ecma3/Date/e15_9_5_22_6` | 11 | 2.6s |  |
| 811 | `ecma3/Date/e15_9_5_22_7` | 11 | 2.6s |  |
| 812 | `ecma3/Date/e15_9_5_22_8` | 2 | 8.6s |  |
| 813 | `ecma3/Date/e15_9_5_23_1` | 18 | 9.0s |  |
| 814 | `ecma3/Date/e15_9_5_23_10` | 18 | 8.8s |  |
| 815 | `ecma3/Date/e15_9_5_23_11` | 18 | 8.8s |  |
| 816 | `ecma3/Date/e15_9_5_23_12` | 18 | 8.9s |  |
| 817 | `ecma3/Date/e15_9_5_23_13` | 18 | 9.0s |  |
| 818 | `ecma3/Date/e15_9_5_23_14` | 18 | 8.8s |  |
| 819 | `ecma3/Date/e15_9_5_23_15` | 18 | 2.9s |  |
| 820 | `ecma3/Date/e15_9_5_23_16` | 18 | 9.0s |  |
| 821 | `ecma3/Date/e15_9_5_23_17` | 18 | 8.8s |  |
| 822 | `ecma3/Date/e15_9_5_23_18` | 18 | 8.7s |  |
| 823 | `ecma3/Date/e15_9_5_23_2` | 26 | 8.8s |  |
| 824 | `ecma3/Date/e15_9_5_23_3_rt` | 1 | 8.6s |  |
| 825 | `ecma3/Date/e15_9_5_23_4` | 44 | 8.7s |  |
| 826 | `ecma3/Date/e15_9_5_23_5` | 44 | 4.7s |  |
| 827 | `ecma3/Date/e15_9_5_23_6` | 44 | 2.8s |  |
| 828 | `ecma3/Date/e15_9_5_23_7` | 44 | 8.6s |  |
| 829 | `ecma3/Date/e15_9_5_23_8` | 42 | 8.7s |  |
| 830 | `ecma3/Date/e15_9_5_23_9` | 42 | 8.6s |  |
| 831 | `ecma3/Date/e15_9_5_24_1` | 16 | 8.7s |  |
| 832 | `ecma3/Date/e15_9_5_24_2` | 16 | 8.7s |  |
| 833 | `ecma3/Date/e15_9_5_24_3` | 16 | 4.7s |  |
| 834 | `ecma3/Date/e15_9_5_24_4` | 16 | 8.9s |  |
| 835 | `ecma3/Date/e15_9_5_24_5` | 16 | 4.7s |  |
| 836 | `ecma3/Date/e15_9_5_24_6` | 16 | 7.1s |  |
| 837 | `ecma3/Date/e15_9_5_24_7` | 16 | 7.1s |  |
| 838 | `ecma3/Date/e15_9_5_24_8` | 16 | 8.9s |  |
| 839 | `ecma3/Date/e15_9_5_25_1` | 153 | 9.2s |  |
| 840 | `ecma3/Date/e15_9_5_26_1` | 119 | 9.1s |  |
| 841 | `ecma3/Date/e15_9_5_27_1` | 119 | 9.1s |  |
| 842 | `ecma3/Date/e15_9_5_2_1` | 15 | 9.0s |  |
| 843 | `ecma3/Date/e15_9_5_2_2_rt` | 1 | 8.6s |  |
| 844 | `ecma3/Date/e15_9_5_3` | 15 | 8.7s |  |
| 845 | `ecma3/Date/e15_9_5_30_1` | 144 | 9.1s |  |
| 846 | `ecma3/Date/e15_9_5_31_1` | 126 | 9.2s |  |
| 847 | `ecma3/Date/e15_9_5_32_1` | 180 | 9.0s |  |
| 848 | `ecma3/Date/e15_9_5_33_1` | 54 | 9.1s |  |
| 849 | `ecma3/Date/e15_9_5_34_1` | 164 | 11.2s |  |
| 850 | `ecma3/Date/e15_9_5_36_1` | 54 | 9.2s |  |
| 851 | `ecma3/Date/e15_9_5_36_2` | 54 | 9.1s |  |
| 852 | `ecma3/Date/e15_9_5_36_3` | 54 | 9.1s |  |
| 853 | `ecma3/Date/e15_9_5_36_4` | 54 | 3.0s |  |
| 854 | `ecma3/Date/e15_9_5_36_5` | 162 | 9.2s |  |
| 855 | `ecma3/Date/e15_9_5_36_6` | 108 | 9.2s |  |
| 856 | `ecma3/Date/e15_9_5_36_7` | 54 | 9.0s |  |
| 857 | `ecma3/Date/e15_9_5_37_1` | 360 | 9.5s |  |
| 858 | `ecma3/Date/e15_9_5_37_2` | 54 | 9.1s |  |
| 859 | `ecma3/Date/e15_9_5_37_3` | 36 | 9.1s |  |
| 860 | `ecma3/Date/e15_9_5_37_4` | 54 | 5.0s |  |
| 861 | `ecma3/Date/e15_9_5_37_5` | 54 | 9.0s |  |
| 862 | `ecma3/Date/e15_9_5_3_1_rt` | 1 | 8.9s |  |
| 863 | `ecma3/Date/e15_9_5_3_2` | 30 | 9.1s |  |
| 864 | `ecma3/Date/e15_9_5_42` | 15 | 9.1s |  |
| 865 | `ecma3/Date/e15_9_5_4_1` | 30 | 9.0s |  |
| 866 | `ecma3/Date/e15_9_5_4_2_rt` | 1 | 8.8s |  |
| 867 | `ecma3/Date/e15_9_5_5` | 15 | 9.1s |  |
| 868 | `ecma3/Date/e15_9_5_6` | 15 | 9.0s |  |
| 869 | `ecma3/Date/e15_9_5_7` | 16 | 9.1s |  |
| 870 | `ecma3/ErrorObject/e15_11_1` | 42 | 8.2s |  |
| 871 | `ecma3/ErrorObject/e15_11_2_1` | 30 | 8.0s |  |
| 872 | `ecma3/Exceptions/binding_001` | 2 | 3.8s |  |
| 873 | `ecma3/Exceptions/boolean_001_rt` | 6 | 8.1s |  |
| 874 | `ecma3/Exceptions/boolean_002_rt` | 6 | 8.2s |  |
| 875 | `ecma3/Exceptions/bug127913` | 1 | 7.8s |  |
| 876 | `ecma3/Exceptions/date_001_rt` | 1 | 7.7s |  |
| 877 | `ecma3/Exceptions/date_002_rt` | 1 | 7.7s |  |
| 878 | `ecma3/Exceptions/date_003_rt` | 1 | 7.7s |  |
| 879 | `ecma3/Exceptions/date_004_rt` | 1 | 7.7s |  |
| 880 | `ecma3/Exceptions/e15_11_4_4_1` | 9 | 8.1s |  |
| 881 | `ecma3/Exceptions/exception_001_rt` | 1 | 3.6s |  |
| 882 | `ecma3/Exceptions/exception_002_rt` | 1 | 7.8s |  |
| 883 | `ecma3/Exceptions/exception_003_rt` | 1 | 7.8s |  |
| 884 | `ecma3/Exceptions/exception_004_rt` | 1 | 7.8s |  |
| 885 | `ecma3/Exceptions/exception_005_rt` | 1 | 7.3s |  |
| 886 | `ecma3/Exceptions/exception_006_rt` | 1 | 7.8s |  |
| 887 | `ecma3/Exceptions/exception_007_rt` | 1 | 7.8s |  |
| 888 | `ecma3/Exceptions/exception_009` | 1 | 7.8s |  |
| 889 | `ecma3/Exceptions/exception_010_rt` | 1 | 7.7s |  |
| 890 | `ecma3/Exceptions/exception_014_rt` | 2 | 7.7s |  |
| 891 | `ecma3/Exceptions/expression_002_rt` | 1 | 7.8s |  |
| 892 | `ecma3/Exceptions/expression_003_rt` | 1 | 7.8s |  |
| 893 | `ecma3/Exceptions/expression_004_rt` | 1 | 7.8s |  |
| 894 | `ecma3/Exceptions/expression_005_rt` | 1 | 7.8s |  |
| 895 | `ecma3/Exceptions/expression_006_rt` | 1 | 7.8s |  |
| 896 | `ecma3/Exceptions/expression_007_rt` | 1 | 7.8s |  |
| 897 | `ecma3/Exceptions/expression_008_rt` | 1 | 3.7s |  |
| 898 | `ecma3/Exceptions/expression_009_rt` | 1 | 7.9s |  |
| 899 | `ecma3/Exceptions/expression_010_rt` | 1 | 7.8s |  |
| 900 | `ecma3/Exceptions/expression_011_rt` | 1 | 6.1s |  |
| 901 | `ecma3/Exceptions/expression_012_rt` | 1 | 6.1s |  |
| 902 | `ecma3/Exceptions/expression_013_rt` | 1 | 6.2s |  |
| 903 | `ecma3/Exceptions/expression_014_rt` | 1 | 6.1s |  |
| 904 | `ecma3/Exceptions/expression_016_rt` | 1 | 6.5s |  |
| 905 | `ecma3/Exceptions/expression_017_rt` | 1 | 6.1s |  |
| 906 | `ecma3/Exceptions/expression_019_rt` | 1 | 6.1s |  |
| 907 | `ecma3/Exceptions/global_001_rt` | 1 | 6.0s |  |
| 908 | `ecma3/Exceptions/global_002_rt` | 1 | 6.0s |  |
| 909 | `ecma3/Exceptions/number_001_rt` | 1 | 6.2s |  |
| 910 | `ecma3/Exceptions/number_002_rt` | 1 | 2.8s |  |
| 911 | `ecma3/Exceptions/number_003_rt` | 4 | 6.2s |  |
| 912 | `ecma3/Exceptions/number_004_rt` | 4 | 6.2s |  |
| 913 | `ecma3/Exceptions/regress_58946` | 1 | 6.1s |  |
| 914 | `ecma3/Exceptions/regress_95101` | 2 | 6.1s |  |
| 915 | `ecma3/Exceptions/string_001_rt` | 1 | 6.1s |  |
| 916 | `ecma3/Exceptions/string_002_rt` | 1 | 6.3s |  |
| 917 | `ecma3/ExecutionContexts/e10_1_3` | 1 | 6.1s |  |
| 918 | `ecma3/ExecutionContexts/e10_1_3_1` | 8 | 6.2s |  |
| 919 | `ecma3/ExecutionContexts/e10_1_4_1` | 1 | 6.0s |  |
| 920 | `ecma3/ExecutionContexts/e10_1_4_10` | 1 | 6.0s |  |
| 921 | `ecma3/ExecutionContexts/e10_1_4_2` | 1 | 2.8s |  |
| 922 | `ecma3/ExecutionContexts/e10_1_4_8` | 1 | 6.1s |  |
| 923 | `ecma3/ExecutionContexts/e10_1_4_9` | 1 | 6.0s |  |
| 924 | `ecma3/ExecutionContexts/e10_1_5_1` | 1 | 6.0s |  |
| 925 | `ecma3/ExecutionContexts/e10_1_5_2` | 1 | 5.9s |  |
| 926 | `ecma3/ExecutionContexts/e10_1_5_3` | 1 | 6.0s |  |
| 927 | `ecma3/ExecutionContexts/e10_1_5_4` | 1 | 6.0s |  |
| 928 | `ecma3/ExecutionContexts/e10_1_6` | 9 | 6.0s |  |
| 929 | `ecma3/ExecutionContexts/e10_1_8_1` | 7 | 6.0s |  |
| 930 | `ecma3/ExecutionContexts/e10_1_8_2` | 8 | 6.0s |  |
| 931 | `ecma3/ExecutionContexts/e10_2_1` | 1 | 6.0s |  |
| 932 | `ecma3/ExecutionContexts/e10_2_3_1` | 2 | 6.0s |  |
| 933 | `ecma3/ExecutionContexts/e10_2_3_2` | 2 | 6.0s |  |
| 934 | `ecma3/Expressions/StrictEquality_001` | 7 | 5.9s |  |
| 935 | `ecma3/Expressions/e11_10_1` | 31 | 6.3s |  |
| 936 | `ecma3/Expressions/e11_10_2` | 1089 | 6.2s |  |
| 937 | `ecma3/Expressions/e11_10_3` | 1089 | 6.2s |  |
| 938 | `ecma3/Expressions/e11_11` | 62 | 6.3s |  |
| 939 | `ecma3/Expressions/e11_12_1` | 7 | 6.1s |  |
| 940 | `ecma3/Expressions/e11_12_3` | 1 | 6.0s |  |
| 941 | `ecma3/Expressions/e11_12_4` | 1 | 6.0s |  |
| 942 | `ecma3/Expressions/e11_13` | 7 | 5.5s |  |
| 943 | `ecma3/Expressions/e11_13_1` | 1 | 6.1s |  |
| 944 | `ecma3/Expressions/e11_13_2_1` | 30 | 6.4s |  |
| 945 | `ecma3/Expressions/e11_13_2_2` | 31 | 6.4s |  |
| 946 | `ecma3/Expressions/e11_13_2_3` | 40 | 6.6s |  |
| 947 | `ecma3/Expressions/e11_13_2_4` | 26 | 3.1s |  |
| 948 | `ecma3/Expressions/e11_13_2_5` | 26 | 6.3s |  |
| 949 | `ecma3/Expressions/e11_14_1` | 3 | 5.9s |  |
| 950 | `ecma3/Expressions/e11_1_1` | 7 | 6.0s |  |
| 951 | `ecma3/Expressions/e11_1_4` | 28 | 6.1s |  |
| 952 | `ecma3/Expressions/e11_1_5` | 20 | 7.9s |  |
| 953 | `ecma3/Expressions/e11_1_6` | 25 | 8.0s |  |
| 954 | `ecma3/Expressions/e11_2_1_1` | 254 | 12.2s |  |
| 955 | `ecma3/Expressions/e11_2_1_2` | 8 | 7.7s |  |
| 956 | `ecma3/Expressions/e11_2_1_3` | 2 | 7.7s |  |
| 957 | `ecma3/Expressions/e11_2_1_4_rt` | 2 | 7.7s |  |
| 958 | `ecma3/Expressions/e11_2_1_5` | 10 | 7.7s |  |
| 959 | `ecma3/Expressions/e11_2_2_10_rt` | 1 | 7.7s |  |
| 960 | `ecma3/Expressions/e11_2_2_11` | 1 | 7.7s |  |
| 961 | `ecma3/Expressions/e11_2_2_12_rt` | 1 | 7.6s |  |
| 962 | `ecma3/Expressions/e11_2_2_1_rt` | 1 | 7.8s |  |
| 963 | `ecma3/Expressions/e11_2_2_2_rt` | 1 | 7.9s |  |
| 964 | `ecma3/Expressions/e11_2_2_3_rt` | 1 | 7.7s |  |
| 965 | `ecma3/Expressions/e11_2_2_4_rt` | 1 | 3.5s |  |
| 966 | `ecma3/Expressions/e11_2_2_5_rt` | 1 | 3.4s |  |
| 967 | `ecma3/Expressions/e11_2_2_6_rt` | 1 | 3.5s |  |
| 968 | `ecma3/Expressions/e11_2_2_7_rt` | 1 | 7.7s |  |
| 969 | `ecma3/Expressions/e11_2_2_8_rt` | 1 | 7.7s |  |
| 970 | `ecma3/Expressions/e11_2_2_9_rt` | 1 | 7.5s |  |
| 971 | `ecma3/Expressions/e11_2_3_1` | 4 | 7.6s |  |
| 972 | `ecma3/Expressions/e11_2_3_3_rt` | 1 | 7.6s |  |
| 973 | `ecma3/Expressions/e11_2_3_4_rt` | 1 | 7.6s |  |
| 974 | `ecma3/Expressions/e11_2_3_5` | 1 | 7.6s |  |
| 975 | `ecma3/Expressions/e11_3_1` | 58 | 8.2s |  |
| 976 | `ecma3/Expressions/e11_3_2` | 58 | 8.4s |  |
| 977 | `ecma3/Expressions/e11_4_1` | 18 | 7.7s |  |
| 978 | `ecma3/Expressions/e11_4_2` | 24 | 7.8s |  |
| 979 | `ecma3/Expressions/e11_4_4` | 52 | 8.0s |  |
| 980 | `ecma3/Expressions/e11_4_5` | 52 | 7.9s |  |
| 981 | `ecma3/Expressions/e11_4_6` | 190 | 10.0s |  |
| 982 | `ecma3/Expressions/e11_4_7` | 146 | 9.2s |  |
| 983 | `ecma3/Expressions/e11_4_8` | 70 | 8.0s |  |
| 984 | `ecma3/Expressions/e11_4_9` | 27 | 7.7s |  |
| 985 | `ecma3/Expressions/e11_5_1` | 47 | 8.1s |  |
| 986 | `ecma3/Expressions/e11_5_2` | 58 | 8.3s |  |
| 987 | `ecma3/Expressions/e11_5_3` | 70 | 8.4s |  |
| 988 | `ecma3/Expressions/e11_6_1_1` | 12 | 7.7s |  |
| 989 | `ecma3/Expressions/e11_6_1_2` | 13 | 7.8s |  |
| 990 | `ecma3/Expressions/e11_6_2_1` | 18 | 8.0s |  |
| 991 | `ecma3/Expressions/e11_6_3` | 34 | 8.0s |  |
| 992 | `ecma3/Expressions/e11_7_1` | 1089 | 8.1s |  |
| 993 | `ecma3/Expressions/e11_7_2` | 2178 | 8.3s |  |
| 994 | `ecma3/Expressions/e11_7_3` | 1089 | 8.1s |  |
| 995 | `ecma3/Expressions/e11_8_1` | 53 | 8.2s |  |
| 996 | `ecma3/Expressions/e11_8_2` | 52 | 8.2s |  |
| 997 | `ecma3/Expressions/e11_8_3` | 56 | 8.2s |  |
| 998 | `ecma3/Expressions/e11_8_4` | 56 | 8.2s |  |
| 999 | `ecma3/Expressions/e11_8_7` | 29 | 7.9s |  |
| 1000 | `ecma3/Expressions/e11_9_1` | 47 | 8.1s |  |
| 1001 | `ecma3/Expressions/e11_9_2` | 47 | 8.2s |  |
| 1002 | `ecma3/Expressions/e11_9_3` | 47 | 8.1s |  |
| 1003 | `ecma3/Expressions/e11_9_6_1` | 6 | 7.9s |  |
| 1004 | `ecma3/Expressions/instanceof_001` | 14 | 7.9s |  |
| 1005 | `ecma3/Expressions/instanceof_002` | 6 | 7.8s |  |
| 1006 | `ecma3/Expressions/instanceof_003_rt` | 30 | 7.8s |  |
| 1007 | `ecma3/Expressions/instanceof_004_rt` | 1 | 7.7s |  |
| 1008 | `ecma3/Expressions/instanceof_006` | 1 | 7.8s |  |
| 1009 | `ecma3/Function/apply_001` | 4 | 7.8s |  |
| 1010 | `ecma3/Function/call_001_rt` | 1 | 7.8s |  |
| 1011 | `ecma3/Function/e15_3_4_3_1` | 14 | 7.9s |  |
| 1012 | `ecma3/Function/e15_3_4_4_1_rt` | 10 | 7.9s |  |
| 1013 | `ecma3/Function/e15_3_FPQA` | 2 | 7.7s |  |
| 1014 | `ecma3/Function/function` | 2 | 7.7s |  |
| 1015 | `ecma3/Function/regress_104584` | 3 | 3.6s |  |
| 1016 | `ecma3/Function/regress_137181` | 2 | 7.7s |  |
| 1017 | `ecma3/Function/regress_49286` | 2 | 7.7s |  |
| 1018 | `ecma3/Function/regress_58274_rt` | 7 | 7.8s |  |
| 1019 | `ecma3/Function/regress_97921` | 4 | 7.8s |  |
| 1020 | `ecma3/Function/scope_001_rt` | 8 | 7.9s |  |
| 1021 | `ecma3/Function/scope_002` | 8 | 7.9s |  |
| 1022 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 6 | 7.9s |  |
| 1023 | `ecma3/FunctionObjects/e15_3_1_1_2_rt` | 1 | 7.7s |  |
| 1024 | `ecma3/FunctionObjects/e15_3_1_1_3_rt` | 1 | 7.9s |  |
| 1025 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 13 | 8.1s |  |
| 1026 | `ecma3/FunctionObjects/e15_3_2_1_2_rt` | 1 | 7.8s |  |
| 1027 | `ecma3/FunctionObjects/e15_3_2_1_3_rt` | 1 | 7.8s |  |
| 1028 | `ecma3/FunctionObjects/e15_3_3_1_1` | 1 | 7.7s |  |
| 1029 | `ecma3/FunctionObjects/e15_3_3_1_2` | 1 | 7.7s |  |
| 1030 | `ecma3/FunctionObjects/e15_3_3_1_3` | 2 | 7.7s |  |
| 1031 | `ecma3/FunctionObjects/e15_3_3_1_4` | 1 | 7.7s |  |
| 1032 | `ecma3/FunctionObjects/e15_3_3_2` | 1 | 7.7s |  |
| 1033 | `ecma3/FunctionObjects/e15_3_4_1` | 1 | 7.7s |  |
| 1034 | `ecma3/FunctionObjects/e15_3_4_2` | 4 | 7.7s |  |
| 1035 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 4 | 7.7s |  |
| 1036 | `ecma3/FunctionObjects/e15_3_4_rt` | 4 | 7.8s |  |
| 1037 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 3 | 7.8s |  |
| 1038 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 4 | 7.8s |  |
| 1039 | `ecma3/FunctionObjects/e15_3_5_3_rt` | 1 | 7.7s |  |
| 1040 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 3 | 7.9s |  |
| 1041 | `ecma3/FunctionObjects/eapply_001_rt` | 4 | 7.8s |  |
| 1042 | `ecma3/FunctionObjects/ecall_1` | 3 | 7.7s |  |
| 1043 | `ecma3/GlobalObject/decodeURI` | 38 | 8.8s |  |
| 1044 | `ecma3/GlobalObject/decodeURIComponent` | 24 | 8.4s |  |
| 1045 | `ecma3/GlobalObject/e15_1_1_1` | 3 | 7.6s |  |
| 1046 | `ecma3/GlobalObject/e15_1_1_2` | 3 | 7.7s |  |
| 1047 | `ecma3/GlobalObject/e15_1_1_n` | 1 | 7.8s |  |
| 1048 | `ecma3/GlobalObject/e15_1_2_1_2_rt` | 1 | 7.7s |  |
| 1049 | `ecma3/GlobalObject/e15_1_2_2_1` | 276 | 10.8s |  |
| 1050 | `ecma3/GlobalObject/e15_1_2_2_2` | 31 | 8.2s |  |
| 1051 | `ecma3/GlobalObject/e15_1_2_3_1` | 186 | 16.0s |  |
| 1052 | `ecma3/GlobalObject/e15_1_2_3_2` | 153 | 9.8s |  |
| 1053 | `ecma3/GlobalObject/e15_1_2_4` | 983 | 8.6s |  |
| 1054 | `ecma3/GlobalObject/e15_1_2_5_1` | 531 | 8.5s |  |
| 1055 | `ecma3/GlobalObject/e15_1_2_5_2` | 85 | 8.0s |  |
| 1056 | `ecma3/GlobalObject/e15_1_2_5_3` | 514 | 8.2s |  |
| 1057 | `ecma3/GlobalObject/e15_1_2_6` | 62 | 9.8s |  |
| 1058 | `ecma3/GlobalObject/e15_1_2_7` | 55 | 9.5s |  |
| 1059 | `ecma3/GlobalObject/e15_1_2_n` | 1 | 7.8s |  |
| 1060 | `ecma3/GlobalObject/e15_1_3` | 2 | 7.8s |  |
| 1061 | `ecma3/GlobalObject/encodeURI` | 39 | 8.1s |  |
| 1062 | `ecma3/GlobalObject/encodeURIComponent` | 23 | 8.0s |  |
| 1063 | `ecma3/GlobalObject/undefined` | 3 | 7.8s |  |
| 1064 | `ecma3/JSON/AS3Types` | 26 | 8.6s |  |
| 1065 | `ecma3/JSON/Callbacks` | 7 | 8.0s |  |
| 1066 | `ecma3/JSON/Invalid` | 40 | 9.4s |  |
| 1067 | `ecma3/JSON/LargeString` | 1 | 7.9s |  |
| 1068 | `ecma3/JSON/Strings` | 21 | 7.9s |  |
| 1069 | `ecma3/JSON/e15_12_0` | 4 | 8.0s |  |
| 1070 | `ecma3/JSON/e15_12_1` | 36 | 9.1s |  |
| 1071 | `ecma3/JSON/e15_12_2` | 12 | 9.0s |  |
| 1072 | `ecma3/JSON/e15_12_3` | 33 | 8.7s |  |
| 1073 | `ecma3/JSON/regress` | 5 | 8.1s |  |
| 1074 | `ecma3/NativeObjects/e15_2_rt` | 9 | 7.9s |  |
| 1075 | `ecma3/Number/e15_7_3` | 2 | 7.8s |  |
| 1076 | `ecma3/Number/e15_7_3_1_1` | 2 | 7.8s |  |
| 1077 | `ecma3/Number/e15_7_3_1_2` | 4 | 8.0s |  |
| 1078 | `ecma3/Number/e15_7_3_1_3` | 1 | 7.8s |  |
| 1079 | `ecma3/Number/e15_7_3_2_1` | 1 | 7.8s |  |
| 1080 | `ecma3/Number/e15_7_3_2_2` | 2 | 7.7s |  |
| 1081 | `ecma3/Number/e15_7_3_2_3` | 2 | 7.9s |  |
| 1082 | `ecma3/Number/e15_7_3_2_4` | 1 | 7.5s |  |
| 1083 | `ecma3/Number/e15_7_3_3_1` | 1 | 3.6s |  |
| 1084 | `ecma3/Number/e15_7_3_3_2` | 2 | 3.6s |  |
| 1085 | `ecma3/Number/e15_7_3_3_3` | 2 | 7.8s |  |
| 1086 | `ecma3/Number/e15_7_3_3_4` | 1 | 3.1s |  |
| 1087 | `ecma3/Number/e15_7_3_4_1` | 1 | 7.7s |  |
| 1088 | `ecma3/Number/e15_7_3_4_2` | 2 | 7.6s |  |
| 1089 | `ecma3/Number/e15_7_3_4_3` | 2 | 7.8s |  |
| 1090 | `ecma3/Number/e15_7_3_4_4` | 1 | 7.3s |  |
| 1091 | `ecma3/Number/e15_7_3_5_1` | 1 | 7.8s |  |
| 1092 | `ecma3/Number/e15_7_3_5_2` | 2 | 3.6s |  |
| 1093 | `ecma3/Number/e15_7_3_5_3_rt` | 2 | 8.0s |  |
| 1094 | `ecma3/Number/e15_7_3_5_4` | 1 | 7.4s |  |
| 1095 | `ecma3/Number/e15_7_3_6_1` | 1 | 3.4s |  |
| 1096 | `ecma3/Number/e15_7_3_6_2` | 2 | 7.8s |  |
| 1097 | `ecma3/Number/e15_7_3_6_3_rt` | 2 | 7.8s |  |
| 1098 | `ecma3/Number/e15_7_3_6_4` | 1 | 1.2s |  |
| 1099 | `ecma3/Number/e15_7_4_1` | 1 | 7.7s |  |
| 1100 | `ecma3/Number/e15_7_4_2_1_rt` | 9 | 8.0s |  |
| 1101 | `ecma3/Number/e15_7_4_2_2_rt` | 2 | 7.5s |  |
| 1102 | `ecma3/Number/e15_7_4_2_3_rt` | 1 | 7.6s |  |
| 1103 | `ecma3/Number/e15_7_4_2_5` | 13 | 7.5s |  |
| 1104 | `ecma3/Number/e15_7_4_3_1_rt` | 7 | 7.5s |  |
| 1105 | `ecma3/Number/e15_7_4_3_2` | 3 | 7.6s |  |
| 1106 | `ecma3/Number/e15_7_4_3_3_rt` | 1 | 7.6s |  |
| 1107 | `ecma3/Number/e15_7_4_6_1` | 26 | 8.7s |  |
| 1108 | `ecma3/Number/e15_7_4__1_rt` | 3 | 7.7s |  |
| 1109 | `ecma3/Number/e15_7_4_rt` | 3 | 7.7s |  |
| 1110 | `ecma3/Number/ecma4_sealedtype_1_rt` | 1 | 7.9s |  |
| 1111 | `ecma3/Number/ecma4_sealedtype_2_rt` | 1 | 7.8s |  |
| 1112 | `ecma3/Number/ecma4_sealedtype_3_rt` | 1 | 7.6s |  |
| 1113 | `ecma3/Number/ecma4_sealedtype_4_rt` | 2 | 7.7s |  |
| 1114 | `ecma3/Number/ecma4_st_valueOf_1_rt` | 1 | 7.8s |  |
| 1115 | `ecma3/Number/ecma4_st_valueOf_2_rt` | 1 | 7.6s |  |
| 1116 | `ecma3/Number/ecma4_st_valueOf_3_rt` | 1 | 7.6s |  |
| 1117 | `ecma3/Number/toLocaleString2_rt` | 1 | 7.4s |  |
| 1118 | `ecma3/Number/toLocaleString3_rt` | 1 | 7.5s |  |
| 1119 | `ecma3/Number/toLocaleString4_rt` | 1 | 7.5s |  |
| 1120 | `ecma3/ObjectObjects/bug129539` | 3 | 7.5s |  |
| 1121 | `ecma3/ObjectObjects/class_001` | 10 | 7.6s |  |
| 1122 | `ecma3/ObjectObjects/class_002` | 9 | 7.6s |  |
| 1123 | `ecma3/ObjectObjects/class_003` | 7 | 7.5s |  |
| 1124 | `ecma3/ObjectObjects/class_004` | 7 | 7.5s |  |
| 1125 | `ecma3/ObjectObjects/class_005` | 2 | 7.5s |  |
| 1126 | `ecma3/ObjectObjects/class_006` | 1 | 7.4s |  |
| 1127 | `ecma3/ObjectObjects/e15_2_1_1_rt` | 54 | 10.6s |  |
| 1128 | `ecma3/ObjectObjects/e15_2_1_2_rt` | 3 | 7.8s |  |
| 1129 | `ecma3/ObjectObjects/e15_2_2_1_rt` | 47 | 8.3s |  |
| 1130 | `ecma3/ObjectObjects/e15_2_2_2` | 3 | 7.6s |  |
| 1131 | `ecma3/ObjectObjects/e15_2_3_1_1` | 1 | 7.7s |  |
| 1132 | `ecma3/ObjectObjects/e15_2_3_1_2` | 1 | 7.7s |  |
| 1133 | `ecma3/ObjectObjects/e15_2_3_1_3` | 1 | 7.8s |  |
| 1134 | `ecma3/ObjectObjects/e15_2_3_1_4` | 1 | 7.8s |  |
| 1135 | `ecma3/ObjectObjects/e15_2_3_1_rt` | 2 | 3.6s |  |
| 1136 | `ecma3/ObjectObjects/e15_2_3_rt` | 2 | 7.2s |  |
| 1137 | `ecma3/ObjectObjects/e15_2_4_1_rt` | 1 | 7.9s |  |
| 1138 | `ecma3/ObjectObjects/e15_2_4_2` | 10 | 8.1s |  |
| 1139 | `ecma3/ObjectObjects/e15_2_4_3` | 9 | 8.4s |  |
| 1140 | `ecma3/ObjectObjects/e8_6_2_6_001` | 1 | 7.9s |  |
| 1141 | `ecma3/ObjectObjects/isPrototypeOf` | 8 | 8.0s |  |
| 1142 | `ecma3/ObjectObjects/propertyIsEnumerable` | 5 | 7.9s |  |
| 1143 | `ecma3/ObjectObjects/regress_72773_rt` | 1 | 8.0s |  |
| 1144 | `ecma3/ObjectObjects/regress_79129_001` | 1 | 8.2s |  |
| 1145 | `ecma3/ObjectObjects/toLocaleString_rt` | 5 | 8.3s |  |
| 1146 | `ecma3/Statements/block` | 4 | 8.2s |  |
| 1147 | `ecma3/Statements/e12_10_1` | 8 | 6.3s |  |
| 1148 | `ecma3/Statements/e12_2_1` | 18 | 6.6s |  |
| 1149 | `ecma3/Statements/e12_5_1` | 6 | 6.2s |  |
| 1150 | `ecma3/Statements/e12_5_2` | 6 | 6.2s |  |
| 1151 | `ecma3/Statements/e12_5_3` | 12 | 6.4s |  |
| 1152 | `ecma3/Statements/e12_6_1_1` | 3 | 6.3s |  |
| 1153 | `ecma3/Statements/e12_6_2_1` | 1 | 6.2s |  |
| 1154 | `ecma3/Statements/e12_6_2_2` | 1 | 6.1s |  |
| 1155 | `ecma3/Statements/e12_6_2_3` | 1 | 6.2s |  |
| 1156 | `ecma3/Statements/e12_6_2_4` | 1 | 6.2s |  |
| 1157 | `ecma3/Statements/e12_6_2_5` | 1 | 6.2s |  |
| 1158 | `ecma3/Statements/e12_6_2_6` | 1 | 6.2s |  |
| 1159 | `ecma3/Statements/e12_6_2_7` | 1 | 6.2s |  |
| 1160 | `ecma3/Statements/e12_6_2_8` | 1 | 6.2s |  |
| 1161 | `ecma3/Statements/e12_6_3_1` | 1 | 6.2s |  |
| 1162 | `ecma3/Statements/e12_6_3_10` | 2 | 6.2s |  |
| 1163 | `ecma3/Statements/e12_6_3_11` | 1 | 6.2s |  |
| 1164 | `ecma3/Statements/e12_6_3_19` | 2 | 6.3s |  |
| 1165 | `ecma3/Statements/e12_6_3_2` | 1 | 6.2s |  |
| 1166 | `ecma3/Statements/e12_6_3_3` | 1 | 6.2s |  |
| 1167 | `ecma3/Statements/e12_6_3_4` | 9 | 6.3s |  |
| 1168 | `ecma3/Statements/e12_6_3_9_rt` | 1 | 6.3s |  |
| 1169 | `ecma3/Statements/e12_9_1` | 5 | 6.2s |  |
| 1170 | `ecma3/Statements/edowhile_001` | 4 | 6.2s |  |
| 1171 | `ecma3/Statements/edowhile_002` | 12 | 6.3s |  |
| 1172 | `ecma3/Statements/edowhile_003` | 10 | 6.2s |  |
| 1173 | `ecma3/Statements/edowhile_004` | 12 | 6.3s |  |
| 1174 | `ecma3/Statements/edowhile_005` | 3 | 6.3s |  |
| 1175 | `ecma3/Statements/edowhile_006` | 8 | 6.2s |  |
| 1176 | `ecma3/Statements/edowhile_007` | 36 | 6.3s |  |
| 1177 | `ecma3/Statements/eforin_001_500476` | 2 | 6.2s |  |
| 1178 | `ecma3/Statements/eif_001` | 1 | 6.3s |  |
| 1179 | `ecma3/Statements/elabel_001` | 5 | 6.1s |  |
| 1180 | `ecma3/Statements/elabel_002` | 4 | 6.2s |  |
| 1181 | `ecma3/Statements/eregress_131348` | 4 | 6.4s |  |
| 1182 | `ecma3/Statements/eregress_74474_001` | 3 | 6.3s |  |
| 1183 | `ecma3/Statements/eregress_74474_002` | 1 | 56.2s |  |
| 1184 | `ecma3/Statements/eregress_74474_003` | 1 | 56.8s |  |
| 1185 | `ecma3/Statements/eregress_83532_001` | 1 | 6.2s |  |
| 1186 | `ecma3/Statements/eregress_83532_002` | 1 | 6.2s |  |
| 1187 | `ecma3/Statements/eswitch_001` | 5 | 6.2s |  |
| 1188 | `ecma3/Statements/eswitch_002` | 10 | 6.3s |  |
| 1189 | `ecma3/Statements/eswitch_003` | 9 | 2.9s |  |
| 1190 | `ecma3/Statements/eswitch_004` | 18 | 6.2s |  |
| 1191 | `ecma3/Statements/etry_001` | 12 | 6.2s |  |
| 1192 | `ecma3/Statements/etry_003` | 9 | 6.5s |  |
| 1193 | `ecma3/Statements/etry_004` | 3 | 6.2s |  |
| 1194 | `ecma3/Statements/etry_005` | 3 | 6.2s |  |
| 1195 | `ecma3/Statements/etry_006` | 4 | 6.2s |  |
| 1196 | `ecma3/Statements/etry_007` | 2 | 6.1s |  |
| 1197 | `ecma3/Statements/etry_008` | 6 | 3.7s |  |
| 1198 | `ecma3/Statements/etry_009` | 2 | 7.9s |  |
| 1199 | `ecma3/Statements/etry_010` | 4 | 8.0s |  |
| 1200 | `ecma3/Statements/etry_012` | 9 | 8.2s |  |
| 1201 | `ecma3/Statements/ewhile_001` | 1 | 7.8s |  |
| 1202 | `ecma3/Statements/ewhile_002` | 8 | 8.0s |  |
| 1203 | `ecma3/Statements/ewhile_003` | 10 | 8.0s |  |
| 1204 | `ecma3/Statements/ewhile_004` | 13 | 8.0s |  |
| 1205 | `ecma3/Statements/expression` | 1 | 7.9s |  |
| 1206 | `ecma3/Statements/throw` | 2 | 8.1s |  |
| 1207 | `ecma3/String/Split` | 19 | 8.2s |  |
| 1208 | `ecma3/String/concat` | 21 | 8.1s |  |
| 1209 | `ecma3/String/e15_5_3` | 2 | 7.8s |  |
| 1210 | `ecma3/String/e15_5_3_1_1` | 2 | 7.9s |  |
| 1211 | `ecma3/String/e15_5_3_1_2` | 1 | 8.1s |  |
| 1212 | `ecma3/String/e15_5_3_1_3` | 1 | 8.0s |  |
| 1213 | `ecma3/String/e15_5_3_1_4` | 1 | 8.0s |  |
| 1214 | `ecma3/String/e15_5_3_2_1` | 116 | 12.5s |  |
| 1215 | `ecma3/String/e15_5_3_2_2` | 2 | 8.0s |  |
| 1216 | `ecma3/String/e15_5_4` | 6 | 7.9s |  |
| 1217 | `ecma3/String/e15_5_4_10_1_rt` | 24 | 8.9s |  |
| 1218 | `ecma3/String/e15_5_4_11_1` | 387 | 8.4s |  |
| 1219 | `ecma3/String/e15_5_4_11_2` | 96 | 8.2s |  |
| 1220 | `ecma3/String/e15_5_4_11_3` | 240 | 8.2s |  |
| 1221 | `ecma3/String/e15_5_4_11_4` | 96 | 8.1s |  |
| 1222 | `ecma3/String/e15_5_4_11_5` | 131 | 8.2s |  |
| 1223 | `ecma3/String/e15_5_4_11_6` | 96 | 8.2s |  |
| 1224 | `ecma3/String/e15_5_4_12_1` | 387 | 8.3s |  |
| 1225 | `ecma3/String/e15_5_4_12_2` | 1 | 8.2s |  |
| 1226 | `ecma3/String/e15_5_4_12_3` | 864 | 8.3s |  |
| 1227 | `ecma3/String/e15_5_4_12_4` | 128 | 8.2s |  |
| 1228 | `ecma3/String/e15_5_4_12_5` | 96 | 2.0s |  |
| 1229 | `ecma3/String/e15_5_4_13` | 17 | 8.0s |  |
| 1230 | `ecma3/String/e15_5_4_1_rt` | 2 | 7.7s |  |
| 1231 | `ecma3/String/e15_5_4_2_1` | 6 | 7.7s |  |
| 1232 | `ecma3/String/e15_5_4_2_3` | 4 | 7.7s |  |
| 1233 | `ecma3/String/e15_5_4_2_rt` | 8 | 7.8s |  |
| 1234 | `ecma3/String/e15_5_4_3_1` | 7 | 7.7s |  |
| 1235 | `ecma3/String/e15_5_4_3_2` | 4 | 7.8s |  |
| 1236 | `ecma3/String/e15_5_4_3_3_rt` | 1 | 7.8s |  |
| 1237 | `ecma3/String/e15_5_4_4_1` | 189 | 7.8s |  |
| 1238 | `ecma3/String/e15_5_4_4_2` | 33 | 8.1s |  |
| 1239 | `ecma3/String/e15_5_4_4_3` | 18 | 3.8s |  |
| 1240 | `ecma3/String/e15_5_4_4_4_rt` | 52 | 11.9s |  |
| 1241 | `ecma3/String/e15_5_4_5_1` | 95 | 7.8s |  |
| 1242 | `ecma3/String/e15_5_4_5_2` | 31 | 8.2s |  |
| 1243 | `ecma3/String/e15_5_4_5_3` | 28 | 7.9s |  |
| 1244 | `ecma3/String/e15_5_4_5_5` | 269 | 7.9s |  |
| 1245 | `ecma3/String/e15_5_4_5_6_rt` | 11 | 8.4s |  |
| 1246 | `ecma3/String/e15_5_4_6_1` | 578 | 8.0s |  |
| 1247 | `ecma3/String/e15_5_4_6_2_rt` | 232 | 9.6s |  |
| 1248 | `ecma3/String/e15_5_4_7_1` | 654 | 8.1s |  |
| 1249 | `ecma3/String/e15_5_4_7_2` | 72 | 8.2s |  |
| 1250 | `ecma3/String/e15_5_4_7_3_rt` | 5 | 8.0s |  |
| 1251 | `ecma3/String/e15_5_4_8_1_rt` | 30 | 9.2s |  |
| 1252 | `ecma3/String/e15_5_4_8_3` | 13 | 7.7s |  |
| 1253 | `ecma3/String/e15_5_4_8_477132` | 1 | 7.6s |  |
| 1254 | `ecma3/String/e15_5_4_9_1_rt` | 22 | 8.4s |  |
| 1255 | `ecma3/String/e15_5_5_1` | 10 | 8.1s |  |
| 1256 | `ecma3/String/ematch_001` | 24 | 7.7s |  |
| 1257 | `ecma3/String/ematch_002` | 32 | 7.8s |  |
| 1258 | `ecma3/String/ematch_003` | 10 | 7.7s |  |
| 1259 | `ecma3/String/ematch_004` | 8 | 7.8s |  |
| 1260 | `ecma3/String/eregress_104375` | 3 | 7.6s |  |
| 1261 | `ecma3/String/eregress_137879` | 7 | 7.6s |  |
| 1262 | `ecma3/String/eregress_137890` | 1 | 7.6s |  |
| 1263 | `ecma3/String/eregress_83293` | 9 | 7.7s |  |
| 1264 | `ecma3/String/ereplace_001` | 15 | 7.9s |  |
| 1265 | `ecma3/String/esplit_001` | 18 | 7.7s |  |
| 1266 | `ecma3/String/esplit_002` | 94 | 7.9s |  |
| 1267 | `ecma3/String/esplit_003` | 86 | 7.8s |  |
| 1268 | `ecma3/String/localeCompare_rt` | 4 | 7.7s |  |
| 1269 | `ecma3/String/replace_439458` | 5 | 7.7s |  |
| 1270 | `ecma3/String/search` | 8 | 7.8s |  |
| 1271 | `ecma3/String/split_407156` | 1 | 7.7s |  |
| 1272 | `ecma3/String/split_504567` | 1 | 7.6s |  |
| 1273 | `ecma3/String/substr` | 24 | 8.0s |  |
| 1274 | `ecma3/String/toLocaleLowerCase` | 387 | 8.2s |  |
| 1275 | `ecma3/String/toLocaleLowerCase2` | 96 | 8.1s |  |
| 1276 | `ecma3/String/toLocaleLowerCase3` | 240 | 8.1s |  |
| 1277 | `ecma3/String/toLocaleLowerCase4` | 96 | 8.0s |  |
| 1278 | `ecma3/String/toLocaleLowerCase5` | 131 | 8.1s |  |
| 1279 | `ecma3/String/toLocaleLowerCase6` | 96 | 2.0s |  |
| 1280 | `ecma3/String/toLocaleUpperCase` | 96 | 8.0s |  |
| 1281 | `ecma3/String/toLocaleUpperCase2` | 128 | 8.1s |  |
| 1282 | `ecma3/String/toLocaleUpperCase3` | 768 | 8.3s |  |
| 1283 | `ecma3/String/toLocaleUpperCase4` | 1 | 8.3s |  |
| 1284 | `ecma3/String/toLocaleUpperCase5` | 387 | 8.3s |  |
| 1285 | `ecma3/TypeConversion/e9_2_rt` | 36 | 8.1s |  |
| 1286 | `ecma3/TypeConversion/e9_3` | 15 | 7.8s |  |
| 1287 | `ecma3/TypeConversion/e9_3_1` | 9 | 7.9s |  |
| 1288 | `ecma3/TypeConversion/e9_3_1_1` | 189 | 10.8s |  |
| 1289 | `ecma3/TypeConversion/e9_3_1_2` | 12 | 8.0s |  |
| 1290 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94 | 8.8s |  |
| 1291 | `ecma3/TypeConversion/e9_4_1` | 19 | 7.9s |  |
| 1292 | `ecma3/TypeConversion/e9_4_2` | 19 | 7.9s |  |
| 1293 | `ecma3/TypeConversion/e9_5_2` | 56 | 8.3s |  |
| 1294 | `ecma3/TypeConversion/e9_6` | 34 | 8.0s |  |
| 1295 | `ecma3/TypeConversion/e9_7` | 38 | 8.1s |  |
| 1296 | `ecma3/TypeConversion/e9_9_1_rt` | 48 | 8.1s |  |
| 1297 | `ecma3/Types/e8_1` | 3 | 7.7s |  |
| 1298 | `ecma3/Types/e8_2` | 2 | 7.6s |  |
| 1299 | `ecma3/Types/e8_3` | 4 | 7.6s |  |
| 1300 | `ecma3/Types/e8_4` | 4 | 7.7s |  |
| 1301 | `ecma3/Types/e8_6_1` | 7 | 7.8s |  |
| 1302 | `ecma3/Unicode/u0000_BasicLatin` | 21 | 8.5s |  |
| 1303 | `ecma3/Unicode/u0080_Latin_1Supplement` | 21 | 7.5s |  |
| 1304 | `ecma3/Unicode/u0100_LatinExtended_A` | 21 | 7.4s |  |
| 1305 | `ecma3/Unicode/u0180_LatinExtended_B` | 21 | 7.5s |  |
| 1306 | `ecma3/Unicode/u0250_IPAExtensions` | 21 | 2.5s |  |
| 1307 | `ecma3/Unicode/u02B0_SpacingModifierLetters` | 21 | 2.5s |  |
| 1308 | `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | 21 | 2.5s |  |
| 1309 | `ecma3/Unicode/u0370_GreekandCoptic` | 21 | 2.5s |  |
| 1310 | `ecma3/Unicode/u0400_Cyrillic` | 42 | 2.5s |  |
| 1311 | `ecma3/Unicode/u0500_CyrillicSupplementary` | 21 | 2.5s |  |
| 1312 | `ecma3/Unicode/u0530_Armenian` | 21 | 2.5s |  |
| 1313 | `ecma3/Unicode/u0590_Hebrew` | 21 | 2.5s |  |
| 1314 | `ecma3/Unicode/u0600_Arabic` | 42 | 2.4s |  |
| 1315 | `ecma3/Unicode/u0700_Syriac` | 21 | 2.5s |  |
| 1316 | `ecma3/Unicode/u0780_Thaana` | 21 | 2.5s |  |
| 1317 | `ecma3/Unicode/u0900_Devanagari` | 21 | 2.5s |  |
| 1318 | `ecma3/Unicode/u0980_Bengali` | 21 | 2.5s |  |
| 1319 | `ecma3/Unicode/u0A00_Gurmukhi` | 21 | 2.5s |  |
| 1320 | `ecma3/Unicode/u0A80_Gujarati` | 21 | 2.5s |  |
| 1321 | `ecma3/Unicode/u0B00_Oriya` | 21 | 2.5s |  |
| 1322 | `ecma3/Unicode/u0B80_Tamil` | 21 | 2.5s |  |
| 1323 | `ecma3/Unicode/u0C00_Telugu` | 21 | 2.5s |  |
| 1324 | `ecma3/Unicode/u0C80_Kannada` | 21 | 2.5s |  |
| 1325 | `ecma3/Unicode/u0D00_Malayalam` | 21 | 2.5s |  |
| 1326 | `ecma3/Unicode/u0D80_Sinhala` | 21 | 2.5s |  |
| 1327 | `ecma3/Unicode/u0E00_Thai` | 21 | 2.5s |  |
| 1328 | `ecma3/Unicode/u0E80_Lao` | 21 | 7.4s |  |
| 1329 | `ecma3/Unicode/u0F00_Tibetan` | 42 | 2.5s |  |
| 1330 | `ecma3/Unicode/u1000_Myanmar` | 21 | 2.4s |  |
| 1331 | `ecma3/Unicode/u10A0_Georgian` | 21 | 2.4s |  |
| 1332 | `ecma3/Unicode/u1100_HangulJamo` | 42 | 2.5s |  |
| 1333 | `ecma3/Unicode/u1200_Ethiopic` | 42 | 2.5s |  |
| 1334 | `ecma3/Unicode/u13A0_Cherokee` | 21 | 2.4s |  |
| 1335 | `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | 63 | 2.5s |  |
| 1336 | `ecma3/Unicode/u1680_Ogham` | 21 | 2.4s |  |
| 1337 | `ecma3/Unicode/u16A0_Runic` | 21 | 2.4s |  |
| 1338 | `ecma3/Unicode/u1700_Tagalog` | 21 | 2.4s |  |
| 1339 | `ecma3/Unicode/u1720_Hanunoo` | 21 | 2.4s |  |
| 1340 | `ecma3/Unicode/u1740_Buhid` | 21 | 2.4s |  |
| 1341 | `ecma3/Unicode/u1760_Tagbanwa` | 21 | 2.5s |  |
| 1342 | `ecma3/Unicode/u1780_Khmer` | 21 | 2.5s |  |
| 1343 | `ecma3/Unicode/u1800_Mongolian` | 21 | 2.4s |  |
| 1344 | `ecma3/Unicode/u1E00_LatinExtendedAdditional` | 42 | 2.4s |  |
| 1345 | `ecma3/Unicode/u1F00_GreekExtended` | 42 | 2.4s |  |
| 1346 | `ecma3/Unicode/u2000_GeneralPunctuation` | 21 | 7.3s |  |
| 1347 | `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | 21 | 7.3s |  |
| 1348 | `ecma3/Unicode/u20A0_CurrencySymbols` | 21 | 7.3s |  |
| 1349 | `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | 21 | 2.4s |  |
| 1350 | `ecma3/Unicode/u2100_LetterlikeSymbols` | 21 | 2.3s |  |
| 1351 | `ecma3/Unicode/u2150_NumberForms` | 21 | 2.3s |  |
| 1352 | `ecma3/Unicode/u2190_Arrows` | 21 | 2.3s |  |
| 1353 | `ecma3/Unicode/u2200_MathematicalOperators` | 42 | 2.3s |  |
| 1354 | `ecma3/Unicode/u2300_MiscellaneousTechnical` | 42 | 7.2s |  |
| 1355 | `ecma3/Unicode/u2400_ControlPictures` | 21 | 2.4s |  |
| 1356 | `ecma3/Unicode/u2440_OpticalCharacterRecognition` | 21 | 2.3s |  |
| 1357 | `ecma3/Unicode/u2460_EnclosedAlphanumerics` | 21 | 2.3s |  |
| 1358 | `ecma3/Unicode/u2500_BoxDrawing` | 21 | 2.4s |  |
| 1359 | `ecma3/Unicode/u2580_BlockElements` | 21 | 2.3s |  |
| 1360 | `ecma3/Unicode/u25A0_GeometricShapes` | 21 | 2.4s |  |
| 1361 | `ecma3/Unicode/u2600_MiscellaneousSymbols` | 42 | 2.3s |  |
| 1362 | `ecma3/Unicode/u2700_Dingbats` | 21 | 2.4s |  |
| 1363 | `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | 21 | 7.2s |  |
| 1364 | `ecma3/Unicode/u27F0_SupplementalArrows_A` | 21 | 2.3s |  |
| 1365 | `ecma3/Unicode/u2800_BraillePatterns` | 42 | 2.4s |  |
| 1366 | `ecma3/Unicode/u2900_SupplementalArrows_B` | 21 | 2.3s |  |
| 1367 | `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | 21 | 2.3s |  |
| 1368 | `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | 42 | 2.3s |  |
| 1369 | `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | 21 | 2.3s |  |
| 1370 | `ecma3/Unicode/u2F00_KangxiRadicals` | 21 | 2.3s |  |
| 1371 | `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | 21 | 2.3s |  |
| 1372 | `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | 21 | 2.3s |  |
| 1373 | `ecma3/Unicode/u3040_Hiragana` | 21 | 2.3s |  |
| 1374 | `ecma3/Unicode/u30A0_Katakana` | 21 | 2.3s |  |
| 1375 | `ecma3/Unicode/u3100_Bopomofo` | 21 | 2.3s |  |
| 1376 | `ecma3/Unicode/u3130_HangulCompatibilityJamo` | 21 | 2.3s |  |
| 1377 | `ecma3/Unicode/u3190_Kanbun` | 21 | 2.3s |  |
| 1378 | `ecma3/Unicode/u31A0_BopomofoExtended` | 21 | 2.4s |  |
| 1379 | `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | 21 | 2.4s |  |
| 1380 | `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | 42 | 2.4s |  |
| 1381 | `ecma3/Unicode/u3300_CJKCompatibility` | 42 | 2.3s |  |
| 1382 | `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | 567 | 3.5s |  |
| 1383 | `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | 63 | 3.1s |  |
| 1384 | `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | 357 | 2.6s |  |
| 1385 | `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | 357 | 2.6s |  |
| 1386 | `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | 357 | 3.4s |  |
| 1387 | `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | 357 | 7.5s |  |
| 1388 | `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | 357 | 2.6s |  |
| 1389 | `ecma3/Unicode/uA000_YiSyllables` | 105 | 2.4s |  |
| 1390 | `ecma3/Unicode/uA490_YiRadicals` | 21 | 7.2s |  |
| 1391 | `ecma3/Unicode/uAC00_HangulSyllables` | 945 | 3.0s |  |
| 1392 | `ecma3/Unicode/uE000_PrivateUseArea` | 546 | 7.6s |  |
| 1393 | `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | 63 | 2.4s |  |
| 1394 | `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | 21 | 2.4s |  |
| 1395 | `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | 63 | 2.4s |  |
| 1396 | `ecma3/Unicode/uFE00_VariationSelectors` | 21 | 2.4s |  |
| 1397 | `ecma3/Unicode/uFE20_CombiningHalfMarks` | 21 | 2.4s |  |
| 1398 | `ecma3/Unicode/uFE30_CJKCompatibilityForms` | 21 | 7.3s |  |
| 1399 | `ecma3/Unicode/uFE50_SmallFormVariants` | 21 | 8.5s |  |
| 1400 | `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | 21 | 7.3s |  |
| 1401 | `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | 21 | 2.5s |  |
| 1402 | `ecma3/Unicode/uFFF0_Specials` | 21 | 7.3s |  |
| 1403 | `ecma3/Unicode/uc_001` | 4 | 7.4s |  |
| 1404 | `ecma3/Unicode/uc_003` | 6 | 7.4s |  |
| 1405 | `ecma3/Unicode/uc_004` | 8 | 7.4s |  |
| 1406 | `ecma3/Unicode/uc_005` | 10 | 7.5s |  |
| 1407 | `ecma3/Unicode/uc_006` | 56 | 7.7s |  |
| 1408 | `ecma3/Unicode/ucs4_bug_515947` | 3 | 7.3s |  |
| 1409 | `ecma3/instanceof/instanceof_001` | 2 | 7.3s |  |
| 1410 | `ecma3/instanceof/instanceof_002` | 5 | 7.4s |  |
| 1411 | `ecma3/instanceof/instanceof_003_rt` | 2 | 7.5s |  |
| 1412 | `ecma3/instanceof/regress_7635_rt` | 3 | 7.5s |  |
| 1413 | `misc/addNull` | 40 | 3.6s |  |
| 1414 | `misc/bug_490371` | 2 | 7.4s |  |
| 1415 | `misc/bug_521353` | 6 | 7.5s |  |
| 1416 | `misc/bug_532806` | 1 | 7.4s |  |
| 1417 | `misc/bug_534074` | 1 | 7.5s |  |
| 1418 | `misc/bug_547583` | 8 | 7.6s |  |
| 1419 | `misc/bug_598322` | 120 | 9.3s |  |
| 1420 | `misc/denseArrayDelete` | 1 | 7.6s |  |
| 1421 | `misc/getlex_anyname` | 1 | 7.6s |  |
| 1422 | `misc/md5_t` | 7 | 8.0s |  |
| 1423 | `misc/nsunbox` | 3 | 7.4s |  |
| 1424 | `misc/superInit` | 1 | 7.4s |  |
| 1425 | `misc/unchecked` | 1 | 7.4s |  |
| 1426 | `mops/lf32` | 20 | 26.3s |  |
| 1427 | `mops/lf64` | 21 | 7.6s |  |
| 1428 | `mops/li16` | 26 | 7.6s |  |
| 1429 | `mops/li32` | 20 | 7.7s |  |
| 1430 | `mops/li8` | 46 | 7.8s |  |
| 1431 | `mops/lix16` | 17 | 7.7s |  |
| 1432 | `mops/lix8` | 21 | 7.5s |  |
| 1433 | `mops/mops_basics` | 56 | 10.8s |  |
| 1434 | `mops/sf32` | 26 | 7.6s |  |
| 1435 | `mops/sf64` | 51 | 7.8s |  |
| 1436 | `mops/si16` | 28 | 7.6s |  |
| 1437 | `mops/si32` | 33 | 7.6s |  |
| 1438 | `mops/si8` | 28 | 7.7s |  |
| 1439 | `recursion/pcre_could_be_empty_branch` | 1 | 7.5s |  |
| 1440 | `recursion/pcre_find_firstassertedchar` | 2 | 7.6s |  |
| 1441 | `recursion/pcre_is_anchored` | 2 | 7.5s |  |
| 1442 | `recursion/pcre_is_startline` | 2 | 7.5s |  |
| 1443 | `recursion/xml_functions` | 3 | 7.6s |  |
| 1444 | `regress/bug_415080` | 1 | 7.3s |  |
| 1445 | `regress/bug_420755` | 27 | 8.1s |  |
| 1446 | `regress/bug_424341` | 1 | 7.3s |  |
| 1447 | `regress/bug_458419` | 1 | 7.7s |  |
| 1448 | `regress/bug_460872` | 1 | 7.6s |  |
| 1449 | `regress/bug_481942` | 1 | 7.6s |  |
| 1450 | `regress/bug_492046` | 1 | 7.6s |  |
| 1451 | `regress/bug_498979` | 1 | 7.6s |  |
| 1452 | `regress/bug_521353` | 49 | 3.5s |  |
| 1453 | `regress/bug_526295` | 2 | 7.7s |  |
| 1454 | `regress/bug_532791` | 1 | 7.6s |  |
| 1455 | `regress/bug_535882` | 1 | 7.6s |  |
| 1456 | `regress/bug_538107` | 2 | 7.6s |  |
| 1457 | `regress/bug_547295` | 2 | 7.6s |  |
| 1458 | `regress/bug_549389` | 1 | 7.5s |  |
| 1459 | `regress/bug_551587` | 6 | 7.6s |  |
| 1460 | `regress/bug_551587_2_swf10` | 2 | 7.7s |  |
| 1461 | `regress/bug_551587_2_swf11` | 2 | 7.6s |  |
| 1462 | `regress/bug_555544` | 1 | 7.7s |  |
| 1463 | `regress/bug_555705_orig` | 2 | 7.5s |  |
| 1464 | `regress/bug_558863_swf11` | 1 | 7.7s |  |
| 1465 | `regress/bug_559565` | 1 | 7.6s |  |
| 1466 | `regress/bug_561191` | 19 | 7.7s |  |
| 1467 | `regress/bug_564839` | 21 | 7.9s |  |
| 1468 | `regress/bug_588041` | 1 | 7.6s |  |
| 1469 | `regress/bug_593383` | 109 | 9.1s |  |
| 1470 | `regress/bug_598683` | 2 | 7.6s |  |
| 1471 | `regress/bug_599357` | 53 | 9.0s |  |
| 1472 | `regress/bug_609416_swf11` | 1 | 7.7s |  |
| 1473 | `regress/bug_615544` | 2 | 7.6s |  |
| 1474 | `regress/bug_637809` | 3 | 7.6s |  |
| 1475 | `regress/bug_642535` | 8 | 7.7s |  |
| 1476 | `regress/bug_643009` | 6 | 7.6s |  |
| 1477 | `regress/bug_654761` | 2 | 7.6s |  |
| 1478 | `regress/bug_654807_swf12` | 170 | 8.2s |  |
| 1479 | `regress/bug_654807_swf13` | 170 | 8.2s |  |
| 1480 | `regress/bug_655315` | 2 | 7.6s |  |
| 1481 | `regress/bug_663469` | 51 | 7.6s |  |
| 1482 | `regress/bug_672012` | 1 | 7.6s |  |
| 1483 | `regress/bug_673284` | 1 | 7.8s |  |
| 1484 | `regress/bug_687838` | 111 | 8.5s |  |
| 1485 | `regress/bug_700613` | 5 | 7.6s |  |
| 1486 | `regress/bug_703238` | 27 | 7.5s |  |
| 1487 | `regress/bug_707133` | 2 | 7.7s |  |
| 1488 | `regress/bug_723461` | 6 | 7.6s |  |
| 1489 | `regress/security/bug_550269` | 2 | 7.6s |  |
| 1490 | `regress/security/bug_663469` | 5 | 7.6s |  |

## Ruffle-Matched Tests

**51 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `as3/Array/bug_535446` | 4 | 4 | 7.7s |  |
| 2 | `as3/Array/length_mods` | 5 | 11 | 8.0s |  |
| 3 | `as3/Expressions/asOperator/asOper` | 2 | 2 | 8.7s |  |
| 4 | `as3/Math/e15_1_2_2` | 1 | 1 | 3.6s |  |
| 5 | `as3/RegExp/replace` | 2 | 3 | 7.7s |  |
| 6 | `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | 1 | 1 | 7.5s |  |
| 7 | `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | 1 | 1 | 7.6s |  |
| 8 | `as3/Types/Number/cos` | 1 | 1 | 7.6s |  |
| 9 | `as3/Types/Number/e15_7_4_6_1/swf14` | 18 | 18 | 8.8s |  |
| 10 | `as3/Types/Number/e15_7_4_6_1/swf15` | 3 | 3 | 8.8s |  |
| 11 | `e4x/XML/bug_564468` | 7 | 7 | 8.0s |  |
| 12 | `e4x/XML/e13_4_4_30` | 3 | 3 | 7.8s |  |
| 13 | `e4x/XML/misc_errors` | 2 | 2 | 8.4s |  |
| 14 | `e4x/XML/setNotification` | 13 | 13 | 3.9s |  |
| 15 | `e4x/XMLList/e13_5_4_18` | 2 | 2 | 7.7s |  |
| 16 | `ecma3/Array/e15_4_4_5` | 1 | 1 | 7.5s |  |
| 17 | `ecma3/Array/toLocaleString` | 1 | 1 | 7.5s |  |
| 18 | `ecma3/Date/e15_9_4_2_1` | 2 | 2 | 9.0s |  |
| 19 | `ecma3/Date/e15_9_5_10` | 3 | 3 | 9.3s |  |
| 20 | `ecma3/Date/e15_9_5_10_1` | 33 | 33 | 8.8s |  |
| 21 | `ecma3/Date/e15_9_5_10_10` | 31 | 31 | 8.8s |  |
| 22 | `ecma3/Date/e15_9_5_10_11` | 93 | 93 | 8.9s |  |
| 23 | `ecma3/Date/e15_9_5_11` | 3 | 3 | 8.7s |  |
| 24 | `ecma3/Date/e15_9_5_12` | 3 | 3 | 8.8s |  |
| 25 | `ecma3/Date/e15_9_5_12_1` | 67 | 67 | 8.8s |  |
| 26 | `ecma3/Date/e15_9_5_13` | 3 | 3 | 8.9s |  |
| 27 | `ecma3/Date/e15_9_5_15_1` | 3 | 3 | 8.8s |  |
| 28 | `ecma3/Date/e15_9_5_17_1` | 3 | 3 | 8.8s |  |
| 29 | `ecma3/Date/e15_9_5_22_1` | 66 | 66 | 8.8s |  |
| 30 | `ecma3/Date/e15_9_5_28_1` | 3 | 3 | 9.1s |  |
| 31 | `ecma3/Date/e15_9_5_29_1` | 1 | 1 | 9.1s |  |
| 32 | `ecma3/Date/e15_9_5_35_1` | 9 | 9 | 9.1s |  |
| 33 | `ecma3/Date/e15_9_5_4` | 14 | 14 | 9.0s |  |
| 34 | `ecma3/JSON/Classes` | 1 | 3 | 8.1s |  |
| 35 | `ecma3/JSON/adhoc` | 7 | 7 | 8.8s |  |
| 36 | `ecma3/Number/e15_7_1` | 1 | 1 | 8.2s |  |
| 37 | `ecma3/Number/e15_7_2` | 1 | 1 | 9.0s |  |
| 38 | `ecma3/Number/e15_7_4_2_4` | 1 | 1 | 9.3s |  |
| 39 | `ecma3/Number/e15_7_4_7_1` | 3 | 10 | 8.1s |  |
| 40 | `ecma3/Number/eregress_121952` | 1 | 1 | 8.1s |  |
| 41 | `ecma3/Number/toStringLimits` | 1 | 1 | 7.6s |  |
| 42 | `ecma3/Number/tostring_001` | 2 | 2 | 7.6s |  |
| 43 | `ecma3/String/e15_5_1` | 1 | 1 | 8.3s |  |
| 44 | `ecma3/String/e15_5_2` | 1 | 1 | 8.6s |  |
| 45 | `ecma3/TypeConversion/e9_8_1` | 1 | 1 | 7.8s |  |
| 46 | `ecma3/Types/e8_5` | 3 | 3 | 7.9s |  |
| 47 | `regress/bug_478501` | 1 | 1 | 7.6s |  |
| 48 | `regress/bug_479786` | 1 | 1 | 7.6s |  |
| 49 | `regress/bug_558863_swf10` | 1 | 1 | 7.7s |  |
| 50 | `regress/bug_609416_swf10` | 1 | 1 | 7.6s |  |
| 51 | `regress/bug_638233` | 2 | 2 | 7.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as3/Array/insertremove` | 99.7% | 30766 | 30870 | 104 |  |
| 2 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321 | 323 | 2 |  |
| 3 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474 | 481 | 7 |  |
| 4 | `recursion/pcre_find_fixedlength` | 95.0% | 19 | 20 | 1 |  |
| 5 | `e4x/XML/e13_4_4_17` | 94.7% | 18 | 19 | 1 |  |
| 6 | `ecma3/Number/toLocaleString_rt` | 91.7% | 44 | 48 | 4 |  |
| 7 | `ecma3/ObjectObjects/hasOwnProperty` | 90.0% | 9 | 10 | 1 |  |
| 8 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54 | 60 | 6 |  |
| 9 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8 | 9 | 1 |  |
| 10 | `e4x/XML/e13_4_4_36` | 81.2% | 13 | 16 | 3 |  |
| 11 | `e4x/Statements/e12_1` | 76.5% | 13 | 17 | 4 |  |
| 12 | `ecma3/Statements/eforin_001` | 75.0% | 12 | 16 | 4 |  |
| 13 | `e4x/Expressions/e11_1_2` | 73.9% | 17 | 23 | 6 |  |
| 14 | `ecma3/Unicode/utf8count` | 66.7% | 2 | 3 | 1 |  |
| 15 | `regress/bug_550958` | 66.7% | 2 | 3 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/Definitions/Super/SuperInForLoop` | exit code 1 | 6.1s |  |
| 2 | `as3/Definitions/Super/SuperProps` | exit code 1 | 6.4s |  |
| 3 | `misc/bug_508617` | exit code 1 | 7.3s |  |
| 4 | `regress/bug_483783` | exit code 1 | 7.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**29 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as3/Array/insertremove` | 99.7% | 30766/30870 | 30870 | 30870 |  |
| 2 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321/323 | 323 | 323 |  |
| 3 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474/481 | 481 | 481 |  |
| 4 | `recursion/pcre_find_fixedlength` | 95.0% | 19/20 | 20 | 20 |  |
| 5 | `e4x/XML/e13_4_4_17` | 94.7% | 18/19 | 19 | 19 |  |
| 6 | `ecma3/Number/toLocaleString_rt` | 91.7% | 44/48 | 48 | 48 |  |
| 7 | `ecma3/ObjectObjects/hasOwnProperty` | 90.0% | 9/10 | 10 | 10 |  |
| 8 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54/60 | 60 | 60 |  |
| 9 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8/9 | 9 | 9 |  |
| 10 | `e4x/XML/e13_4_4_36` | 81.2% | 13/16 | 16 | 16 |  |
| 11 | `e4x/Statements/e12_1` | 76.5% | 13/17 | 17 | 17 |  |
| 12 | `ecma3/Statements/eforin_001` | 75.0% | 12/16 | 16 | 16 |  |
| 13 | `e4x/Expressions/e11_1_2` | 73.9% | 17/23 | 23 | 20 |  |
| 14 | `ecma3/Unicode/utf8count` | 66.7% | 2/3 | 3 | 3 |  |
| 15 | `regress/bug_550958` | 66.7% | 2/3 | 2 | 3 |  |
| 16 | `regress/bug_539328` | 46.7% | 7/15 | 8 | 15 |  |
| 17 | `e4x/Expressions/e11_1_4` | 37.8% | 14/37 | 37 | 34 |  |
| 18 | `ecma3/Exceptions/exception_011_rt` | 33.3% | 1/3 | 1 | 3 |  |
| 19 | `ecma3/Expressions/e11_6_1_3` | 33.3% | 3/9 | 9 | 9 |  |
| 20 | `e4x/XML/e13_4_4_2` | 26.7% | 4/15 | 14 | 15 |  |
| 21 | `as3/String/localeCompare_585791/v9` | 25.0% | 2/8 | 8 | 8 |  |
| 22 | `e4x/Regress/regress-524214` | 9.1% | 1/11 | 11 | 3 |  |
| 23 | `e4x/Global/e13_1_2_1` | 2.4% | 7/293 | 293 | 10 |  |
| 24 | `as3/RuntimeErrors/Error1052InvalidUriPassed` | 0.0% | 0/1 | 1 | 1 |  |
| 25 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 0.0% | 0/1 | 1 | 1 |  |
| 26 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | 0.0% | 0/3 | 3 | 3 |  |
| 27 | `e4x/Regress/regress-263935` | 0.0% | 0/6 | 6 | 2 |  |
| 28 | `ecma3/Statements/e12_10` | 0.0% | 0/1 | 1 | 1 |  |
| 29 | `ecma3/Statements/eforin_002` | 0.0% | 0/10 | 10 | 10 |  |
