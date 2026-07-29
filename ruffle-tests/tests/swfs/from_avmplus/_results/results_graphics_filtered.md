# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 18:24 UTC

**Git SHA**: `8c3b7673f1`

**Run Duration**: 172m 21s

**Filtered**: 0 tests ignored out of 1574 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1574 |
| Passing | **1458** (92.6%) |
| Ruffle-matched | 51 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1509** (95.9%) |
| Failing | 65 |
| Total expected lines | 85996 |
| Matching lines | 85214 (99.1%) |
| Mismatched lines | 782 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 61 | 93.8% |
| Runtime Error | 4 | 6.2% |

## Passing Tests

**1458 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `as3/Array/regress_524122_swf10` | 1 | 7.1s |  |
| 2 | `as3/Array/regress_524122_swf11` | 1 | 7.0s |  |
| 3 | `as3/Array/regress_636535` | 6 | 7.0s |  |
| 4 | `as3/Array/regress_733384` | 24 | 7.1s |  |
| 5 | `as3/ByteArray/ByteArray` | 425 | 8.6s |  |
| 6 | `as3/ByteArray/ByteArrayLzma` | 397 | 8.5s |  |
| 7 | `as3/ByteArray/ByteArrayLzmaThirdParty` | 2 | 7.5s |  |
| 8 | `as3/ByteArray/ByteArray_bug662851_32bit` | 4 | 7.2s |  |
| 9 | `as3/ByteArray/ByteArray_bug662851_64bit` | 2 | 7.0s |  |
| 10 | `as3/Definitions/Classes/ClassDef/Bug162570` | 5 | 7.1s |  |
| 11 | `as3/Definitions/Classes/ClassDef/DefaultClass` | 15 | 7.4s |  |
| 12 | `as3/Definitions/Classes/ClassDef/DefaultClassPrototype` | 18 | 7.5s |  |
| 13 | `as3/Definitions/Classes/ClassDef/DefaultDynamicClass` | 32 | 7.4s |  |
| 14 | `as3/Definitions/Classes/ClassDef/DynamicClass` | 15 | 7.4s |  |
| 15 | `as3/Definitions/Classes/ClassDef/DynamicClassHasOwnProperty` | 1 | 7.0s |  |
| 16 | `as3/Definitions/Classes/ClassDef/DynamicClassMeth` | 2 | 7.0s |  |
| 17 | `as3/Definitions/Classes/ClassDef/DynamicClassProp` | 12 | 7.1s |  |
| 18 | `as3/Definitions/Classes/ClassDef/DynamicClassPrototype` | 18 | 7.4s |  |
| 19 | `as3/Definitions/Classes/ClassDef/DynamicClassSameMethPropName` | 4 | 7.1s |  |
| 20 | `as3/Definitions/Classes/ClassDef/FinalClassPrototype` | 18 | 7.3s |  |
| 21 | `as3/Definitions/Classes/ClassDef/FinalDefaultClass` | 32 | 7.4s |  |
| 22 | `as3/Definitions/Classes/ClassDef/FinalDefaultDynamicClass` | 32 | 6.6s |  |
| 23 | `as3/Definitions/Classes/ClassDef/FinalInternalClass` | 36 | 7.4s |  |
| 24 | `as3/Definitions/Classes/ClassDef/FinalInternalDynamicClass` | 32 | 6.6s |  |
| 25 | `as3/Definitions/Classes/ClassDef/FinalPublicClass` | 40 | 7.4s |  |
| 26 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClass` | 40 | 7.4s |  |
| 27 | `as3/Definitions/Classes/ClassDef/FinalPublicDynamicClassMethodAndProp` | 20 | 7.1s |  |
| 28 | `as3/Definitions/Classes/ClassDef/IntClassWithStrParamCons` | 4 | 7.1s |  |
| 29 | `as3/Definitions/Classes/ClassDef/InternalClass` | 32 | 6.7s |  |
| 30 | `as3/Definitions/Classes/ClassDef/InternalClassPrototype` | 18 | 7.3s |  |
| 31 | `as3/Definitions/Classes/ClassDef/InternalDynamicClass` | 32 | 7.4s |  |
| 32 | `as3/Definitions/Classes/ClassDef/PrivateStaticClassMethodAndProp` | 14 | 7.2s |  |
| 33 | `as3/Definitions/Classes/ClassDef/PublicClass` | 44 | 7.4s |  |
| 34 | `as3/Definitions/Classes/ClassDef/PublicClassMethodAndProp` | 20 | 7.2s |  |
| 35 | `as3/Definitions/Classes/ClassDef/PublicClassPrototype` | 18 | 7.3s |  |
| 36 | `as3/Definitions/Classes/ClassDef/PublicDynamicClass` | 44 | 7.5s |  |
| 37 | `as3/Definitions/Classes/ClassDef/PublicStaticFinalDynamicClassMethodAndProp` | 22 | 7.2s |  |
| 38 | `as3/Definitions/Classes/ClassDef/StatClassSameNamePackage` | 0 | 2.0s |  |
| 39 | `as3/Definitions/Classes/ClassDef/StaticClassMethodAndProp` | 16 | 7.1s |  |
| 40 | `as3/Definitions/Classes/ClassDef/bug113887` | 2 | 7.0s |  |
| 41 | `as3/Definitions/Classes/ClassDef/dynfinClassCons` | 1 | 7.0s |  |
| 42 | `as3/Definitions/Classes/ClassDef/dynfinClassDefCons` | 1 | 6.9s |  |
| 43 | `as3/Definitions/Classes/ClassDef/dynfinClassWithMultiStrParamCons` | 3 | 7.0s |  |
| 44 | `as3/Definitions/Classes/ClassDef/dynfinClassWithParamCons` | 1 | 7.0s |  |
| 45 | `as3/Definitions/Classes/ClassDef/dynfinClassWithStrParamCons` | 4 | 7.0s |  |
| 46 | `as3/Definitions/Classes/ClassDef/finClassNoParamCons` | 1 | 7.0s |  |
| 47 | `as3/Definitions/Classes/ClassDef/finalClassDefCons` | 1 | 3.5s |  |
| 48 | `as3/Definitions/Classes/ClassDef/finalClassWithParamCons` | 1 | 3.4s |  |
| 49 | `as3/Definitions/Classes/ClassDef/intClassDefCons` | 1 | 7.0s |  |
| 50 | `as3/Definitions/Classes/ClassDef/intClassNoParamCons` | 1 | 7.1s |  |
| 51 | `as3/Definitions/Classes/ClassDef/intClassWithParamCons` | 1 | 7.1s |  |
| 52 | `as3/Definitions/Classes/ClassDef/publicClassConsNoParam` | 1 | 7.1s |  |
| 53 | `as3/Definitions/Classes/ClassDef/publicClassDefCons` | 4 | 7.2s |  |
| 54 | `as3/Definitions/Classes/ClassDef/publicClassWithParamCons` | 1 | 7.1s |  |
| 55 | `as3/Definitions/Classes/ClassDef/testClassInitializers` | 3 | 7.1s |  |
| 56 | `as3/Definitions/Classes/ClassDef/testdynfinpublicClassInitializers` | 3 | 7.1s |  |
| 57 | `as3/Definitions/Classes/ClassDef/testinternalClassInitializers` | 3 | 7.1s |  |
| 58 | `as3/Definitions/Classes/Ext/AccNSStatMethSubClassMeth` | 6 | 7.1s |  |
| 59 | `as3/Definitions/Classes/Ext/AccNSStatPropSubClassMeth` | 6 | 7.1s |  |
| 60 | `as3/Definitions/Classes/Ext/AccStatMethIntermediateSubClassMeth` | 4 | 7.1s |  |
| 61 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMeth` | 6 | 7.1s |  |
| 62 | `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | 1 | 7.3s |  |
| 63 | `as3/Definitions/Classes/Ext/AccStatMethSubClassStatMeth` | 4 | 7.2s |  |
| 64 | `as3/Definitions/Classes/Ext/AccStatPropIntermediateSubClassMeth` | 6 | 7.2s |  |
| 65 | `as3/Definitions/Classes/Ext/AccStatPropSubClassInit` | 6 | 7.2s |  |
| 66 | `as3/Definitions/Classes/Ext/AccStatPropSubClassMeth` | 6 | 7.2s |  |
| 67 | `as3/Definitions/Classes/Ext/AccStatPropSubClassStatMeth` | 6 | 7.2s |  |
| 68 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | 3 | 7.3s |  |
| 69 | `as3/Definitions/Classes/Ext/AccStatPropViaSubClassWIntermediate` | 3 | 7.3s |  |
| 70 | `as3/Definitions/Classes/Ext/DynExtDefaultClass` | 23 | 8.0s |  |
| 71 | `as3/Definitions/Classes/Ext/DynExtDefaultClassFin` | 21 | 7.7s |  |
| 72 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPub` | 40 | 7.9s |  |
| 73 | `as3/Definitions/Classes/Ext/DynExtDefaultClassPubStat` | 24 | 7.7s |  |
| 74 | `as3/Definitions/Classes/Ext/DynExtDefaultClassStat` | 21 | 7.7s |  |
| 75 | `as3/Definitions/Classes/Ext/DynExtDynamicClass` | 16 | 7.6s |  |
| 76 | `as3/Definitions/Classes/Ext/DynExtDynamicClassFin` | 20 | 7.5s |  |
| 77 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPub` | 18 | 7.6s |  |
| 78 | `as3/Definitions/Classes/Ext/DynExtDynamicClassPubStat` | 16 | 7.6s |  |
| 79 | `as3/Definitions/Classes/Ext/DynExtDynamicClassStat` | 22 | 7.7s |  |
| 80 | `as3/Definitions/Classes/Ext/DynExtInternalClass` | 21 | 8.0s |  |
| 81 | `as3/Definitions/Classes/Ext/DynExtPublicClass` | 8 | 7.5s |  |
| 82 | `as3/Definitions/Classes/Ext/DynExtPublicClassFin` | 24 | 7.7s |  |
| 83 | `as3/Definitions/Classes/Ext/DynExtPublicClassPub` | 16 | 7.5s |  |
| 84 | `as3/Definitions/Classes/Ext/DynExtPublicClassPubStat` | 14 | 7.7s |  |
| 85 | `as3/Definitions/Classes/Ext/DynExtPublicClassStat` | 14 | 7.6s |  |
| 86 | `as3/Definitions/Classes/Ext/ExtDefaultClass` | 20 | 8.1s |  |
| 87 | `as3/Definitions/Classes/Ext/ExtDefaultClassPub` | 14 | 7.8s |  |
| 88 | `as3/Definitions/Classes/Ext/ExtDefaultClassPubStat` | 26 | 7.9s |  |
| 89 | `as3/Definitions/Classes/Ext/ExtDefaultClassStat` | 25 | 7.7s |  |
| 90 | `as3/Definitions/Classes/Ext/ExtDefaultProtClass` | 20 | 7.8s |  |
| 91 | `as3/Definitions/Classes/Ext/ExtDynamicClass` | 19 | 7.5s |  |
| 92 | `as3/Definitions/Classes/Ext/ExtDynamicClassPub` | 21 | 7.4s |  |
| 93 | `as3/Definitions/Classes/Ext/ExtDynamicClassPubStat` | 26 | 7.6s |  |
| 94 | `as3/Definitions/Classes/Ext/ExtDynamicClassStat` | 24 | 7.5s |  |
| 95 | `as3/Definitions/Classes/Ext/ExtError` | 40 | 7.5s |  |
| 96 | `as3/Definitions/Classes/Ext/ExtInternalClass` | 20 | 7.9s |  |
| 97 | `as3/Definitions/Classes/Ext/ExtPublicClass` | 7 | 7.5s |  |
| 98 | `as3/Definitions/Classes/Ext/ExtPublicClassFin` | 10 | 7.6s |  |
| 99 | `as3/Definitions/Classes/Ext/ExtPublicClassPub` | 14 | 7.7s |  |
| 100 | `as3/Definitions/Classes/Ext/ExtPublicClassStat` | 28 | 7.6s |  |
| 101 | `as3/Definitions/Classes/Ext/IntExtDefaultClass` | 22 | 6.5s |  |
| 102 | `as3/Definitions/Classes/Ext/IntExtDynamicClass` | 20 | 6.4s |  |
| 103 | `as3/Definitions/Classes/Ext/IntExtInternalClass` | 20 | 6.6s |  |
| 104 | `as3/Definitions/Classes/Ext/IntExtPublicClass` | 20 | 6.3s |  |
| 105 | `as3/Definitions/Classes/Ext/PubExtDefaultClass` | 19 | 5.9s |  |
| 106 | `as3/Definitions/Classes/Ext/PubExtDefaultClassFin` | 16 | 6.0s |  |
| 107 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPub` | 20 | 6.1s |  |
| 108 | `as3/Definitions/Classes/Ext/PubExtDefaultClassPubStat` | 29 | 6.0s |  |
| 109 | `as3/Definitions/Classes/Ext/PubExtDefaultClassStat` | 27 | 6.3s |  |
| 110 | `as3/Definitions/Classes/Ext/PubExtDynamicClass` | 18 | 6.0s |  |
| 111 | `as3/Definitions/Classes/Ext/PubExtDynamicClassFin` | 18 | 5.8s |  |
| 112 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPub` | 20 | 5.7s |  |
| 113 | `as3/Definitions/Classes/Ext/PubExtDynamicClassPubStat` | 29 | 6.0s |  |
| 114 | `as3/Definitions/Classes/Ext/PubExtDynamicClassStat` | 29 | 5.2s |  |
| 115 | `as3/Definitions/Classes/Ext/PubExtInternalClass` | 17 | 6.1s |  |
| 116 | `as3/Definitions/Classes/Ext/PubExtPublicClass` | 12 | 5.9s |  |
| 117 | `as3/Definitions/Classes/Ext/PubExtPublicClassFin` | 16 | 5.9s |  |
| 118 | `as3/Definitions/Classes/Ext/PubExtPublicClassStat` | 27 | 6.3s |  |
| 119 | `as3/Definitions/Classes/Ext/PubFinExtDefaultClass` | 22 | 6.5s |  |
| 120 | `as3/Definitions/Function/EmptyFunctionBody` | 24 | 5.8s |  |
| 121 | `as3/Definitions/Function/EmptyFunctionName` | 52 | 6.2s |  |
| 122 | `as3/Definitions/Function/FinalFunctionBody` | 12 | 5.7s |  |
| 123 | `as3/Definitions/Function/FinalFunctionName` | 28 | 5.8s |  |
| 124 | `as3/Definitions/Function/MultiOptArgFunction` | 12 | 5.7s |  |
| 125 | `as3/Definitions/Function/MultipleExtraArgFunction1` | 4 | 5.6s |  |
| 126 | `as3/Definitions/Function/MultipleExtraArgFunction2` | 4 | 5.8s |  |
| 127 | `as3/Definitions/Function/MultipleExtraArgFunction3` | 4 | 5.5s |  |
| 128 | `as3/Definitions/Function/NamespaceFunctionBody` | 12 | 5.5s |  |
| 129 | `as3/Definitions/Function/NamespaceFunctionName` | 28 | 5.5s |  |
| 130 | `as3/Definitions/Function/NoExtraArgFunction` | 4 | 5.3s |  |
| 131 | `as3/Definitions/Function/OneExtraArgFunction` | 20 | 2.8s |  |
| 132 | `as3/Definitions/Function/OneOptArgFunction` | 12 | 5.5s |  |
| 133 | `as3/Definitions/Function/OverrideFunctionBody` | 12 | 5.5s |  |
| 134 | `as3/Definitions/Function/OverrideFunctionName` | 28 | 5.5s |  |
| 135 | `as3/Definitions/Function/PrivateFunctionBody` | 12 | 5.4s |  |
| 136 | `as3/Definitions/Function/PrivateFunctionName` | 26 | 5.5s |  |
| 137 | `as3/Definitions/Function/PublicFunctionBody` | 24 | 5.7s |  |
| 138 | `as3/Definitions/Function/PublicFunctionName` | 54 | 5.8s |  |
| 139 | `as3/Definitions/Function/RestGlobal` | 17 | 5.4s |  |
| 140 | `as3/Definitions/Function/StaticFunctionBody` | 12 | 5.6s |  |
| 141 | `as3/Definitions/Function/StaticFunctionName` | 26 | 5.5s |  |
| 142 | `as3/Definitions/Function/StaticPrivateFunctionName` | 13 | 5.7s |  |
| 143 | `as3/Definitions/Function/StaticPublicFunctionName` | 13 | 5.6s |  |
| 144 | `as3/Definitions/Function/ThreeOptArgFunction` | 4 | 5.4s |  |
| 145 | `as3/Definitions/Function/VirtualFunctionBody` | 12 | 2.5s |  |
| 146 | `as3/Definitions/Function/VirtualFunctionName` | 28 | 5.0s |  |
| 147 | `as3/Definitions/Function/VoidEvaluation` | 3 | 5.4s |  |
| 148 | `as3/Definitions/Function/bug152222` | 2 | 5.4s |  |
| 149 | `as3/Definitions/Function/functionReturnTypes` | 319 | 6.8s |  |
| 150 | `as3/Definitions/Interfaces/Example_1_1_6` | 2 | 5.3s |  |
| 151 | `as3/Definitions/Interfaces/Example_9_3` | 4 | 5.8s |  |
| 152 | `as3/Definitions/Interfaces/ExtendMultipleInterfaces` | 8 | 5.6s |  |
| 153 | `as3/Definitions/Interfaces/GetSet` | 10 | 5.5s |  |
| 154 | `as3/Definitions/Interfaces/ImplementByExtension` | 6 | 7.3s |  |
| 155 | `as3/Definitions/Interfaces/ImplementMultipleInterfaces` | 8 | 7.0s |  |
| 156 | `as3/Definitions/Interfaces/InterfaceAsType` | 11 | 6.9s |  |
| 157 | `as3/Definitions/Interfaces/Lattice` | 7 | 6.8s |  |
| 158 | `as3/Definitions/Interfaces/bug127174` | 1 | 6.8s |  |
| 159 | `as3/Definitions/Super/SuperArgsCall` | 4 | 6.8s |  |
| 160 | `as3/Definitions/Super/SuperExprChainAccess` | 10 | 6.9s |  |
| 161 | `as3/Definitions/Super/SuperImplicitlyCalled` | 4 | 6.8s |  |
| 162 | `as3/Definitions/Super/SuperObject` | 1 | 6.8s |  |
| 163 | `as3/Definitions/Super/SuperObjectCall` | 1 | 6.8s |  |
| 164 | `as3/Definitions/Variable/ConstVariables_custom2` | 22 | 6.9s |  |
| 165 | `as3/Definitions/Variable/ModifyClassConstGlobally_rt` | 1 | 6.8s |  |
| 166 | `as3/Definitions/Variable/ModifyClassVariableInObjectInstance_rt` | 1 | 6.8s |  |
| 167 | `as3/Definitions/Variable/ModifyPackageConstGlobally_rt` | 1 | 6.7s |  |
| 168 | `as3/Definitions/Variable/ModifyVariables` | 25 | 6.9s |  |
| 169 | `as3/Definitions/Variable/ProtectedVariables` | 8 | 6.8s |  |
| 170 | `as3/Definitions/Variable/VarDefEmpty` | 44 | 7.1s |  |
| 171 | `as3/Definitions/Variable/VarDefOutside` | 20 | 6.7s |  |
| 172 | `as3/Definitions/Variable/VarDefOutsideNoVar` | 9 | 6.8s |  |
| 173 | `as3/Definitions/Variable/VarDefPrivate` | 44 | 7.2s |  |
| 174 | `as3/Definitions/Variable/VarDefPrivateStatic` | 44 | 7.3s |  |
| 175 | `as3/Definitions/Variable/VarDefPublic` | 44 | 7.2s |  |
| 176 | `as3/Definitions/Variable/VarDefPublicStatic` | 44 | 7.3s |  |
| 177 | `as3/Definitions/Variable/VarDefStatic` | 44 | 6.4s |  |
| 178 | `as3/Definitions/const/ConstAccessFromClass` | 1 | 6.7s |  |
| 179 | `as3/Definitions/const/ConstAccessWithinClass` | 1 | 6.7s |  |
| 180 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName` | 1 | 6.8s |  |
| 181 | `as3/Definitions/const/ConstAndClassFuncArgWithSameName2` | 1 | 6.8s |  |
| 182 | `as3/Definitions/const/ConstAndFunctionArgWithSameName` | 1 | 6.7s |  |
| 183 | `as3/Definitions/const/ConstAndFunctionArgWithSameName2` | 1 | 6.7s |  |
| 184 | `as3/Definitions/const/ConstAsVarReplacement` | 1 | 6.7s |  |
| 185 | `as3/Definitions/const/ConstConditionalInitialization` | 1 | 6.7s |  |
| 186 | `as3/Definitions/const/ConstConditionalInitializationInClass` | 1 | 6.7s |  |
| 187 | `as3/Definitions/const/ConstConditionalInitializationInClass2` | 1 | 6.7s |  |
| 188 | `as3/Definitions/const/ConstConditionalInitializationInClass3_rt` | 1 | 6.8s |  |
| 189 | `as3/Definitions/const/ConstConditionalInitializationInFunc` | 1 | 6.7s |  |
| 190 | `as3/Definitions/const/ConstInPackage` | 1 | 6.8s |  |
| 191 | `as3/Definitions/const/ConstInPackage2` | 1 | 6.7s |  |
| 192 | `as3/Definitions/const/ConstInPackageWithClass` | 1 | 6.7s |  |
| 193 | `as3/Definitions/const/ConstInPackageWithFunction` | 1 | 6.7s |  |
| 194 | `as3/Definitions/const/ConstInitializationInsideConstructor` | 1 | 3.3s |  |
| 195 | `as3/Definitions/const/ConstInitializationOutsideClass_rt` | 1 | 6.8s |  |
| 196 | `as3/Definitions/const/ConstInsideClass` | 1 | 6.7s |  |
| 197 | `as3/Definitions/const/ConstKeyword` | 1 | 6.4s |  |
| 198 | `as3/Definitions/const/ConstReinit_rt` | 1 | 6.8s |  |
| 199 | `as3/Definitions/const/ConstVarAsClassProp` | 2 | 6.7s |  |
| 200 | `as3/Definitions/const/ConstVarInsideClassFunction` | 1 | 6.8s |  |
| 201 | `as3/Definitions/const/ConstVarInsideClassFunction2_rt` | 1 | 6.8s |  |
| 202 | `as3/Definitions/const/ConstVarInsideGlobalFunction` | 1 | 6.1s |  |
| 203 | `as3/Definitions/const/ConstVarInsideGlobalFunction2` | 1 | 6.1s |  |
| 204 | `as3/Definitions/const/ConstVarInsideGlobalFunction3` | 1 | 2.7s |  |
| 205 | `as3/Definitions/const/ConstVarInsideGlobalFunction4` | 1 | 6.1s |  |
| 206 | `as3/Definitions/const/ConstVarInsideGlobalFunction5_rt` | 1 | 6.1s |  |
| 207 | `as3/Definitions/const/ConstVarInsideGlobalFunction6` | 4 | 6.1s |  |
| 208 | `as3/Definitions/const/ConstWithinClass` | 1 | 6.1s |  |
| 209 | `as3/Definitions/const/ConstWithinPackage` | 1 | 2.7s |  |
| 210 | `as3/Definitions/const/GlobalConstInitialization2_rt` | 1 | 6.1s |  |
| 211 | `as3/Definitions/const/GlobalConstInitialization_rt` | 1 | 6.1s |  |
| 212 | `as3/Definitions/const/StaticConst` | 1 | 6.0s |  |
| 213 | `as3/Definitions/const/StaticConstInDerivedClass` | 1 | 6.0s |  |
| 214 | `as3/Definitions/const/StaticConstInitializationOutsideClass_rt` | 1 | 6.1s |  |
| 215 | `as3/Expressions/QualifiedReferences/AS3NSReferences` | 3 | 2.8s |  |
| 216 | `as3/Expressions/QualifiedReferences/DescendantOperator` | 3 | 6.2s |  |
| 217 | `as3/Expressions/QualifiedReferences/FilterOperator` | 2 | 6.2s |  |
| 218 | `as3/Expressions/QualifiedReferences/MultipleNamespaces` | 7 | 6.1s |  |
| 219 | `as3/Expressions/QualifiedReferences/NSSingleFunc` | 3 | 6.1s |  |
| 220 | `as3/Expressions/QualifiedReferences/ReturnNSReference` | 3 | 6.1s |  |
| 221 | `as3/Expressions/QualifiedReferences/ReturnNamespace` | 1 | 6.1s |  |
| 222 | `as3/Expressions/asOperator/asOperator` | 75 | 6.6s |  |
| 223 | `as3/Expressions/asOperator/asOperatorConversions` | 48 | 6.5s |  |
| 224 | `as3/Expressions/asOperator/asOperatorMuliti` | 12 | 6.1s |  |
| 225 | `as3/Expressions/asOperator/asOperatorTypes` | 48 | 6.3s |  |
| 226 | `as3/Expressions/asOperator/asTypeError` | 2 | 6.1s |  |
| 227 | `as3/Expressions/deleteOperator/deleteArray` | 9 | 6.1s |  |
| 228 | `as3/Expressions/deleteOperator/deleteClass` | 1 | 6.1s |  |
| 229 | `as3/Expressions/deleteOperator/deleteFixedFunction` | 1 | 6.1s |  |
| 230 | `as3/Expressions/deleteOperator/deleteFixedVar` | 1 | 5.7s |  |
| 231 | `as3/Expressions/deleteOperator/deleteInstantiatedFunction` | 4 | 6.0s |  |
| 232 | `as3/Expressions/deleteOperator/deleteInstantiatedVar` | 2 | 6.0s |  |
| 233 | `as3/Expressions/deleteOperator/deleteNonexistentDynamicProperty` | 1 | 6.1s |  |
| 234 | `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | 1 | 6.1s |  |
| 235 | `as3/Expressions/deleteOperator/deleteNoninstantiatedFunction` | 2 | 6.0s |  |
| 236 | `as3/Expressions/deleteOperator/deleteNoninstantiatedVar` | 2 | 2.8s |  |
| 237 | `as3/Expressions/e11_2_2_1` | 4 | 6.1s |  |
| 238 | `as3/Expressions/e11_2_4` | 25 | 6.4s |  |
| 239 | `as3/Expressions/e11_4_3` | 86 | 6.7s |  |
| 240 | `as3/Expressions/e11_9_4` | 56 | 6.7s |  |
| 241 | `as3/Expressions/e11_9_5` | 56 | 3.4s |  |
| 242 | `as3/Expressions/indexProperties` | 36 | 6.6s |  |
| 243 | `as3/Expressions/isOperator/isOper` | 429 | 6.6s |  |
| 244 | `as3/Expressions/isOperator/isOperTypeError` | 2 | 6.2s |  |
| 245 | `as3/Expressions/logicalAssignment` | 16 | 6.3s |  |
| 246 | `as3/Expressions/logicalAssignment2` | 4 | 6.3s |  |
| 247 | `as3/Expressions/postfix` | 14 | 6.2s |  |
| 248 | `as3/Math/MathClass` | 2 | 2.9s |  |
| 249 | `as3/Math/MathUtils` | 7 | 6.2s |  |
| 250 | `as3/Math/e15_8_2_11_rest` | 6 | 6.3s |  |
| 251 | `as3/Math/e15_8_2_12_rest` | 12 | 6.4s |  |
| 252 | `as3/Math/op_divide_703238` | 9 | 6.9s |  |
| 253 | `as3/Math/op_subtract_703238` | 8 | 6.7s |  |
| 254 | `as3/MethodClosures/MethodClosure` | 1 | 6.9s |  |
| 255 | `as3/MethodClosures/MethodClosureFunc` | 1 | 6.8s |  |
| 256 | `as3/RegExp/bug_513020` | 2 | 6.7s |  |
| 257 | `as3/RegExp/eregress_122076` | 1 | 6.8s |  |
| 258 | `as3/RuntimeErrors/Error1002PrecisionArgOutOfRange` | 1 | 6.8s |  |
| 259 | `as3/RuntimeErrors/Error1003RadixArgOutOfRange` | 1 | 6.8s |  |
| 260 | `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | 1 | 6.8s |  |
| 261 | `as3/RuntimeErrors/Error1005ArrayIndexNotInteger` | 1 | 6.8s |  |
| 262 | `as3/RuntimeErrors/Error1006CallNonFunctionObject` | 2 | 6.8s |  |
| 263 | `as3/RuntimeErrors/Error1007InstantiationOnNonConstructor` | 1 | 6.7s |  |
| 264 | `as3/RuntimeErrors/Error1009CannotAccessPropOfNullRef` | 1 | 3.3s |  |
| 265 | `as3/RuntimeErrors/Error1010UndefinedTerm` | 1 | 6.7s |  |
| 266 | `as3/RuntimeErrors/Error1016DescendantsOpNotSupported` | 1 | 6.7s |  |
| 267 | `as3/RuntimeErrors/Error1034TypeCoercionFailed` | 1 | 6.7s |  |
| 268 | `as3/RuntimeErrors/Error1037CannotAssignMethod` | 1 | 6.8s |  |
| 269 | `as3/RuntimeErrors/Error1040InvalidRHSOfInstanceof` | 1 | 6.8s |  |
| 270 | `as3/RuntimeErrors/Error1041RHSOfIsMustBeClass` | 1 | 3.3s |  |
| 271 | `as3/RuntimeErrors/Error1056CannotCreatePropInSealedClass` | 1 | 6.8s |  |
| 272 | `as3/RuntimeErrors/Error1065VariableNotDefined` | 1 | 6.8s |  |
| 273 | `as3/RuntimeErrors/Error1066Function-body-NotAllowed` | 1 | 3.3s |  |
| 274 | `as3/RuntimeErrors/Error1069PropertyNotFound` | 1 | 6.6s |  |
| 275 | `as3/RuntimeErrors/Error1070MethodNotFound` | 1 | 6.7s |  |
| 276 | `as3/RuntimeErrors/Error1077IllegalReadOfWriteOnlyProp` | 1 | 6.9s |  |
| 277 | `as3/RuntimeErrors/Error1083XmlPrefixNotFound` | 1 | 6.9s |  |
| 278 | `as3/RuntimeErrors/Error1084XmlQNameProductionMismatch` | 1 | 6.9s |  |
| 279 | `as3/RuntimeErrors/Error1085XmlEndTagMissing` | 1 | 3.4s |  |
| 280 | `as3/RuntimeErrors/Error1086XmlMethodOnlyOnListWithOneItem` | 1 | 7.0s |  |
| 281 | `as3/RuntimeErrors/Error1087XmlAssignToIndexedXml` | 2 | 3.3s |  |
| 282 | `as3/RuntimeErrors/Error1088XmlDocNotWellFormed` | 1 | 7.0s |  |
| 283 | `as3/RuntimeErrors/Error1089XmlAssignToMoreThanOneItemList` | 2 | 6.9s |  |
| 284 | `as3/RuntimeErrors/Error1090XmlElementMalformed` | 1 | 3.3s |  |
| 285 | `as3/RuntimeErrors/Error1091XmlUnterminatedCdata` | 1 | 7.1s |  |
| 286 | `as3/RuntimeErrors/Error1093XmlUnterminatedDoctype` | 1 | 3.5s |  |
| 287 | `as3/RuntimeErrors/Error1094XmlUnterminatedComment` | 1 | 7.1s |  |
| 288 | `as3/RuntimeErrors/Error1097XmlUnterminatedProcessingInstr` | 1 | 7.0s |  |
| 289 | `as3/RuntimeErrors/Error1098XmlIllegalPrefixFoNoNamespace` | 1 | 3.4s |  |
| 290 | `as3/RuntimeErrors/Error1100RegExpFlagsArg` | 1 | 7.0s |  |
| 291 | `as3/RuntimeErrors/Error1104XmlDuplicateAttr` | 1 | 7.0s |  |
| 292 | `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | 2 | 7.1s |  |
| 293 | `as3/RuntimeErrors/Error1115NotAConstructor/v11` | 3 | 7.2s |  |
| 294 | `as3/RuntimeErrors/Error1116FunctionProtoApply2ndArgMustBeArr` | 1 | 7.2s |  |
| 295 | `as3/RuntimeErrors/Error1118IllegalCyclicalLoop` | 2 | 7.0s |  |
| 296 | `as3/ShellClasses/Dictionary` | 22 | 7.4s |  |
| 297 | `as3/ShellClasses/DictionarySubclass` | 22 | 7.8s |  |
| 298 | `as3/Statements/Exceptions/MultipleCatchBlocks2` | 7 | 7.2s |  |
| 299 | `as3/Statements/Exceptions/MultipleCatchBlocksArgument` | 1 | 7.2s |  |
| 300 | `as3/Statements/Exceptions/MultipleCatchBlocksEval` | 1 | 3.7s |  |
| 301 | `as3/Statements/Exceptions/MultipleCatchBlocksRange` | 1 | 7.2s |  |
| 302 | `as3/Statements/Exceptions/MultipleCatchBlocksRefErrorCaughtWithError` | 1 | 7.0s |  |
| 303 | `as3/Statements/Exceptions/MultipleCatchBlocksReference` | 1 | 7.2s |  |
| 304 | `as3/Statements/Exceptions/MultipleCatchBlocksType` | 1 | 7.3s |  |
| 305 | `as3/Statements/Exceptions/MultipleCatchBlocksType1` | 1 | 7.1s |  |
| 306 | `as3/Statements/Exceptions/MultipleCatchBlocksType2` | 1 | 7.1s |  |
| 307 | `as3/Statements/Exceptions/MultipleCatchBlocksType3` | 1 | 7.0s |  |
| 308 | `as3/Statements/Exceptions/MultipleCatchBlocksType4` | 1 | 7.0s |  |
| 309 | `as3/Statements/Exceptions/MultipleCatchBlocksType5` | 1 | 1.7s |  |
| 310 | `as3/Statements/Exceptions/MultipleCatchBlocksType6` | 1 | 1.6s |  |
| 311 | `as3/Statements/Exceptions/MultipleCatchBlocksType7` | 1 | 7.0s |  |
| 312 | `as3/Statements/Exceptions/MultipleCatchBlocksURI` | 1 | 7.2s |  |
| 313 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArg1` | 1 | 7.1s |  |
| 314 | `as3/Statements/Exceptions/MultipleCatchBlocksWithArgErrorCaughtByError` | 1 | 7.2s |  |
| 315 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDef1` | 1 | 7.3s |  |
| 316 | `as3/Statements/Exceptions/MultipleCatchBlocksWithDefErrorCaughtWithError` | 1 | 7.4s |  |
| 317 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEval1` | 1 | 7.3s |  |
| 318 | `as3/Statements/Exceptions/MultipleCatchBlocksWithEvalErrorCaughtByError` | 1 | 7.3s |  |
| 319 | `as3/Statements/Exceptions/MultipleCatchBlocksWithNoTypeErrorCatchBlock` | 1 | 7.3s |  |
| 320 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRange1` | 1 | 7.2s |  |
| 321 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRangeErrorCaughtByError` | 1 | 7.3s |  |
| 322 | `as3/Statements/Exceptions/MultipleCatchBlocksWithRefError1` | 1 | 7.3s |  |
| 323 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntax` | 1 | 1.7s |  |
| 324 | `as3/Statements/Exceptions/MultipleCatchBlocksWithSyntaxErrorCaughtByError` | 1 | 1.7s |  |
| 325 | `as3/Statements/Exceptions/MultipleCatchBlocksWithTwoType` | 2 | 7.3s |  |
| 326 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURI1` | 1 | 7.1s |  |
| 327 | `as3/Statements/Exceptions/MultipleCatchBlocksWithURICaughtByError` | 1 | 6.7s |  |
| 328 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUninitialized1` | 1 | 7.3s |  |
| 329 | `as3/Statements/Exceptions/MultipleCatchBlocksWithUnitializedCaughtWithError` | 1 | 7.5s |  |
| 330 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerify1` | 1 | 7.4s |  |
| 331 | `as3/Statements/Exceptions/MultipleCatchBlocksWithVerifyCaughtByError` | 1 | 1.2s |  |
| 332 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchBlocksTypeWithNoInnerCatchType` | 2 | 7.4s |  |
| 333 | `as3/Statements/Exceptions/NestedTryBlockWithMultipleCatchRefType` | 2 | 7.5s |  |
| 334 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideEighthCatch` | 2 | 7.5s |  |
| 335 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideFifthCatch` | 2 | 7.4s |  |
| 336 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSeventhCatch` | 2 | 3.8s |  |
| 337 | `as3/Statements/Exceptions/NestedTryWithMulitpleCatchInsideSixthCatch` | 2 | 3.8s |  |
| 338 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinally` | 2 | 7.4s |  |
| 339 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFinallyExceptionBubbling` | 1 | 7.5s |  |
| 340 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatch` | 2 | 7.4s |  |
| 341 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideFourthCatchWithoutMatchingCatch` | 2 | 7.4s |  |
| 342 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatch` | 2 | 7.4s |  |
| 343 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideSecondCatchWithoutMatchingCatch` | 2 | 7.4s |  |
| 344 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatch` | 2 | 7.1s |  |
| 345 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideThirdCatchWithoutMatchingCatch` | 1 | 7.0s |  |
| 346 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTry` | 1 | 7.0s |  |
| 347 | `as3/Statements/Exceptions/NestedTryWithMultipleCatchInsideTryWithoutMatchingCatch` | 1 | 7.0s |  |
| 348 | `as3/Statements/Exceptions/TryCatchBlockPackage` | 1 | 6.8s |  |
| 349 | `as3/Statements/Exceptions/TryCatchBlockPackage2` | 1 | 6.9s |  |
| 350 | `as3/Statements/Exceptions/TryCatchBlockPackage3` | 1 | 3.4s |  |
| 351 | `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | 7 | 7.0s |  |
| 352 | `as3/Statements/Exceptions/UserDefinedErrorsInPackage` | 1 | 6.8s |  |
| 353 | `as3/Statements/Exceptions/UserDefinedErrorsPackage` | 1 | 6.9s |  |
| 354 | `as3/Statements/Exceptions/UserDefinedErrorsPackage2` | 1 | 7.0s |  |
| 355 | `as3/Statements/Exceptions/UserDefinedErrorsPackage3` | 1 | 7.0s |  |
| 356 | `as3/Statements/Exceptions/UserDefinedErrorsPackageWithoutMatchingCatch` | 1 | 6.8s |  |
| 357 | `as3/Statements/e12_6_3_12` | 1 | 6.6s |  |
| 358 | `as3/Statements/for-each-in/eforeachin_001` | 8 | 7.1s |  |
| 359 | `as3/Statements/for-each-in/eforeachin_001_500476` | 2 | 6.7s |  |
| 360 | `as3/Statements/for-each-in/eforeachin_002` | 2 | 6.7s |  |
| 361 | `as3/Statements/switch/switch_000` | 3 | 6.6s |  |
| 362 | `as3/Statements/switch/switch_001` | 6 | 6.7s |  |
| 363 | `as3/Statements/switch/switch_002` | 5 | 6.6s |  |
| 364 | `as3/Statements/switch/switch_003` | 6 | 6.7s |  |
| 365 | `as3/String/localeCompare_585791/v12` | 8 | 6.7s |  |
| 366 | `as3/Types/Conversions/ExplicitConversions` | 54 | 6.9s |  |
| 367 | `as3/Types/Conversions/ImplicitConversions1_23` | 6 | 5.6s |  |
| 368 | `as3/Types/Conversions/ImplicitConversionsFalse` | 10 | 6.8s |  |
| 369 | `as3/Types/Conversions/ImplicitConversionsNaN` | 6 | 6.7s |  |
| 370 | `as3/Types/Conversions/ImplicitConversionsNeg1_23` | 10 | 6.9s |  |
| 371 | `as3/Types/Conversions/ImplicitConversionsNull` | 10 | 6.8s |  |
| 372 | `as3/Types/Conversions/ImplicitConversionsString` | 20 | 7.0s |  |
| 373 | `as3/Types/Conversions/ImplicitConversionsTrue` | 10 | 6.8s |  |
| 374 | `as3/Types/Conversions/ImplicitConversionsUndefined` | 11 | 6.8s |  |
| 375 | `as3/Types/Int/intConstructor` | 12 | 6.8s |  |
| 376 | `as3/Types/Int/intIs` | 12 | 6.8s |  |
| 377 | `as3/Types/Int/intMaxValue` | 4 | 6.7s |  |
| 378 | `as3/Types/Int/intMinValue` | 4 | 6.7s |  |
| 379 | `as3/Types/Int/intType` | 2 | 6.7s |  |
| 380 | `as3/Types/Int/signed_unsigned` | 6 | 6.5s |  |
| 381 | `as3/Types/Int/wraparound` | 16 | 3.3s |  |
| 382 | `as3/Types/Number/abs` | 41 | 6.9s |  |
| 383 | `as3/Types/Number/acos` | 29 | 6.8s |  |
| 384 | `as3/Types/Number/asin` | 34 | 6.9s |  |
| 385 | `as3/Types/Number/atan` | 33 | 6.9s |  |
| 386 | `as3/Types/Number/atan2` | 72 | 7.9s |  |
| 387 | `as3/Types/Number/ceil` | 49 | 7.2s |  |
| 388 | `as3/Types/Number/e` | 8 | 6.6s |  |
| 389 | `as3/Types/Number/exp` | 30 | 6.8s |  |
| 390 | `as3/Types/Number/floor` | 46 | 7.0s |  |
| 391 | `as3/Types/Number/ln10` | 8 | 6.3s |  |
| 392 | `as3/Types/Number/ln2` | 8 | 6.3s |  |
| 393 | `as3/Types/Number/log` | 32 | 7.2s |  |
| 394 | `as3/Types/Number/log10e` | 9 | 6.9s |  |
| 395 | `as3/Types/Number/log2e` | 9 | 6.5s |  |
| 396 | `as3/Types/Number/max` | 54 | 7.3s |  |
| 397 | `as3/Types/Number/min` | 54 | 7.3s |  |
| 398 | `as3/Types/Number/pi` | 8 | 7.0s |  |
| 399 | `as3/Types/Number/pow` | 96 | 8.5s |  |
| 400 | `as3/Types/Number/random` | 4 | 7.0s |  |
| 401 | `as3/Types/Number/round` | 54 | 7.4s |  |
| 402 | `as3/Types/Number/sin` | 28 | 7.1s |  |
| 403 | `as3/Types/Number/sqrt` | 69 | 7.2s |  |
| 404 | `as3/Types/Number/sqrt1_2` | 9 | 6.5s |  |
| 405 | `as3/Types/Number/sqrt2` | 8 | 6.5s |  |
| 406 | `as3/Types/Number/tan` | 28 | 7.1s |  |
| 407 | `as3/Types/Number/visibility/v15` | 34 | 7.2s |  |
| 408 | `as3/Types/Number/visibility/v16` | 9 | 7.2s |  |
| 409 | `as3/Types/uint/UintFunctionArg` | 17 | 7.3s |  |
| 410 | `as3/Types/uint/UintHex` | 1 | 7.0s |  |
| 411 | `as3/Types/uint/UintIs` | 12 | 7.1s |  |
| 412 | `as3/Types/uint/UintPublicClassMethodArg` | 24 | 7.6s |  |
| 413 | `as3/Types/uint/UintType` | 1 | 7.1s |  |
| 414 | `as3/Types/uint/UintVarAsClassProp` | 1 | 6.8s |  |
| 415 | `as3/Types/uint/UintVarOperationInFunc` | 1 | 6.9s |  |
| 416 | `as3/Types/uint/UintVarOperationInFuncRet` | 1 | 6.9s |  |
| 417 | `as3/Types/uint/UintVarOperations` | 17 | 7.2s |  |
| 418 | `as3/Vector/Vector_double_methods` | 11 | 7.2s |  |
| 419 | `as3/Vector/Vector_object_methods` | 12 | 7.1s |  |
| 420 | `as3/Vector/Vector_uint_methods` | 2 | 6.8s |  |
| 421 | `as3/Vector/bug504525/v10` | 1 | 6.8s |  |
| 422 | `as3/Vector/bug504525/v11` | 1 | 6.7s |  |
| 423 | `as3/Vector/bug_678952` | 2 | 6.7s |  |
| 424 | `as3/Vector/bug_683507` | 1 | 6.9s |  |
| 425 | `as3/Vector/concat` | 10 | 7.1s |  |
| 426 | `as3/Vector/concat_with_initializers` | 4 | 6.8s |  |
| 427 | `as3/Vector/constructor` | 18 | 7.1s |  |
| 428 | `as3/Vector/every` | 14 | 7.2s |  |
| 429 | `as3/Vector/every_initializers` | 5 | 6.7s |  |
| 430 | `as3/Vector/filter` | 9 | 7.2s |  |
| 431 | `as3/Vector/filter_initializers` | 5 | 6.9s |  |
| 432 | `as3/Vector/fixed_length` | 4 | 6.9s |  |
| 433 | `as3/Vector/foreach` | 6 | 3.5s |  |
| 434 | `as3/Vector/foreach_initializers` | 5 | 7.1s |  |
| 435 | `as3/Vector/get` | 7 | 6.9s |  |
| 436 | `as3/Vector/in` | 10 | 6.8s |  |
| 437 | `as3/Vector/in_initializers` | 10 | 6.9s |  |
| 438 | `as3/Vector/indexof` | 7 | 6.9s |  |
| 439 | `as3/Vector/indexof_initializers` | 7 | 6.9s |  |
| 440 | `as3/Vector/initializer_expressions` | 41 | 8.2s |  |
| 441 | `as3/Vector/initializer_large_vector` | 1 | 9.8s |  |
| 442 | `as3/Vector/initializer_ws` | 2 | 6.8s |  |
| 443 | `as3/Vector/insert_remove` | 542 | 7.4s |  |
| 444 | `as3/Vector/interface_method_return_type` | 5 | 7.5s |  |
| 445 | `as3/Vector/join` | 4 | 6.7s |  |
| 446 | `as3/Vector/join_initializers` | 4 | 7.2s |  |
| 447 | `as3/Vector/lastindexof` | 5 | 6.8s |  |
| 448 | `as3/Vector/lastindexof_initializers` | 7 | 6.7s |  |
| 449 | `as3/Vector/length` | 9 | 6.7s |  |
| 450 | `as3/Vector/length_initializers` | 3 | 6.7s |  |
| 451 | `as3/Vector/map` | 12 | 7.3s |  |
| 452 | `as3/Vector/map_initializers` | 7 | 6.9s |  |
| 453 | `as3/Vector/nested` | 8 | 8.2s |  |
| 454 | `as3/Vector/nested_initializers` | 5 | 6.8s |  |
| 455 | `as3/Vector/nonindexproperty/v10` | 51 | 7.9s |  |
| 456 | `as3/Vector/nonindexproperty/v11` | 55 | 7.8s |  |
| 457 | `as3/Vector/optimization_tests` | 14 | 7.8s |  |
| 458 | `as3/Vector/pop` | 12 | 6.9s |  |
| 459 | `as3/Vector/push` | 12 | 7.3s |  |
| 460 | `as3/Vector/put` | 8 | 7.0s |  |
| 461 | `as3/Vector/reverse` | 5 | 6.7s |  |
| 462 | `as3/Vector/reverse_initializers` | 4 | 6.7s |  |
| 463 | `as3/Vector/shift` | 12 | 7.1s |  |
| 464 | `as3/Vector/slice` | 1 | 6.7s |  |
| 465 | `as3/Vector/slice_initializers` | 5 | 6.8s |  |
| 466 | `as3/Vector/some` | 13 | 7.2s |  |
| 467 | `as3/Vector/some_initializers` | 6 | 6.9s |  |
| 468 | `as3/Vector/sort` | 9 | 7.2s |  |
| 469 | `as3/Vector/sort_initializers` | 1 | 6.9s |  |
| 470 | `as3/Vector/specialized_at_runtime` | 3 | 7.0s |  |
| 471 | `as3/Vector/splice` | 4 | 6.8s |  |
| 472 | `as3/Vector/static_initializer` | 4 | 6.7s |  |
| 473 | `as3/Vector/tostring` | 7 | 6.8s |  |
| 474 | `as3/Vector/tostring_initializer` | 5 | 6.7s |  |
| 475 | `as3/Vector/typechecking` | 10 | 7.1s |  |
| 476 | `as3/Vector/unshift` | 7 | 7.0s |  |
| 477 | `as3/Vector/vectorIndexRangeExceptions` | 1270 | 8.2s |  |
| 478 | `e4x/Expressions/e11_1_3` | 8 | 7.1s |  |
| 479 | `e4x/Expressions/e11_1_5` | 17 | 7.2s |  |
| 480 | `e4x/Expressions/e11_2_1` | 40 | 7.8s |  |
| 481 | `e4x/Expressions/e11_2_2` | 24 | 7.3s |  |
| 482 | `e4x/Expressions/e11_2_3` | 10 | 7.1s |  |
| 483 | `e4x/Expressions/e11_2_4` | 15 | 7.4s |  |
| 484 | `e4x/Expressions/e11_3_2` | 7 | 7.0s |  |
| 485 | `e4x/Expressions/e11_4_1` | 18 | 7.2s |  |
| 486 | `e4x/Expressions/e11_5_1` | 66 | 7.9s |  |
| 487 | `e4x/Expressions/e11_6_1` | 19 | 7.3s |  |
| 488 | `e4x/Expressions/e11_6_2` | 15 | 7.5s |  |
| 489 | `e4x/Expressions/e11_6_3` | 6 | 7.1s |  |
| 490 | `e4x/Expressions/kXMLBadQNameErr` | 5 | 7.0s |  |
| 491 | `e4x/Namespace/e13_2_1` | 19 | 7.1s |  |
| 492 | `e4x/Namespace/e13_2_2` | 22 | 7.2s |  |
| 493 | `e4x/Namespace/e13_2_3_1` | 3 | 6.4s |  |
| 494 | `e4x/Namespace/e13_2_4_1` | 3 | 6.4s |  |
| 495 | `e4x/Namespace/e13_2_4_2` | 4 | 6.4s |  |
| 496 | `e4x/QName/e13_3_1` | 22 | 6.5s |  |
| 497 | `e4x/QName/e13_3_3_1` | 3 | 5.9s |  |
| 498 | `e4x/QName/e13_3_4_1` | 2 | 6.4s |  |
| 499 | `e4x/QName/e13_3_4_2` | 4 | 6.3s |  |
| 500 | `e4x/QName/e13_3_5` | 13 | 6.5s |  |
| 501 | `e4x/Regress/b121219` | 2 | 6.4s |  |
| 502 | `e4x/Regress/error1085` | 2 | 6.3s |  |
| 503 | `e4x/Regress/regress-257679` | 2 | 6.4s |  |
| 504 | `e4x/Regress/regress-263934` | 2 | 6.3s |  |
| 505 | `e4x/Regress/regress-263936` | 2 | 6.3s |  |
| 506 | `e4x/Regress/regress-264369` | 2 | 6.3s |  |
| 507 | `e4x/Regress/regress-271545` | 6 | 6.3s |  |
| 508 | `e4x/Regress/regress-277650` | 2 | 3.0s |  |
| 509 | `e4x/Regress/regress-277664` | 2 | 6.4s |  |
| 510 | `e4x/Regress/regress-277683` | 2 | 6.4s |  |
| 511 | `e4x/Regress/regress-277779` | 2 | 6.3s |  |
| 512 | `e4x/Regress/regress-278112` | 4 | 2.9s |  |
| 513 | `e4x/Statements/e12_2` | 14 | 6.5s |  |
| 514 | `e4x/Statements/e12_3` | 5 | 6.4s |  |
| 515 | `e4x/TypeConversion/bug153363` | 3 | 6.3s |  |
| 516 | `e4x/TypeConversion/bug153363_2` | 3 | 6.4s |  |
| 517 | `e4x/TypeConversion/e10_1_1` | 3 | 6.4s |  |
| 518 | `e4x/TypeConversion/e10_1_2` | 5 | 6.4s |  |
| 519 | `e4x/TypeConversion/e10_2_1` | 5 | 6.4s |  |
| 520 | `e4x/TypeConversion/e10_2_1_1` | 5 | 6.3s |  |
| 521 | `e4x/TypeConversion/e10_2_1_2` | 13 | 6.5s |  |
| 522 | `e4x/TypeConversion/e10_2_2` | 2 | 6.4s |  |
| 523 | `e4x/TypeConversion/e10_3` | 7 | 6.6s |  |
| 524 | `e4x/TypeConversion/e10_3_1` | 2 | 6.4s |  |
| 525 | `e4x/TypeConversion/e10_4` | 9 | 6.6s |  |
| 526 | `e4x/TypeConversion/e10_4_1` | 8 | 6.4s |  |
| 527 | `e4x/Types/e9_1_1_1` | 32 | 7.2s |  |
| 528 | `e4x/Types/e9_1_1_10` | 2 | 6.4s |  |
| 529 | `e4x/Types/e9_1_1_11` | 2 | 6.0s |  |
| 530 | `e4x/Types/e9_1_1_12` | 2 | 5.9s |  |
| 531 | `e4x/Types/e9_1_1_13` | 2 | 6.0s |  |
| 532 | `e4x/Types/e9_1_1_2` | 6 | 6.6s |  |
| 533 | `e4x/Types/e9_1_1_3` | 5 | 6.5s |  |
| 534 | `e4x/Types/e9_1_1_4` | 2 | 6.4s |  |
| 535 | `e4x/Types/e9_1_1_5` | 2 | 5.9s |  |
| 536 | `e4x/Types/e9_1_1_6` | 11 | 6.3s |  |
| 537 | `e4x/Types/e9_1_1_7` | 2 | 2.4s |  |
| 538 | `e4x/Types/e9_1_1_8` | 2 | 5.9s |  |
| 539 | `e4x/Types/e9_1_1_9` | 20 | 6.8s |  |
| 540 | `e4x/Types/e9_2_1_1` | 11 | 6.5s |  |
| 541 | `e4x/Types/e9_2_1_10` | 2 | 7.0s |  |
| 542 | `e4x/Types/e9_2_1_2` | 19 | 7.2s |  |
| 543 | `e4x/Types/e9_2_1_3` | 2 | 6.6s |  |
| 544 | `e4x/Types/e9_2_1_4` | 2 | 6.6s |  |
| 545 | `e4x/Types/e9_2_1_5` | 2 | 3.1s |  |
| 546 | `e4x/Types/e9_2_1_6` | 2 | 6.5s |  |
| 547 | `e4x/Types/e9_2_1_7` | 2 | 6.6s |  |
| 548 | `e4x/Types/e9_2_1_8` | 2 | 7.0s |  |
| 549 | `e4x/Types/e9_2_1_9` | 11 | 7.2s |  |
| 550 | `e4x/XML/bug157597` | 2 | 7.0s |  |
| 551 | `e4x/XML/bug157597_2` | 2 | 6.6s |  |
| 552 | `e4x/XML/bug157735` | 2 | 7.0s |  |
| 553 | `e4x/XML/bug158506` | 2 | 7.0s |  |
| 554 | `e4x/XML/e13_4_1` | 18 | 7.2s |  |
| 555 | `e4x/XML/e13_4_2` | 36 | 7.7s |  |
| 556 | `e4x/XML/e13_4_3` | 35 | 7.6s |  |
| 557 | `e4x/XML/e13_4_3_1` | 5 | 7.1s |  |
| 558 | `e4x/XML/e13_4_3_2` | 8 | 7.1s |  |
| 559 | `e4x/XML/e13_4_3_3` | 8 | 7.1s |  |
| 560 | `e4x/XML/e13_4_3_4` | 11 | 7.2s |  |
| 561 | `e4x/XML/e13_4_3_5` | 5 | 7.1s |  |
| 562 | `e4x/XML/e13_4_3_6` | 10 | 7.2s |  |
| 563 | `e4x/XML/e13_4_3_7` | 31 | 7.2s |  |
| 564 | `e4x/XML/e13_4_3_8` | 41 | 7.3s |  |
| 565 | `e4x/XML/e13_4_3_9` | 11 | 7.2s |  |
| 566 | `e4x/XML/e13_4_4_1` | 3 | 7.1s |  |
| 567 | `e4x/XML/e13_4_4_10` | 11 | 7.2s |  |
| 568 | `e4x/XML/e13_4_4_11` | 12 | 7.2s |  |
| 569 | `e4x/XML/e13_4_4_12` | 15 | 7.3s |  |
| 570 | `e4x/XML/e13_4_4_13` | 7 | 7.2s |  |
| 571 | `e4x/XML/e13_4_4_14` | 12 | 7.1s |  |
| 572 | `e4x/XML/e13_4_4_15` | 16 | 7.2s |  |
| 573 | `e4x/XML/e13_4_4_16` | 25 | 7.3s |  |
| 574 | `e4x/XML/e13_4_4_18` | 16 | 7.6s |  |
| 575 | `e4x/XML/e13_4_4_19` | 16 | 7.6s |  |
| 576 | `e4x/XML/e13_4_4_20` | 11 | 7.1s |  |
| 577 | `e4x/XML/e13_4_4_21` | 16 | 7.2s |  |
| 578 | `e4x/XML/e13_4_4_22` | 15 | 7.2s |  |
| 579 | `e4x/XML/e13_4_4_23` | 17 | 7.5s |  |
| 580 | `e4x/XML/e13_4_4_24` | 22 | 7.4s |  |
| 581 | `e4x/XML/e13_4_4_25` | 15 | 7.3s |  |
| 582 | `e4x/XML/e13_4_4_26` | 6 | 7.2s |  |
| 583 | `e4x/XML/e13_4_4_27` | 21 | 7.3s |  |
| 584 | `e4x/XML/e13_4_4_29/v10` | 19 | 7.8s |  |
| 585 | `e4x/XML/e13_4_4_29/v9` | 19 | 7.8s |  |
| 586 | `e4x/XML/e13_4_4_3/v10` | 16 | 7.6s |  |
| 587 | `e4x/XML/e13_4_4_3/v21` | 16 | 6.7s |  |
| 588 | `e4x/XML/e13_4_4_3/v9` | 16 | 7.5s |  |
| 589 | `e4x/XML/e13_4_4_31` | 19 | 7.2s |  |
| 590 | `e4x/XML/e13_4_4_32/v10` | 9 | 7.1s |  |
| 591 | `e4x/XML/e13_4_4_33` | 6 | 7.0s |  |
| 592 | `e4x/XML/e13_4_4_34` | 12 | 7.3s |  |
| 593 | `e4x/XML/e13_4_4_35` | 17 | 7.5s |  |
| 594 | `e4x/XML/e13_4_4_37` | 12 | 7.1s |  |
| 595 | `e4x/XML/e13_4_4_38` | 17 | 7.2s |  |
| 596 | `e4x/XML/e13_4_4_39` | 20 | 7.2s |  |
| 597 | `e4x/XML/e13_4_4_4` | 19 | 7.2s |  |
| 598 | `e4x/XML/e13_4_4_40` | 7 | 7.0s |  |
| 599 | `e4x/XML/e13_4_4_5` | 12 | 7.1s |  |
| 600 | `e4x/XML/e13_4_4_6` | 31 | 7.3s |  |
| 601 | `e4x/XML/e13_4_4_7` | 7 | 7.0s |  |
| 602 | `e4x/XML/e13_4_4_8` | 7 | 7.1s |  |
| 603 | `e4x/XML/e13_4_4_9` | 14 | 7.1s |  |
| 604 | `e4x/XML/kXMLAssignmentToIndexedXMLNotAllowedErr` | 3 | 7.1s |  |
| 605 | `e4x/XML/kXMLMarkupMustBeWellFormedErr` | 3 | 7.1s |  |
| 606 | `e4x/XML/kXMLPrefixNotBoundErr` | 7 | 7.2s |  |
| 607 | `e4x/XML/kXMLUnterminatedElementTagErr` | 5 | 7.1s |  |
| 608 | `e4x/XMLList/bug157735` | 2 | 7.0s |  |
| 609 | `e4x/XMLList/e13_5_1` | 26 | 7.4s |  |
| 610 | `e4x/XMLList/e13_5_2` | 37 | 7.7s |  |
| 611 | `e4x/XMLList/e13_5_3_1` | 5 | 7.2s |  |
| 612 | `e4x/XMLList/e13_5_4_1` | 3 | 7.2s |  |
| 613 | `e4x/XMLList/e13_5_4_10` | 7 | 7.3s |  |
| 614 | `e4x/XMLList/e13_5_4_11` | 13 | 7.2s |  |
| 615 | `e4x/XMLList/e13_5_4_12` | 19 | 7.6s |  |
| 616 | `e4x/XMLList/e13_5_4_13` | 28 | 7.7s |  |
| 617 | `e4x/XMLList/e13_5_4_14` | 11 | 7.4s |  |
| 618 | `e4x/XMLList/e13_5_4_15` | 3 | 7.3s |  |
| 619 | `e4x/XMLList/e13_5_4_16` | 24 | 7.5s |  |
| 620 | `e4x/XMLList/e13_5_4_19` | 5 | 7.3s |  |
| 621 | `e4x/XMLList/e13_5_4_2` | 28 | 7.9s |  |
| 622 | `e4x/XMLList/e13_5_4_20` | 12 | 7.3s |  |
| 623 | `e4x/XMLList/e13_5_4_21` | 12 | 7.1s |  |
| 624 | `e4x/XMLList/e13_5_4_22` | 5 | 7.1s |  |
| 625 | `e4x/XMLList/e13_5_4_3` | 16 | 7.2s |  |
| 626 | `e4x/XMLList/e13_5_4_4` | 39 | 8.1s |  |
| 627 | `e4x/XMLList/e13_5_4_5` | 11 | 7.3s |  |
| 628 | `e4x/XMLList/e13_5_4_6` | 6 | 7.2s |  |
| 629 | `e4x/XMLList/e13_5_4_7` | 6 | 7.1s |  |
| 630 | `e4x/XMLList/e13_5_4_8` | 11 | 7.2s |  |
| 631 | `e4x/XMLList/e13_5_4_9` | 10 | 7.1s |  |
| 632 | `e4x/XMLList/kXMLOnlyWorksWithOneItemListsErr` | 29 | 7.7s |  |
| 633 | `ecma3/Array/bug_630945` | 6 | 6.9s |  |
| 634 | `ecma3/Array/e15_4_1` | 14 | 7.0s |  |
| 635 | `ecma3/Array/e15_4_1_1` | 7 | 7.0s |  |
| 636 | `ecma3/Array/e15_4_1_2` | 16 | 6.8s |  |
| 637 | `ecma3/Array/e15_4_1_3` | 4 | 6.7s |  |
| 638 | `ecma3/Array/e15_4_2` | 9 | 6.7s |  |
| 639 | `ecma3/Array/e15_4_2_1_1` | 7 | 6.7s |  |
| 640 | `ecma3/Array/e15_4_2_1_2` | 1025 | 6.6s |  |
| 641 | `ecma3/Array/e15_4_2_1_3` | 1031 | 6.7s |  |
| 642 | `ecma3/Array/e15_4_2_2_1` | 17 | 6.8s |  |
| 643 | `ecma3/Array/e15_4_2_2_2` | 8 | 6.6s |  |
| 644 | `ecma3/Array/e15_4_2_3` | 5 | 6.6s |  |
| 645 | `ecma3/Array/e15_4_3` | 1 | 6.6s |  |
| 646 | `ecma3/Array/e15_4_3_1_2` | 4 | 6.8s |  |
| 647 | `ecma3/Array/e15_4_3_2` | 1 | 6.6s |  |
| 648 | `ecma3/Array/e15_4_4` | 4 | 6.7s |  |
| 649 | `ecma3/Array/e15_4_4_1` | 1 | 6.6s |  |
| 650 | `ecma3/Array/e15_4_4_10` | 6 | 6.8s |  |
| 651 | `ecma3/Array/e15_4_4_11` | 16 | 6.6s |  |
| 652 | `ecma3/Array/e15_4_4_12` | 4 | 6.6s |  |
| 653 | `ecma3/Array/e15_4_4_13` | 7 | 6.7s |  |
| 654 | `ecma3/Array/e15_4_4_2` | 13 | 6.7s |  |
| 655 | `ecma3/Array/e15_4_4_3_1` | 1 | 6.6s |  |
| 656 | `ecma3/Array/e15_4_4_4_001` | 9 | 6.7s |  |
| 657 | `ecma3/Array/e15_4_4_4_1` | 1046 | 7.2s |  |
| 658 | `ecma3/Array/e15_4_4_4_2` | 4 | 6.7s |  |
| 659 | `ecma3/Array/e15_4_4_5_1` | 53 | 6.8s |  |
| 660 | `ecma3/Array/e15_4_4_5_2` | 53 | 6.7s |  |
| 661 | `ecma3/Array/e15_4_4_5_3` | 56 | 7.0s |  |
| 662 | `ecma3/Array/e15_4_4_6` | 5 | 6.6s |  |
| 663 | `ecma3/Array/e15_4_4_6_1` | 1 | 6.6s |  |
| 664 | `ecma3/Array/e15_4_4_7` | 6 | 6.7s |  |
| 665 | `ecma3/Array/e15_4_4_8` | 4 | 6.6s |  |
| 666 | `ecma3/Array/e15_4_4_9` | 8 | 6.6s |  |
| 667 | `ecma3/Array/e15_4_4_9_1` | 1 | 2.8s |  |
| 668 | `ecma3/Array/e15_4_5_1_1` | 27 | 7.2s |  |
| 669 | `ecma3/Array/e15_4_5_1_2` | 13 | 6.7s |  |
| 670 | `ecma3/Array/e15_4_5_2_1` | 6 | 6.6s |  |
| 671 | `ecma3/Array/e15_4_5_2_2` | 11 | 6.7s |  |
| 672 | `ecma3/Array/e15_4__1` | 12 | 6.8s |  |
| 673 | `ecma3/Array/eregress_130451` | 7 | 6.7s |  |
| 674 | `ecma3/Array/general1` | 6 | 6.6s |  |
| 675 | `ecma3/Array/general2` | 2 | 6.6s |  |
| 676 | `ecma3/Array/general3` | 4 | 3.3s |  |
| 677 | `ecma3/Array/slice` | 2 | 6.7s |  |
| 678 | `ecma3/Array/sortOn` | 32 | 6.8s |  |
| 679 | `ecma3/Array/sparseArray` | 15 | 6.8s |  |
| 680 | `ecma3/Array/splice1` | 2 | 6.8s |  |
| 681 | `ecma3/Array/splice2` | 2 | 6.8s |  |
| 682 | `ecma3/Boolean/e15_6_1` | 20 | 6.7s |  |
| 683 | `ecma3/Boolean/e15_6_2` | 57 | 7.1s |  |
| 684 | `ecma3/Boolean/e15_6_3` | 2 | 6.6s |  |
| 685 | `ecma3/Boolean/e15_6_3_1` | 2 | 6.6s |  |
| 686 | `ecma3/Boolean/e15_6_3_1_1` | 1 | 6.5s |  |
| 687 | `ecma3/Boolean/e15_6_3_1_2` | 1 | 6.7s |  |
| 688 | `ecma3/Boolean/e15_6_3_1_3` | 1 | 6.7s |  |
| 689 | `ecma3/Boolean/e15_6_3_1_4` | 2 | 6.8s |  |
| 690 | `ecma3/Boolean/e15_6_3_1_5` | 1 | 6.7s |  |
| 691 | `ecma3/Boolean/e15_6_4` | 2 | 6.8s |  |
| 692 | `ecma3/Boolean/e15_6_4_1` | 1 | 6.8s |  |
| 693 | `ecma3/Boolean/e15_6_4_2_1` | 24 | 6.9s |  |
| 694 | `ecma3/Boolean/e15_6_4_2_2` | 3 | 6.7s |  |
| 695 | `ecma3/Boolean/e15_6_4_2_3` | 2 | 6.6s |  |
| 696 | `ecma3/Boolean/e15_6_4_3` | 22 | 6.8s |  |
| 697 | `ecma3/Boolean/e15_6_4_3_1` | 22 | 6.3s |  |
| 698 | `ecma3/Boolean/e15_6_4_3_2` | 3 | 6.6s |  |
| 699 | `ecma3/Boolean/e15_6_4_3_3` | 2 | 6.6s |  |
| 700 | `ecma3/Boolean/e15_6_4__1` | 4 | 6.7s |  |
| 701 | `ecma3/Boolean/ecma4_sealedtype_1_rt` | 1 | 6.7s |  |
| 702 | `ecma3/Boolean/ecma4_sealedtype_2_rt` | 1 | 6.7s |  |
| 703 | `ecma3/Boolean/ecma4_sealedtype_3_rt` | 1 | 6.7s |  |
| 704 | `ecma3/Boolean/ecma4_sealedtype_4_rt` | 1 | 6.7s |  |
| 705 | `ecma3/Boolean/ecma4_sealedtype_5_rt` | 1 | 6.7s |  |
| 706 | `ecma3/Boolean/ecma4_st_valueOf_1_rt` | 2 | 6.7s |  |
| 707 | `ecma3/Boolean/ecma4_st_valueOf_2_rt` | 2 | 6.7s |  |
| 708 | `ecma3/Boolean/ecma4_st_valueOf_3_rt` | 1 | 6.7s |  |
| 709 | `ecma3/Boolean/ecma4_st_valueOf_4_rt` | 1 | 6.7s |  |
| 710 | `ecma3/Boolean/ecma4_st_valueOf_5_rt` | 1 | 6.6s |  |
| 711 | `ecma3/Date/e15_9_1_1_1` | 686 | 7.7s |  |
| 712 | `ecma3/Date/e15_9_1_1_2` | 685 | 7.8s |  |
| 713 | `ecma3/Date/e15_9_2_1` | 24 | 8.0s |  |
| 714 | `ecma3/Date/e15_9_2_2_1` | 24 | 8.0s |  |
| 715 | `ecma3/Date/e15_9_2_2_2` | 20 | 8.0s |  |
| 716 | `ecma3/Date/e15_9_2_2_3` | 15 | 7.9s |  |
| 717 | `ecma3/Date/e15_9_2_2_4` | 3 | 7.8s |  |
| 718 | `ecma3/Date/e15_9_2_2_5` | 4 | 7.8s |  |
| 719 | `ecma3/Date/e15_9_2_2_6` | 4 | 7.7s |  |
| 720 | `ecma3/Date/e15_9_3_1_1` | 648 | 8.4s |  |
| 721 | `ecma3/Date/e15_9_3_1_2` | 90 | 8.0s |  |
| 722 | `ecma3/Date/e15_9_3_1_3` | 54 | 8.0s |  |
| 723 | `ecma3/Date/e15_9_3_1_4` | 90 | 8.0s |  |
| 724 | `ecma3/Date/e15_9_3_1_5` | 36 | 8.0s |  |
| 725 | `ecma3/Date/e15_9_3_2_1` | 90 | 8.1s |  |
| 726 | `ecma3/Date/e15_9_3_2_2` | 54 | 8.1s |  |
| 727 | `ecma3/Date/e15_9_3_2_3` | 72 | 8.0s |  |
| 728 | `ecma3/Date/e15_9_3_2_4` | 54 | 8.1s |  |
| 729 | `ecma3/Date/e15_9_3_2_5` | 36 | 8.1s |  |
| 730 | `ecma3/Date/e15_9_3_8_1` | 90 | 8.1s |  |
| 731 | `ecma3/Date/e15_9_3_8_2` | 90 | 8.1s |  |
| 732 | `ecma3/Date/e15_9_3_8_3` | 108 | 8.1s |  |
| 733 | `ecma3/Date/e15_9_3_8_4` | 72 | 8.1s |  |
| 734 | `ecma3/Date/e15_9_3_8_5` | 108 | 8.2s |  |
| 735 | `ecma3/Date/e15_9_4_2` | 391 | 8.4s |  |
| 736 | `ecma3/Date/e15_9_4_3` | 40 | 8.3s |  |
| 737 | `ecma3/Date/e15_9_5` | 1 | 7.9s |  |
| 738 | `ecma3/Date/e15_9_5_1` | 1 | 7.9s |  |
| 739 | `ecma3/Date/e15_9_5_10_12` | 64 | 7.9s |  |
| 740 | `ecma3/Date/e15_9_5_10_13` | 33 | 8.0s |  |
| 741 | `ecma3/Date/e15_9_5_10_3` | 31 | 4.4s |  |
| 742 | `ecma3/Date/e15_9_5_10_4` | 31 | 2.6s |  |
| 743 | `ecma3/Date/e15_9_5_10_5` | 31 | 2.7s |  |
| 744 | `ecma3/Date/e15_9_5_10_6` | 32 | 7.9s |  |
| 745 | `ecma3/Date/e15_9_5_10_7` | 31 | 4.4s |  |
| 746 | `ecma3/Date/e15_9_5_10_8` | 33 | 7.9s |  |
| 747 | `ecma3/Date/e15_9_5_10_9` | 33 | 7.8s |  |
| 748 | `ecma3/Date/e15_9_5_11_1` | 55 | 7.8s |  |
| 749 | `ecma3/Date/e15_9_5_11_3` | 55 | 7.8s |  |
| 750 | `ecma3/Date/e15_9_5_11_4` | 55 | 7.7s |  |
| 751 | `ecma3/Date/e15_9_5_11_5` | 55 | 2.6s |  |
| 752 | `ecma3/Date/e15_9_5_11_6` | 55 | 7.9s |  |
| 753 | `ecma3/Date/e15_9_5_11_7` | 55 | 7.9s |  |
| 754 | `ecma3/Date/e15_9_5_12_3` | 67 | 7.8s |  |
| 755 | `ecma3/Date/e15_9_5_12_4` | 67 | 7.7s |  |
| 756 | `ecma3/Date/e15_9_5_12_5` | 67 | 7.9s |  |
| 757 | `ecma3/Date/e15_9_5_12_6` | 55 | 7.9s |  |
| 758 | `ecma3/Date/e15_9_5_12_7` | 67 | 4.5s |  |
| 759 | `ecma3/Date/e15_9_5_12_8` | 2 | 7.8s |  |
| 760 | `ecma3/Date/e15_9_5_13_1` | 36 | 8.3s |  |
| 761 | `ecma3/Date/e15_9_5_13_2` | 36 | 8.1s |  |
| 762 | `ecma3/Date/e15_9_5_13_3` | 36 | 7.9s |  |
| 763 | `ecma3/Date/e15_9_5_13_4` | 36 | 7.8s |  |
| 764 | `ecma3/Date/e15_9_5_13_5` | 36 | 2.6s |  |
| 765 | `ecma3/Date/e15_9_5_13_6` | 60 | 7.9s |  |
| 766 | `ecma3/Date/e15_9_5_13_7` | 60 | 7.9s |  |
| 767 | `ecma3/Date/e15_9_5_13_8` | 2 | 8.0s |  |
| 768 | `ecma3/Date/e15_9_5_14` | 44 | 8.0s |  |
| 769 | `ecma3/Date/e15_9_5_15` | 58 | 8.0s |  |
| 770 | `ecma3/Date/e15_9_5_16` | 51 | 8.1s |  |
| 771 | `ecma3/Date/e15_9_5_17` | 51 | 8.0s |  |
| 772 | `ecma3/Date/e15_9_5_18` | 51 | 8.2s |  |
| 773 | `ecma3/Date/e15_9_5_19` | 51 | 4.6s |  |
| 774 | `ecma3/Date/e15_9_5_2` | 15 | 8.3s |  |
| 775 | `ecma3/Date/e15_9_5_20` | 79 | 8.2s |  |
| 776 | `ecma3/Date/e15_9_5_21_1` | 9 | 8.0s |  |
| 777 | `ecma3/Date/e15_9_5_21_2` | 1 | 8.0s |  |
| 778 | `ecma3/Date/e15_9_5_21_3` | 1 | 8.1s |  |
| 779 | `ecma3/Date/e15_9_5_21_4` | 1 | 2.7s |  |
| 780 | `ecma3/Date/e15_9_5_21_5` | 1 | 8.5s |  |
| 781 | `ecma3/Date/e15_9_5_21_6` | 1 | 8.4s |  |
| 782 | `ecma3/Date/e15_9_5_21_7` | 1 | 2.8s |  |
| 783 | `ecma3/Date/e15_9_5_21_8` | 2 | 8.4s |  |
| 784 | `ecma3/Date/e15_9_5_22_2` | 11 | 8.6s |  |
| 785 | `ecma3/Date/e15_9_5_22_3` | 11 | 4.9s |  |
| 786 | `ecma3/Date/e15_9_5_22_4` | 11 | 8.3s |  |
| 787 | `ecma3/Date/e15_9_5_22_5` | 11 | 2.7s |  |
| 788 | `ecma3/Date/e15_9_5_22_6` | 11 | 2.7s |  |
| 789 | `ecma3/Date/e15_9_5_22_7` | 11 | 2.7s |  |
| 790 | `ecma3/Date/e15_9_5_22_8` | 2 | 8.3s |  |
| 791 | `ecma3/Date/e15_9_5_23_1` | 18 | 8.5s |  |
| 792 | `ecma3/Date/e15_9_5_23_10` | 18 | 8.4s |  |
| 793 | `ecma3/Date/e15_9_5_23_11` | 18 | 8.4s |  |
| 794 | `ecma3/Date/e15_9_5_23_12` | 18 | 8.4s |  |
| 795 | `ecma3/Date/e15_9_5_23_13` | 18 | 8.4s |  |
| 796 | `ecma3/Date/e15_9_5_23_14` | 18 | 8.3s |  |
| 797 | `ecma3/Date/e15_9_5_23_15` | 18 | 2.9s |  |
| 798 | `ecma3/Date/e15_9_5_23_16` | 18 | 8.4s |  |
| 799 | `ecma3/Date/e15_9_5_23_17` | 18 | 8.4s |  |
| 800 | `ecma3/Date/e15_9_5_23_18` | 18 | 8.3s |  |
| 801 | `ecma3/Date/e15_9_5_23_2` | 26 | 8.4s |  |
| 802 | `ecma3/Date/e15_9_5_23_3_rt` | 1 | 8.2s |  |
| 803 | `ecma3/Date/e15_9_5_23_4` | 44 | 8.4s |  |
| 804 | `ecma3/Date/e15_9_5_23_5` | 44 | 4.8s |  |
| 805 | `ecma3/Date/e15_9_5_23_6` | 44 | 2.8s |  |
| 806 | `ecma3/Date/e15_9_5_23_7` | 44 | 8.2s |  |
| 807 | `ecma3/Date/e15_9_5_23_8` | 42 | 8.4s |  |
| 808 | `ecma3/Date/e15_9_5_23_9` | 42 | 8.2s |  |
| 809 | `ecma3/Date/e15_9_5_24_1` | 16 | 8.3s |  |
| 810 | `ecma3/Date/e15_9_5_24_2` | 16 | 8.4s |  |
| 811 | `ecma3/Date/e15_9_5_24_3` | 16 | 4.8s |  |
| 812 | `ecma3/Date/e15_9_5_24_4` | 16 | 8.4s |  |
| 813 | `ecma3/Date/e15_9_5_24_5` | 16 | 4.8s |  |
| 814 | `ecma3/Date/e15_9_5_24_6` | 16 | 6.7s |  |
| 815 | `ecma3/Date/e15_9_5_24_7` | 16 | 6.7s |  |
| 816 | `ecma3/Date/e15_9_5_24_8` | 16 | 8.2s |  |
| 817 | `ecma3/Date/e15_9_5_25_1` | 153 | 8.3s |  |
| 818 | `ecma3/Date/e15_9_5_26_1` | 119 | 8.3s |  |
| 819 | `ecma3/Date/e15_9_5_27_1` | 119 | 8.3s |  |
| 820 | `ecma3/Date/e15_9_5_2_1` | 15 | 8.2s |  |
| 821 | `ecma3/Date/e15_9_5_2_2_rt` | 1 | 8.0s |  |
| 822 | `ecma3/Date/e15_9_5_3` | 15 | 8.1s |  |
| 823 | `ecma3/Date/e15_9_5_30_1` | 144 | 8.3s |  |
| 824 | `ecma3/Date/e15_9_5_31_1` | 126 | 8.4s |  |
| 825 | `ecma3/Date/e15_9_5_32_1` | 180 | 8.3s |  |
| 826 | `ecma3/Date/e15_9_5_33_1` | 54 | 8.4s |  |
| 827 | `ecma3/Date/e15_9_5_34_1` | 164 | 10.6s |  |
| 828 | `ecma3/Date/e15_9_5_36_1` | 54 | 8.4s |  |
| 829 | `ecma3/Date/e15_9_5_36_2` | 54 | 8.2s |  |
| 830 | `ecma3/Date/e15_9_5_36_3` | 54 | 8.2s |  |
| 831 | `ecma3/Date/e15_9_5_36_4` | 54 | 3.0s |  |
| 832 | `ecma3/Date/e15_9_5_36_5` | 162 | 8.4s |  |
| 833 | `ecma3/Date/e15_9_5_36_6` | 108 | 8.4s |  |
| 834 | `ecma3/Date/e15_9_5_36_7` | 54 | 8.2s |  |
| 835 | `ecma3/Date/e15_9_5_37_1` | 360 | 8.7s |  |
| 836 | `ecma3/Date/e15_9_5_37_2` | 54 | 8.3s |  |
| 837 | `ecma3/Date/e15_9_5_37_3` | 36 | 8.4s |  |
| 838 | `ecma3/Date/e15_9_5_37_4` | 54 | 4.8s |  |
| 839 | `ecma3/Date/e15_9_5_37_5` | 54 | 8.2s |  |
| 840 | `ecma3/Date/e15_9_5_3_1_rt` | 1 | 8.1s |  |
| 841 | `ecma3/Date/e15_9_5_3_2` | 30 | 8.2s |  |
| 842 | `ecma3/Date/e15_9_5_42` | 15 | 8.3s |  |
| 843 | `ecma3/Date/e15_9_5_4_1` | 30 | 8.3s |  |
| 844 | `ecma3/Date/e15_9_5_4_2_rt` | 1 | 8.2s |  |
| 845 | `ecma3/Date/e15_9_5_5` | 15 | 8.2s |  |
| 846 | `ecma3/Date/e15_9_5_6` | 15 | 8.2s |  |
| 847 | `ecma3/Date/e15_9_5_7` | 16 | 8.4s |  |
| 848 | `ecma3/ErrorObject/e15_11_1` | 42 | 7.4s |  |
| 849 | `ecma3/ErrorObject/e15_11_2_1` | 30 | 7.2s |  |
| 850 | `ecma3/Exceptions/binding_001` | 2 | 3.6s |  |
| 851 | `ecma3/Exceptions/boolean_001_rt` | 6 | 7.3s |  |
| 852 | `ecma3/Exceptions/boolean_002_rt` | 6 | 7.3s |  |
| 853 | `ecma3/Exceptions/bug127913` | 1 | 7.0s |  |
| 854 | `ecma3/Exceptions/date_001_rt` | 1 | 6.9s |  |
| 855 | `ecma3/Exceptions/date_002_rt` | 1 | 6.9s |  |
| 856 | `ecma3/Exceptions/date_003_rt` | 1 | 6.9s |  |
| 857 | `ecma3/Exceptions/date_004_rt` | 1 | 7.0s |  |
| 858 | `ecma3/Exceptions/e15_11_4_4_1` | 9 | 7.3s |  |
| 859 | `ecma3/Exceptions/exception_003_rt` | 1 | 7.0s |  |
| 860 | `ecma3/Exceptions/exception_004_rt` | 1 | 7.0s |  |
| 861 | `ecma3/Exceptions/exception_005_rt` | 1 | 6.6s |  |
| 862 | `ecma3/Exceptions/exception_006_rt` | 1 | 7.0s |  |
| 863 | `ecma3/Exceptions/exception_007_rt` | 1 | 7.0s |  |
| 864 | `ecma3/Exceptions/exception_009` | 1 | 7.2s |  |
| 865 | `ecma3/Exceptions/exception_010_rt` | 1 | 7.1s |  |
| 866 | `ecma3/Exceptions/exception_014_rt` | 2 | 7.1s |  |
| 867 | `ecma3/Exceptions/expression_002_rt` | 1 | 7.0s |  |
| 868 | `ecma3/Exceptions/expression_003_rt` | 1 | 7.1s |  |
| 869 | `ecma3/Exceptions/expression_004_rt` | 1 | 7.0s |  |
| 870 | `ecma3/Exceptions/expression_006_rt` | 1 | 7.0s |  |
| 871 | `ecma3/Exceptions/expression_007_rt` | 1 | 7.0s |  |
| 872 | `ecma3/Exceptions/expression_008_rt` | 1 | 3.5s |  |
| 873 | `ecma3/Exceptions/expression_009_rt` | 1 | 7.0s |  |
| 874 | `ecma3/Exceptions/expression_010_rt` | 1 | 7.0s |  |
| 875 | `ecma3/Exceptions/expression_011_rt` | 1 | 6.9s |  |
| 876 | `ecma3/Exceptions/expression_012_rt` | 1 | 6.9s |  |
| 877 | `ecma3/Exceptions/expression_013_rt` | 1 | 7.0s |  |
| 878 | `ecma3/Exceptions/expression_014_rt` | 1 | 6.9s |  |
| 879 | `ecma3/Exceptions/expression_016_rt` | 1 | 6.9s |  |
| 880 | `ecma3/Exceptions/expression_017_rt` | 1 | 6.9s |  |
| 881 | `ecma3/Exceptions/expression_019_rt` | 1 | 6.9s |  |
| 882 | `ecma3/Exceptions/global_001_rt` | 1 | 6.9s |  |
| 883 | `ecma3/Exceptions/global_002_rt` | 1 | 6.9s |  |
| 884 | `ecma3/Exceptions/number_001_rt` | 1 | 7.0s |  |
| 885 | `ecma3/Exceptions/number_002_rt` | 1 | 3.5s |  |
| 886 | `ecma3/Exceptions/number_003_rt` | 4 | 7.2s |  |
| 887 | `ecma3/Exceptions/number_004_rt` | 4 | 7.2s |  |
| 888 | `ecma3/Exceptions/regress_58946` | 1 | 6.9s |  |
| 889 | `ecma3/Exceptions/regress_95101` | 2 | 7.0s |  |
| 890 | `ecma3/Exceptions/string_001_rt` | 1 | 7.0s |  |
| 891 | `ecma3/Exceptions/string_002_rt` | 1 | 6.9s |  |
| 892 | `ecma3/ExecutionContexts/e10_1_3` | 1 | 6.9s |  |
| 893 | `ecma3/ExecutionContexts/e10_1_3_1` | 8 | 7.0s |  |
| 894 | `ecma3/ExecutionContexts/e10_1_4_1` | 1 | 6.9s |  |
| 895 | `ecma3/ExecutionContexts/e10_1_4_10` | 1 | 6.9s |  |
| 896 | `ecma3/ExecutionContexts/e10_1_4_2` | 1 | 3.4s |  |
| 897 | `ecma3/ExecutionContexts/e10_1_4_8` | 1 | 6.9s |  |
| 898 | `ecma3/ExecutionContexts/e10_1_4_9` | 1 | 6.9s |  |
| 899 | `ecma3/ExecutionContexts/e10_1_5_1` | 1 | 7.0s |  |
| 900 | `ecma3/ExecutionContexts/e10_1_5_2` | 1 | 6.9s |  |
| 901 | `ecma3/ExecutionContexts/e10_1_5_3` | 1 | 6.9s |  |
| 902 | `ecma3/ExecutionContexts/e10_1_5_4` | 1 | 6.9s |  |
| 903 | `ecma3/ExecutionContexts/e10_1_6` | 9 | 6.9s |  |
| 904 | `ecma3/ExecutionContexts/e10_1_8_1` | 7 | 6.9s |  |
| 905 | `ecma3/ExecutionContexts/e10_1_8_2` | 8 | 6.9s |  |
| 906 | `ecma3/ExecutionContexts/e10_2_1` | 1 | 6.9s |  |
| 907 | `ecma3/ExecutionContexts/e10_2_3_1` | 2 | 6.9s |  |
| 908 | `ecma3/ExecutionContexts/e10_2_3_2` | 2 | 6.9s |  |
| 909 | `ecma3/Expressions/StrictEquality_001` | 7 | 6.9s |  |
| 910 | `ecma3/Expressions/e11_10_1` | 31 | 7.3s |  |
| 911 | `ecma3/Expressions/e11_10_2` | 1089 | 7.3s |  |
| 912 | `ecma3/Expressions/e11_10_3` | 1089 | 7.4s |  |
| 913 | `ecma3/Expressions/e11_11` | 62 | 7.5s |  |
| 914 | `ecma3/Expressions/e11_12_1` | 7 | 6.9s |  |
| 915 | `ecma3/Expressions/e11_12_3` | 1 | 6.8s |  |
| 916 | `ecma3/Expressions/e11_12_4` | 1 | 6.9s |  |
| 917 | `ecma3/Expressions/e11_13` | 7 | 6.4s |  |
| 918 | `ecma3/Expressions/e11_13_1` | 1 | 6.8s |  |
| 919 | `ecma3/Expressions/e11_13_2_1` | 30 | 7.4s |  |
| 920 | `ecma3/Expressions/e11_13_2_2` | 31 | 7.5s |  |
| 921 | `ecma3/Expressions/e11_13_2_3` | 40 | 7.7s |  |
| 922 | `ecma3/Expressions/e11_13_2_4` | 26 | 3.8s |  |
| 923 | `ecma3/Expressions/e11_13_2_5` | 26 | 7.4s |  |
| 924 | `ecma3/Expressions/e11_14_1` | 3 | 6.9s |  |
| 925 | `ecma3/Expressions/e11_1_1` | 7 | 6.9s |  |
| 926 | `ecma3/Expressions/e11_1_4` | 28 | 7.2s |  |
| 927 | `ecma3/Expressions/e11_1_5` | 20 | 7.0s |  |
| 928 | `ecma3/Expressions/e11_1_6` | 25 | 7.0s |  |
| 929 | `ecma3/Expressions/e11_2_1_1` | 254 | 11.1s |  |
| 930 | `ecma3/Expressions/e11_2_1_2` | 8 | 6.8s |  |
| 931 | `ecma3/Expressions/e11_2_1_3` | 2 | 6.6s |  |
| 932 | `ecma3/Expressions/e11_2_1_4_rt` | 2 | 6.7s |  |
| 933 | `ecma3/Expressions/e11_2_1_5` | 10 | 6.8s |  |
| 934 | `ecma3/Expressions/e11_2_2_11` | 1 | 6.7s |  |
| 935 | `ecma3/Expressions/e11_2_2_12_rt` | 1 | 6.8s |  |
| 936 | `ecma3/Expressions/e11_2_2_1_rt` | 1 | 6.8s |  |
| 937 | `ecma3/Expressions/e11_2_2_2_rt` | 1 | 6.8s |  |
| 938 | `ecma3/Expressions/e11_2_2_3_rt` | 1 | 6.8s |  |
| 939 | `ecma3/Expressions/e11_2_2_4_rt` | 1 | 3.3s |  |
| 940 | `ecma3/Expressions/e11_2_2_5_rt` | 1 | 3.2s |  |
| 941 | `ecma3/Expressions/e11_2_2_6_rt` | 1 | 3.3s |  |
| 942 | `ecma3/Expressions/e11_2_2_7_rt` | 1 | 6.8s |  |
| 943 | `ecma3/Expressions/e11_2_2_8_rt` | 1 | 6.8s |  |
| 944 | `ecma3/Expressions/e11_2_2_9_rt` | 1 | 6.7s |  |
| 945 | `ecma3/Expressions/e11_2_3_1` | 4 | 6.7s |  |
| 946 | `ecma3/Expressions/e11_2_3_3_rt` | 1 | 6.8s |  |
| 947 | `ecma3/Expressions/e11_2_3_4_rt` | 1 | 6.8s |  |
| 948 | `ecma3/Expressions/e11_2_3_5` | 1 | 6.8s |  |
| 949 | `ecma3/Expressions/e11_3_1` | 58 | 7.3s |  |
| 950 | `ecma3/Expressions/e11_3_2` | 58 | 7.3s |  |
| 951 | `ecma3/Expressions/e11_4_1` | 18 | 6.8s |  |
| 952 | `ecma3/Expressions/e11_4_2` | 24 | 6.9s |  |
| 953 | `ecma3/Expressions/e11_4_4` | 52 | 7.1s |  |
| 954 | `ecma3/Expressions/e11_4_5` | 52 | 7.0s |  |
| 955 | `ecma3/Expressions/e11_4_6` | 190 | 9.0s |  |
| 956 | `ecma3/Expressions/e11_4_7` | 146 | 8.3s |  |
| 957 | `ecma3/Expressions/e11_4_8` | 70 | 7.0s |  |
| 958 | `ecma3/Expressions/e11_4_9` | 27 | 6.9s |  |
| 959 | `ecma3/Expressions/e11_5_1` | 47 | 7.2s |  |
| 960 | `ecma3/Expressions/e11_5_2` | 58 | 7.3s |  |
| 961 | `ecma3/Expressions/e11_5_3` | 70 | 7.4s |  |
| 962 | `ecma3/Expressions/e11_6_1_1` | 12 | 6.8s |  |
| 963 | `ecma3/Expressions/e11_6_1_2` | 13 | 6.8s |  |
| 964 | `ecma3/Expressions/e11_6_2_1` | 18 | 6.9s |  |
| 965 | `ecma3/Expressions/e11_6_3` | 34 | 6.9s |  |
| 966 | `ecma3/Expressions/e11_7_1` | 1089 | 7.1s |  |
| 967 | `ecma3/Expressions/e11_7_2` | 2178 | 7.2s |  |
| 968 | `ecma3/Expressions/e11_7_3` | 1089 | 7.0s |  |
| 969 | `ecma3/Expressions/e11_8_1` | 53 | 7.2s |  |
| 970 | `ecma3/Expressions/e11_8_2` | 52 | 7.2s |  |
| 971 | `ecma3/Expressions/e11_8_3` | 56 | 7.3s |  |
| 972 | `ecma3/Expressions/e11_8_4` | 56 | 7.2s |  |
| 973 | `ecma3/Expressions/e11_8_7` | 29 | 7.0s |  |
| 974 | `ecma3/Expressions/e11_9_1` | 47 | 7.1s |  |
| 975 | `ecma3/Expressions/e11_9_2` | 47 | 7.2s |  |
| 976 | `ecma3/Expressions/e11_9_3` | 47 | 7.1s |  |
| 977 | `ecma3/Expressions/e11_9_6_1` | 6 | 6.5s |  |
| 978 | `ecma3/Expressions/instanceof_001` | 14 | 6.6s |  |
| 979 | `ecma3/Expressions/instanceof_002` | 6 | 6.5s |  |
| 980 | `ecma3/Expressions/instanceof_003_rt` | 30 | 6.6s |  |
| 981 | `ecma3/Expressions/instanceof_004_rt` | 1 | 6.5s |  |
| 982 | `ecma3/Expressions/instanceof_006` | 1 | 6.6s |  |
| 983 | `ecma3/Function/apply_001` | 4 | 6.5s |  |
| 984 | `ecma3/Function/call_001_rt` | 1 | 6.5s |  |
| 985 | `ecma3/Function/e15_3_FPQA` | 2 | 6.5s |  |
| 986 | `ecma3/Function/function` | 2 | 6.5s |  |
| 987 | `ecma3/Function/regress_104584` | 3 | 2.9s |  |
| 988 | `ecma3/Function/regress_137181` | 2 | 6.4s |  |
| 989 | `ecma3/Function/regress_49286` | 2 | 6.4s |  |
| 990 | `ecma3/Function/regress_58274_rt` | 7 | 6.5s |  |
| 991 | `ecma3/Function/regress_97921` | 4 | 6.6s |  |
| 992 | `ecma3/Function/scope_001_rt` | 8 | 6.6s |  |
| 993 | `ecma3/Function/scope_002` | 8 | 6.7s |  |
| 994 | `ecma3/FunctionObjects/e15_3_1_1_1_rt` | 6 | 6.7s |  |
| 995 | `ecma3/FunctionObjects/e15_3_1_1_2_rt` | 1 | 6.5s |  |
| 996 | `ecma3/FunctionObjects/e15_3_1_1_3_rt` | 1 | 6.5s |  |
| 997 | `ecma3/FunctionObjects/e15_3_2_1_1_rt` | 13 | 6.8s |  |
| 998 | `ecma3/FunctionObjects/e15_3_2_1_2_rt` | 1 | 6.5s |  |
| 999 | `ecma3/FunctionObjects/e15_3_2_1_3_rt` | 1 | 6.6s |  |
| 1000 | `ecma3/FunctionObjects/e15_3_3_1_1` | 1 | 6.4s |  |
| 1001 | `ecma3/FunctionObjects/e15_3_3_1_2` | 1 | 6.4s |  |
| 1002 | `ecma3/FunctionObjects/e15_3_3_1_3` | 2 | 6.4s |  |
| 1003 | `ecma3/FunctionObjects/e15_3_3_1_4` | 1 | 6.5s |  |
| 1004 | `ecma3/FunctionObjects/e15_3_3_2` | 1 | 6.5s |  |
| 1005 | `ecma3/FunctionObjects/e15_3_4_1` | 1 | 6.4s |  |
| 1006 | `ecma3/FunctionObjects/e15_3_4_2` | 4 | 6.5s |  |
| 1007 | `ecma3/FunctionObjects/e15_3_4__1_rt` | 4 | 6.5s |  |
| 1008 | `ecma3/FunctionObjects/e15_3_4_rt` | 4 | 6.6s |  |
| 1009 | `ecma3/FunctionObjects/e15_3_5_1_rt` | 3 | 6.5s |  |
| 1010 | `ecma3/FunctionObjects/e15_3_5_2_rt` | 4 | 6.6s |  |
| 1011 | `ecma3/FunctionObjects/e15_3_5_3_rt` | 1 | 6.6s |  |
| 1012 | `ecma3/FunctionObjects/e15_3_5__1_rt` | 3 | 6.7s |  |
| 1013 | `ecma3/FunctionObjects/eapply_001_rt` | 4 | 6.5s |  |
| 1014 | `ecma3/FunctionObjects/ecall_1` | 3 | 6.6s |  |
| 1015 | `ecma3/GlobalObject/decodeURI` | 38 | 7.5s |  |
| 1016 | `ecma3/GlobalObject/decodeURIComponent` | 24 | 7.2s |  |
| 1017 | `ecma3/GlobalObject/e15_1_1_1` | 3 | 6.5s |  |
| 1018 | `ecma3/GlobalObject/e15_1_1_2` | 3 | 6.5s |  |
| 1019 | `ecma3/GlobalObject/e15_1_1_n` | 1 | 6.5s |  |
| 1020 | `ecma3/GlobalObject/e15_1_2_1_2_rt` | 1 | 6.5s |  |
| 1021 | `ecma3/GlobalObject/e15_1_2_2_1` | 276 | 9.2s |  |
| 1022 | `ecma3/GlobalObject/e15_1_2_3_1` | 186 | 13.2s |  |
| 1023 | `ecma3/GlobalObject/e15_1_2_3_2` | 153 | 8.0s |  |
| 1024 | `ecma3/GlobalObject/e15_1_2_4` | 983 | 7.2s |  |
| 1025 | `ecma3/GlobalObject/e15_1_2_5_1` | 531 | 7.2s |  |
| 1026 | `ecma3/GlobalObject/e15_1_2_5_2` | 85 | 6.8s |  |
| 1027 | `ecma3/GlobalObject/e15_1_2_5_3` | 514 | 6.9s |  |
| 1028 | `ecma3/GlobalObject/e15_1_2_6` | 62 | 8.4s |  |
| 1029 | `ecma3/GlobalObject/e15_1_2_7` | 55 | 8.2s |  |
| 1030 | `ecma3/GlobalObject/e15_1_2_n` | 1 | 6.7s |  |
| 1031 | `ecma3/GlobalObject/e15_1_3` | 2 | 6.7s |  |
| 1032 | `ecma3/GlobalObject/encodeURI` | 39 | 6.9s |  |
| 1033 | `ecma3/GlobalObject/encodeURIComponent` | 23 | 6.8s |  |
| 1034 | `ecma3/GlobalObject/undefined` | 3 | 6.6s |  |
| 1035 | `ecma3/JSON/AS3Types` | 26 | 7.4s |  |
| 1036 | `ecma3/JSON/Callbacks` | 7 | 6.8s |  |
| 1037 | `ecma3/JSON/Invalid` | 40 | 8.0s |  |
| 1038 | `ecma3/JSON/LargeString` | 1 | 6.7s |  |
| 1039 | `ecma3/JSON/Strings` | 21 | 6.7s |  |
| 1040 | `ecma3/JSON/e15_12_0` | 4 | 6.8s |  |
| 1041 | `ecma3/JSON/e15_12_1` | 36 | 7.7s |  |
| 1042 | `ecma3/JSON/e15_12_2` | 12 | 7.7s |  |
| 1043 | `ecma3/JSON/e15_12_3` | 33 | 7.5s |  |
| 1044 | `ecma3/JSON/regress` | 5 | 6.9s |  |
| 1045 | `ecma3/NativeObjects/e15_2_rt` | 9 | 6.7s |  |
| 1046 | `ecma3/Number/e15_7_3` | 2 | 6.7s |  |
| 1047 | `ecma3/Number/e15_7_3_1_1` | 2 | 6.7s |  |
| 1048 | `ecma3/Number/e15_7_3_1_2` | 4 | 6.8s |  |
| 1049 | `ecma3/Number/e15_7_3_1_3` | 1 | 6.6s |  |
| 1050 | `ecma3/Number/e15_7_3_2_1` | 1 | 6.6s |  |
| 1051 | `ecma3/Number/e15_7_3_2_2` | 2 | 6.7s |  |
| 1052 | `ecma3/Number/e15_7_3_2_3` | 2 | 6.7s |  |
| 1053 | `ecma3/Number/e15_7_3_2_4` | 1 | 6.3s |  |
| 1054 | `ecma3/Number/e15_7_3_3_1` | 1 | 3.2s |  |
| 1055 | `ecma3/Number/e15_7_3_3_2` | 2 | 3.2s |  |
| 1056 | `ecma3/Number/e15_7_3_3_3` | 2 | 6.8s |  |
| 1057 | `ecma3/Number/e15_7_3_3_4` | 1 | 2.7s |  |
| 1058 | `ecma3/Number/e15_7_3_4_1` | 1 | 6.7s |  |
| 1059 | `ecma3/Number/e15_7_3_4_2` | 2 | 6.5s |  |
| 1060 | `ecma3/Number/e15_7_3_4_3` | 2 | 6.7s |  |
| 1061 | `ecma3/Number/e15_7_3_4_4` | 1 | 6.3s |  |
| 1062 | `ecma3/Number/e15_7_3_5_1` | 1 | 6.6s |  |
| 1063 | `ecma3/Number/e15_7_3_5_2` | 2 | 3.2s |  |
| 1064 | `ecma3/Number/e15_7_3_5_3_rt` | 2 | 6.7s |  |
| 1065 | `ecma3/Number/e15_7_3_5_4` | 1 | 6.3s |  |
| 1066 | `ecma3/Number/e15_7_3_6_1` | 1 | 2.1s |  |
| 1067 | `ecma3/Number/e15_7_3_6_2` | 2 | 6.6s |  |
| 1068 | `ecma3/Number/e15_7_3_6_3_rt` | 2 | 6.7s |  |
| 1069 | `ecma3/Number/e15_7_3_6_4` | 1 | 1.1s |  |
| 1070 | `ecma3/Number/e15_7_4_1` | 1 | 6.5s |  |
| 1071 | `ecma3/Number/e15_7_4_2_1_rt` | 9 | 7.1s |  |
| 1072 | `ecma3/Number/e15_7_4_2_2_rt` | 2 | 6.7s |  |
| 1073 | `ecma3/Number/e15_7_4_2_3_rt` | 1 | 6.7s |  |
| 1074 | `ecma3/Number/e15_7_4_2_5` | 13 | 7.0s |  |
| 1075 | `ecma3/Number/e15_7_4_3_1_rt` | 7 | 7.0s |  |
| 1076 | `ecma3/Number/e15_7_4_3_2` | 3 | 6.9s |  |
| 1077 | `ecma3/Number/e15_7_4_3_3_rt` | 1 | 7.0s |  |
| 1078 | `ecma3/Number/e15_7_4_6_1` | 26 | 8.3s |  |
| 1079 | `ecma3/Number/e15_7_4__1_rt` | 3 | 6.9s |  |
| 1080 | `ecma3/Number/e15_7_4_rt` | 3 | 6.9s |  |
| 1081 | `ecma3/Number/ecma4_sealedtype_1_rt` | 1 | 6.9s |  |
| 1082 | `ecma3/Number/ecma4_sealedtype_2_rt` | 1 | 6.9s |  |
| 1083 | `ecma3/Number/ecma4_sealedtype_3_rt` | 1 | 6.9s |  |
| 1084 | `ecma3/Number/ecma4_sealedtype_4_rt` | 2 | 7.0s |  |
| 1085 | `ecma3/Number/ecma4_st_valueOf_1_rt` | 1 | 6.9s |  |
| 1086 | `ecma3/Number/ecma4_st_valueOf_2_rt` | 1 | 6.9s |  |
| 1087 | `ecma3/Number/ecma4_st_valueOf_3_rt` | 1 | 6.9s |  |
| 1088 | `ecma3/Number/toLocaleString2_rt` | 1 | 6.9s |  |
| 1089 | `ecma3/Number/toLocaleString3_rt` | 1 | 6.9s |  |
| 1090 | `ecma3/Number/toLocaleString4_rt` | 1 | 7.0s |  |
| 1091 | `ecma3/ObjectObjects/bug129539` | 3 | 6.9s |  |
| 1092 | `ecma3/ObjectObjects/class_001` | 10 | 7.0s |  |
| 1093 | `ecma3/ObjectObjects/class_002` | 9 | 7.0s |  |
| 1094 | `ecma3/ObjectObjects/class_003` | 7 | 7.0s |  |
| 1095 | `ecma3/ObjectObjects/class_004` | 7 | 7.0s |  |
| 1096 | `ecma3/ObjectObjects/class_005` | 2 | 7.0s |  |
| 1097 | `ecma3/ObjectObjects/class_006` | 1 | 6.9s |  |
| 1098 | `ecma3/ObjectObjects/e15_2_1_1_rt` | 54 | 9.7s |  |
| 1099 | `ecma3/ObjectObjects/e15_2_1_2_rt` | 3 | 6.9s |  |
| 1100 | `ecma3/ObjectObjects/e15_2_2_1_rt` | 47 | 7.6s |  |
| 1101 | `ecma3/ObjectObjects/e15_2_2_2` | 3 | 6.9s |  |
| 1102 | `ecma3/ObjectObjects/e15_2_3_1_1` | 1 | 6.9s |  |
| 1103 | `ecma3/ObjectObjects/e15_2_3_1_2` | 1 | 6.9s |  |
| 1104 | `ecma3/ObjectObjects/e15_2_3_1_3` | 1 | 6.8s |  |
| 1105 | `ecma3/ObjectObjects/e15_2_3_1_4` | 1 | 6.9s |  |
| 1106 | `ecma3/ObjectObjects/e15_2_3_1_rt` | 2 | 3.4s |  |
| 1107 | `ecma3/ObjectObjects/e15_2_3_rt` | 2 | 6.4s |  |
| 1108 | `ecma3/ObjectObjects/e15_2_4_1_rt` | 1 | 7.0s |  |
| 1109 | `ecma3/ObjectObjects/e15_2_4_2` | 10 | 7.2s |  |
| 1110 | `ecma3/ObjectObjects/e15_2_4_3` | 9 | 7.4s |  |
| 1111 | `ecma3/ObjectObjects/e8_6_2_6_001` | 1 | 7.0s |  |
| 1112 | `ecma3/ObjectObjects/propertyIsEnumerable` | 5 | 7.0s |  |
| 1113 | `ecma3/ObjectObjects/regress_72773_rt` | 1 | 7.0s |  |
| 1114 | `ecma3/ObjectObjects/regress_79129_001` | 1 | 6.9s |  |
| 1115 | `ecma3/ObjectObjects/toLocaleString_rt` | 5 | 7.0s |  |
| 1116 | `ecma3/Statements/block` | 4 | 7.0s |  |
| 1117 | `ecma3/Statements/e12_10_1` | 8 | 5.4s |  |
| 1118 | `ecma3/Statements/e12_2_1` | 18 | 5.7s |  |
| 1119 | `ecma3/Statements/e12_5_1` | 6 | 5.3s |  |
| 1120 | `ecma3/Statements/e12_5_2` | 6 | 5.3s |  |
| 1121 | `ecma3/Statements/e12_5_3` | 12 | 5.4s |  |
| 1122 | `ecma3/Statements/e12_6_1_1` | 3 | 5.3s |  |
| 1123 | `ecma3/Statements/e12_6_2_1` | 1 | 5.3s |  |
| 1124 | `ecma3/Statements/e12_6_2_2` | 1 | 5.2s |  |
| 1125 | `ecma3/Statements/e12_6_2_3` | 1 | 5.2s |  |
| 1126 | `ecma3/Statements/e12_6_2_4` | 1 | 5.2s |  |
| 1127 | `ecma3/Statements/e12_6_2_5` | 1 | 5.2s |  |
| 1128 | `ecma3/Statements/e12_6_2_6` | 1 | 5.2s |  |
| 1129 | `ecma3/Statements/e12_6_2_7` | 1 | 5.2s |  |
| 1130 | `ecma3/Statements/e12_6_2_8` | 1 | 5.2s |  |
| 1131 | `ecma3/Statements/e12_6_3_1` | 1 | 5.2s |  |
| 1132 | `ecma3/Statements/e12_6_3_10` | 2 | 5.3s |  |
| 1133 | `ecma3/Statements/e12_6_3_11` | 1 | 5.2s |  |
| 1134 | `ecma3/Statements/e12_6_3_19` | 2 | 5.3s |  |
| 1135 | `ecma3/Statements/e12_6_3_2` | 1 | 5.2s |  |
| 1136 | `ecma3/Statements/e12_6_3_3` | 1 | 5.3s |  |
| 1137 | `ecma3/Statements/e12_6_3_4` | 9 | 5.3s |  |
| 1138 | `ecma3/Statements/e12_6_3_9_rt` | 1 | 5.3s |  |
| 1139 | `ecma3/Statements/e12_9_1` | 5 | 5.3s |  |
| 1140 | `ecma3/Statements/edowhile_001` | 4 | 5.3s |  |
| 1141 | `ecma3/Statements/edowhile_002` | 12 | 5.3s |  |
| 1142 | `ecma3/Statements/edowhile_003` | 10 | 5.3s |  |
| 1143 | `ecma3/Statements/edowhile_004` | 12 | 5.3s |  |
| 1144 | `ecma3/Statements/edowhile_005` | 3 | 5.3s |  |
| 1145 | `ecma3/Statements/edowhile_006` | 8 | 5.3s |  |
| 1146 | `ecma3/Statements/edowhile_007` | 36 | 5.3s |  |
| 1147 | `ecma3/Statements/eforin_001_500476` | 2 | 5.2s |  |
| 1148 | `ecma3/Statements/eif_001` | 1 | 5.2s |  |
| 1149 | `ecma3/Statements/elabel_001` | 5 | 5.2s |  |
| 1150 | `ecma3/Statements/elabel_002` | 4 | 5.3s |  |
| 1151 | `ecma3/Statements/eregress_131348` | 4 | 5.5s |  |
| 1152 | `ecma3/Statements/eregress_74474_001` | 3 | 5.3s |  |
| 1153 | `ecma3/Statements/eregress_74474_002` | 1 | 55.3s |  |
| 1154 | `ecma3/Statements/eregress_74474_003` | 1 | 52.5s |  |
| 1155 | `ecma3/Statements/eregress_83532_001` | 1 | 5.2s |  |
| 1156 | `ecma3/Statements/eregress_83532_002` | 1 | 5.2s |  |
| 1157 | `ecma3/Statements/eswitch_001` | 5 | 5.3s |  |
| 1158 | `ecma3/Statements/eswitch_002` | 10 | 5.3s |  |
| 1159 | `ecma3/Statements/eswitch_003` | 9 | 2.4s |  |
| 1160 | `ecma3/Statements/eswitch_004` | 18 | 5.3s |  |
| 1161 | `ecma3/Statements/etry_001` | 12 | 5.4s |  |
| 1162 | `ecma3/Statements/etry_003` | 9 | 5.6s |  |
| 1163 | `ecma3/Statements/etry_004` | 3 | 5.4s |  |
| 1164 | `ecma3/Statements/etry_005` | 3 | 5.4s |  |
| 1165 | `ecma3/Statements/etry_006` | 4 | 5.4s |  |
| 1166 | `ecma3/Statements/etry_007` | 2 | 5.3s |  |
| 1167 | `ecma3/Statements/etry_008` | 6 | 3.4s |  |
| 1168 | `ecma3/Statements/etry_009` | 2 | 7.0s |  |
| 1169 | `ecma3/Statements/etry_010` | 4 | 7.0s |  |
| 1170 | `ecma3/Statements/etry_012` | 9 | 7.3s |  |
| 1171 | `ecma3/Statements/ewhile_001` | 1 | 6.8s |  |
| 1172 | `ecma3/Statements/ewhile_002` | 8 | 6.9s |  |
| 1173 | `ecma3/Statements/ewhile_003` | 10 | 6.9s |  |
| 1174 | `ecma3/Statements/ewhile_004` | 13 | 7.1s |  |
| 1175 | `ecma3/Statements/expression` | 1 | 6.8s |  |
| 1176 | `ecma3/Statements/throw` | 2 | 6.9s |  |
| 1177 | `ecma3/String/Split` | 19 | 7.1s |  |
| 1178 | `ecma3/String/concat` | 21 | 7.0s |  |
| 1179 | `ecma3/String/e15_5_3` | 2 | 6.7s |  |
| 1180 | `ecma3/String/e15_5_3_1_1` | 2 | 6.8s |  |
| 1181 | `ecma3/String/e15_5_3_1_2` | 1 | 6.8s |  |
| 1182 | `ecma3/String/e15_5_3_1_3` | 1 | 6.7s |  |
| 1183 | `ecma3/String/e15_5_3_1_4` | 1 | 6.8s |  |
| 1184 | `ecma3/String/e15_5_3_2_1` | 116 | 11.1s |  |
| 1185 | `ecma3/String/e15_5_3_2_2` | 2 | 6.8s |  |
| 1186 | `ecma3/String/e15_5_4` | 6 | 6.8s |  |
| 1187 | `ecma3/String/e15_5_4_10_1_rt` | 24 | 7.8s |  |
| 1188 | `ecma3/String/e15_5_4_11_1` | 387 | 7.3s |  |
| 1189 | `ecma3/String/e15_5_4_11_2` | 96 | 7.3s |  |
| 1190 | `ecma3/String/e15_5_4_11_3` | 240 | 7.2s |  |
| 1191 | `ecma3/String/e15_5_4_11_4` | 96 | 7.2s |  |
| 1192 | `ecma3/String/e15_5_4_11_5` | 131 | 7.3s |  |
| 1193 | `ecma3/String/e15_5_4_11_6` | 96 | 7.1s |  |
| 1194 | `ecma3/String/e15_5_4_12_1` | 387 | 7.3s |  |
| 1195 | `ecma3/String/e15_5_4_12_2` | 1 | 7.2s |  |
| 1196 | `ecma3/String/e15_5_4_12_3` | 864 | 7.4s |  |
| 1197 | `ecma3/String/e15_5_4_12_4` | 128 | 7.1s |  |
| 1198 | `ecma3/String/e15_5_4_12_5` | 96 | 1.9s |  |
| 1199 | `ecma3/String/e15_5_4_13` | 17 | 7.0s |  |
| 1200 | `ecma3/String/e15_5_4_1_rt` | 2 | 6.9s |  |
| 1201 | `ecma3/String/e15_5_4_2_1` | 6 | 6.9s |  |
| 1202 | `ecma3/String/e15_5_4_2_3` | 4 | 6.8s |  |
| 1203 | `ecma3/String/e15_5_4_2_rt` | 8 | 6.9s |  |
| 1204 | `ecma3/String/e15_5_4_3_1` | 7 | 6.8s |  |
| 1205 | `ecma3/String/e15_5_4_3_2` | 4 | 6.8s |  |
| 1206 | `ecma3/String/e15_5_4_3_3_rt` | 1 | 6.8s |  |
| 1207 | `ecma3/String/e15_5_4_4_1` | 189 | 6.8s |  |
| 1208 | `ecma3/String/e15_5_4_4_2` | 33 | 7.0s |  |
| 1209 | `ecma3/String/e15_5_4_4_3` | 18 | 3.4s |  |
| 1210 | `ecma3/String/e15_5_4_4_4_rt` | 52 | 10.8s |  |
| 1211 | `ecma3/String/e15_5_4_5_1` | 95 | 6.8s |  |
| 1212 | `ecma3/String/e15_5_4_5_2` | 31 | 7.3s |  |
| 1213 | `ecma3/String/e15_5_4_5_3` | 28 | 7.0s |  |
| 1214 | `ecma3/String/e15_5_4_5_5` | 269 | 6.9s |  |
| 1215 | `ecma3/String/e15_5_4_5_6_rt` | 11 | 7.4s |  |
| 1216 | `ecma3/String/e15_5_4_6_1` | 578 | 7.0s |  |
| 1217 | `ecma3/String/e15_5_4_6_2_rt` | 232 | 8.7s |  |
| 1218 | `ecma3/String/e15_5_4_7_1` | 654 | 7.2s |  |
| 1219 | `ecma3/String/e15_5_4_7_2` | 72 | 7.3s |  |
| 1220 | `ecma3/String/e15_5_4_7_3_rt` | 5 | 7.1s |  |
| 1221 | `ecma3/String/e15_5_4_8_1_rt` | 30 | 8.3s |  |
| 1222 | `ecma3/String/e15_5_4_8_3` | 13 | 6.9s |  |
| 1223 | `ecma3/String/e15_5_4_8_477132` | 1 | 6.7s |  |
| 1224 | `ecma3/String/e15_5_4_9_1_rt` | 22 | 7.6s |  |
| 1225 | `ecma3/String/ematch_001` | 24 | 6.8s |  |
| 1226 | `ecma3/String/ematch_002` | 32 | 6.9s |  |
| 1227 | `ecma3/String/ematch_003` | 10 | 6.8s |  |
| 1228 | `ecma3/String/ematch_004` | 8 | 6.9s |  |
| 1229 | `ecma3/String/eregress_104375` | 3 | 6.7s |  |
| 1230 | `ecma3/String/eregress_137879` | 7 | 6.7s |  |
| 1231 | `ecma3/String/eregress_137890` | 1 | 6.7s |  |
| 1232 | `ecma3/String/eregress_83293` | 9 | 6.7s |  |
| 1233 | `ecma3/String/ereplace_001` | 15 | 7.0s |  |
| 1234 | `ecma3/String/esplit_001` | 18 | 6.8s |  |
| 1235 | `ecma3/String/esplit_002` | 94 | 7.0s |  |
| 1236 | `ecma3/String/esplit_003` | 86 | 6.9s |  |
| 1237 | `ecma3/String/localeCompare_rt` | 4 | 6.8s |  |
| 1238 | `ecma3/String/replace_439458` | 5 | 6.7s |  |
| 1239 | `ecma3/String/search` | 8 | 6.7s |  |
| 1240 | `ecma3/String/split_407156` | 1 | 6.6s |  |
| 1241 | `ecma3/String/split_504567` | 1 | 6.6s |  |
| 1242 | `ecma3/String/substr` | 24 | 7.1s |  |
| 1243 | `ecma3/String/toLocaleLowerCase` | 387 | 7.2s |  |
| 1244 | `ecma3/String/toLocaleLowerCase2` | 96 | 7.1s |  |
| 1245 | `ecma3/String/toLocaleLowerCase3` | 240 | 7.2s |  |
| 1246 | `ecma3/String/toLocaleLowerCase4` | 96 | 7.1s |  |
| 1247 | `ecma3/String/toLocaleLowerCase5` | 131 | 7.2s |  |
| 1248 | `ecma3/String/toLocaleLowerCase6` | 96 | 1.9s |  |
| 1249 | `ecma3/String/toLocaleUpperCase` | 96 | 7.0s |  |
| 1250 | `ecma3/String/toLocaleUpperCase2` | 128 | 7.1s |  |
| 1251 | `ecma3/String/toLocaleUpperCase3` | 768 | 7.3s |  |
| 1252 | `ecma3/String/toLocaleUpperCase4` | 1 | 7.2s |  |
| 1253 | `ecma3/String/toLocaleUpperCase5` | 387 | 7.2s |  |
| 1254 | `ecma3/TypeConversion/e9_2_rt` | 36 | 7.0s |  |
| 1255 | `ecma3/TypeConversion/e9_3` | 15 | 6.8s |  |
| 1256 | `ecma3/TypeConversion/e9_3_1` | 9 | 6.8s |  |
| 1257 | `ecma3/TypeConversion/e9_3_1_1` | 189 | 9.5s |  |
| 1258 | `ecma3/TypeConversion/e9_3_1_2` | 12 | 6.8s |  |
| 1259 | `ecma3/TypeConversion/e9_4_1` | 19 | 6.9s |  |
| 1260 | `ecma3/TypeConversion/e9_4_2` | 19 | 6.9s |  |
| 1261 | `ecma3/TypeConversion/e9_5_2` | 56 | 7.2s |  |
| 1262 | `ecma3/TypeConversion/e9_6` | 34 | 7.0s |  |
| 1263 | `ecma3/TypeConversion/e9_7` | 38 | 7.1s |  |
| 1264 | `ecma3/TypeConversion/e9_9_1_rt` | 48 | 5.3s |  |
| 1265 | `ecma3/Types/e8_1` | 3 | 5.3s |  |
| 1266 | `ecma3/Types/e8_2` | 2 | 5.4s |  |
| 1267 | `ecma3/Types/e8_3` | 4 | 5.3s |  |
| 1268 | `ecma3/Types/e8_4` | 4 | 5.3s |  |
| 1269 | `ecma3/Types/e8_6_1` | 7 | 5.3s |  |
| 1270 | `ecma3/Unicode/u0000_BasicLatin` | 21 | 5.3s |  |
| 1271 | `ecma3/Unicode/u0080_Latin_1Supplement` | 21 | 5.3s |  |
| 1272 | `ecma3/Unicode/u0100_LatinExtended_A` | 21 | 5.4s |  |
| 1273 | `ecma3/Unicode/u0180_LatinExtended_B` | 21 | 5.4s |  |
| 1274 | `ecma3/Unicode/u0250_IPAExtensions` | 21 | 1.1s |  |
| 1275 | `ecma3/Unicode/u02B0_SpacingModifierLetters` | 21 | 1.1s |  |
| 1276 | `ecma3/Unicode/u0300_CombiningDiacriticalMarks` | 21 | 1.1s |  |
| 1277 | `ecma3/Unicode/u0370_GreekandCoptic` | 21 | 1.1s |  |
| 1278 | `ecma3/Unicode/u0400_Cyrillic` | 42 | 1.1s |  |
| 1279 | `ecma3/Unicode/u0500_CyrillicSupplementary` | 21 | 1.1s |  |
| 1280 | `ecma3/Unicode/u0530_Armenian` | 21 | 1.1s |  |
| 1281 | `ecma3/Unicode/u0590_Hebrew` | 21 | 1.1s |  |
| 1282 | `ecma3/Unicode/u0600_Arabic` | 42 | 1.1s |  |
| 1283 | `ecma3/Unicode/u0700_Syriac` | 21 | 1.1s |  |
| 1284 | `ecma3/Unicode/u0780_Thaana` | 21 | 1.1s |  |
| 1285 | `ecma3/Unicode/u0900_Devanagari` | 21 | 1.1s |  |
| 1286 | `ecma3/Unicode/u0980_Bengali` | 21 | 1.1s |  |
| 1287 | `ecma3/Unicode/u0A00_Gurmukhi` | 21 | 1.1s |  |
| 1288 | `ecma3/Unicode/u0A80_Gujarati` | 21 | 1.1s |  |
| 1289 | `ecma3/Unicode/u0B00_Oriya` | 21 | 1.1s |  |
| 1290 | `ecma3/Unicode/u0B80_Tamil` | 21 | 1.1s |  |
| 1291 | `ecma3/Unicode/u0C00_Telugu` | 21 | 1.1s |  |
| 1292 | `ecma3/Unicode/u0C80_Kannada` | 21 | 1.1s |  |
| 1293 | `ecma3/Unicode/u0D00_Malayalam` | 21 | 1.1s |  |
| 1294 | `ecma3/Unicode/u0D80_Sinhala` | 21 | 1.1s |  |
| 1295 | `ecma3/Unicode/u0E00_Thai` | 21 | 1.1s |  |
| 1296 | `ecma3/Unicode/u0E80_Lao` | 21 | 5.3s |  |
| 1297 | `ecma3/Unicode/u0F00_Tibetan` | 42 | 1.1s |  |
| 1298 | `ecma3/Unicode/u1000_Myanmar` | 21 | 1.1s |  |
| 1299 | `ecma3/Unicode/u10A0_Georgian` | 21 | 1.1s |  |
| 1300 | `ecma3/Unicode/u1100_HangulJamo` | 42 | 1.1s |  |
| 1301 | `ecma3/Unicode/u1200_Ethiopic` | 42 | 1.1s |  |
| 1302 | `ecma3/Unicode/u13A0_Cherokee` | 21 | 1.1s |  |
| 1303 | `ecma3/Unicode/u1400_UnifiedCanadianAboriginalSyllabics` | 63 | 1.1s |  |
| 1304 | `ecma3/Unicode/u1680_Ogham` | 21 | 1.1s |  |
| 1305 | `ecma3/Unicode/u16A0_Runic` | 21 | 1.1s |  |
| 1306 | `ecma3/Unicode/u1700_Tagalog` | 21 | 1.1s |  |
| 1307 | `ecma3/Unicode/u1720_Hanunoo` | 21 | 1.1s |  |
| 1308 | `ecma3/Unicode/u1740_Buhid` | 21 | 1.1s |  |
| 1309 | `ecma3/Unicode/u1760_Tagbanwa` | 21 | 1.1s |  |
| 1310 | `ecma3/Unicode/u1780_Khmer` | 21 | 1.1s |  |
| 1311 | `ecma3/Unicode/u1800_Mongolian` | 21 | 1.1s |  |
| 1312 | `ecma3/Unicode/u1E00_LatinExtendedAdditional` | 42 | 1.1s |  |
| 1313 | `ecma3/Unicode/u1F00_GreekExtended` | 42 | 1.1s |  |
| 1314 | `ecma3/Unicode/u2000_GeneralPunctuation` | 21 | 3.5s |  |
| 1315 | `ecma3/Unicode/u2070_SuperscriptsandSubscripts` | 21 | 3.6s |  |
| 1316 | `ecma3/Unicode/u20A0_CurrencySymbols` | 21 | 3.6s |  |
| 1317 | `ecma3/Unicode/u20D0_CombiningDiacriticalMarksforSymbols` | 21 | 0.7s |  |
| 1318 | `ecma3/Unicode/u2100_LetterlikeSymbols` | 21 | 0.7s |  |
| 1319 | `ecma3/Unicode/u2150_NumberForms` | 21 | 0.7s |  |
| 1320 | `ecma3/Unicode/u2190_Arrows` | 21 | 0.7s |  |
| 1321 | `ecma3/Unicode/u2200_MathematicalOperators` | 42 | 0.7s |  |
| 1322 | `ecma3/Unicode/u2300_MiscellaneousTechnical` | 42 | 3.6s |  |
| 1323 | `ecma3/Unicode/u2400_ControlPictures` | 21 | 1.6s |  |
| 1324 | `ecma3/Unicode/u2440_OpticalCharacterRecognition` | 21 | 0.7s |  |
| 1325 | `ecma3/Unicode/u2460_EnclosedAlphanumerics` | 21 | 0.7s |  |
| 1326 | `ecma3/Unicode/u2500_BoxDrawing` | 21 | 0.7s |  |
| 1327 | `ecma3/Unicode/u2580_BlockElements` | 21 | 0.7s |  |
| 1328 | `ecma3/Unicode/u25A0_GeometricShapes` | 21 | 0.7s |  |
| 1329 | `ecma3/Unicode/u2600_MiscellaneousSymbols` | 42 | 0.7s |  |
| 1330 | `ecma3/Unicode/u2700_Dingbats` | 21 | 0.7s |  |
| 1331 | `ecma3/Unicode/u27C0_MiscellaneousMathematicalSymbols_A` | 21 | 3.6s |  |
| 1332 | `ecma3/Unicode/u27F0_SupplementalArrows_A` | 21 | 0.7s |  |
| 1333 | `ecma3/Unicode/u2800_BraillePatterns` | 42 | 0.7s |  |
| 1334 | `ecma3/Unicode/u2900_SupplementalArrows_B` | 21 | 0.7s |  |
| 1335 | `ecma3/Unicode/u2980_MiscellaneousMathematicalSymbols_B` | 21 | 0.7s |  |
| 1336 | `ecma3/Unicode/u2A00_SupplementalMathematicalOperators` | 42 | 1.6s |  |
| 1337 | `ecma3/Unicode/u2E80_CJKRadicalsSupplement` | 21 | 0.7s |  |
| 1338 | `ecma3/Unicode/u2F00_KangxiRadicals` | 21 | 0.7s |  |
| 1339 | `ecma3/Unicode/u2FF0_IdeographicDescriptionCharacters` | 21 | 0.7s |  |
| 1340 | `ecma3/Unicode/u3000_CJKSymbolsandPunctuation` | 21 | 0.7s |  |
| 1341 | `ecma3/Unicode/u3040_Hiragana` | 21 | 0.7s |  |
| 1342 | `ecma3/Unicode/u30A0_Katakana` | 21 | 0.7s |  |
| 1343 | `ecma3/Unicode/u3100_Bopomofo` | 21 | 0.7s |  |
| 1344 | `ecma3/Unicode/u3130_HangulCompatibilityJamo` | 21 | 0.7s |  |
| 1345 | `ecma3/Unicode/u3190_Kanbun` | 21 | 0.7s |  |
| 1346 | `ecma3/Unicode/u31A0_BopomofoExtended` | 21 | 0.7s |  |
| 1347 | `ecma3/Unicode/u31F0_KatakanaPhoneticExtensions` | 21 | 0.7s |  |
| 1348 | `ecma3/Unicode/u3200_EnclosedCJKLettersandMonths` | 42 | 0.7s |  |
| 1349 | `ecma3/Unicode/u3300_CJKCompatibility` | 42 | 0.7s |  |
| 1350 | `ecma3/Unicode/u3400_CJKUnifiedIdeographsExtensionA` | 567 | 1.6s |  |
| 1351 | `ecma3/Unicode/u4E00_CJKUnifiedIdeographs` | 63 | 1.3s |  |
| 1352 | `ecma3/Unicode/u5000_CJKUnifiedIdeographs` | 357 | 0.9s |  |
| 1353 | `ecma3/Unicode/u6000_CJKUnifiedIdeographs` | 357 | 0.9s |  |
| 1354 | `ecma3/Unicode/u7000_CJKUnifiedIdeographs` | 357 | 1.5s |  |
| 1355 | `ecma3/Unicode/u8000_CJKUnifiedIdeographs` | 357 | 4.1s |  |
| 1356 | `ecma3/Unicode/u9000_CJKUnifiedIdeographs` | 357 | 0.9s |  |
| 1357 | `ecma3/Unicode/uA000_YiSyllables` | 105 | 0.8s |  |
| 1358 | `ecma3/Unicode/uA490_YiRadicals` | 21 | 3.6s |  |
| 1359 | `ecma3/Unicode/uAC00_HangulSyllables` | 945 | 1.4s |  |
| 1360 | `ecma3/Unicode/uE000_PrivateUseArea` | 546 | 4.5s |  |
| 1361 | `ecma3/Unicode/uF900_CJKCompatibilityIdeographs` | 63 | 0.8s |  |
| 1362 | `ecma3/Unicode/uFB00_AlphabeticPresentationForms` | 21 | 0.7s |  |
| 1363 | `ecma3/Unicode/uFB50_ArabicPresentationForms_A` | 63 | 0.8s |  |
| 1364 | `ecma3/Unicode/uFE00_VariationSelectors` | 21 | 0.7s |  |
| 1365 | `ecma3/Unicode/uFE20_CombiningHalfMarks` | 21 | 0.7s |  |
| 1366 | `ecma3/Unicode/uFE30_CJKCompatibilityForms` | 21 | 7.2s |  |
| 1367 | `ecma3/Unicode/uFE50_SmallFormVariants` | 21 | 8.0s |  |
| 1368 | `ecma3/Unicode/uFE70_ArabicPresentationForms_B` | 21 | 7.0s |  |
| 1369 | `ecma3/Unicode/uFF00_HalfwidthandFullwidthForms` | 21 | 2.5s |  |
| 1370 | `ecma3/Unicode/uFFF0_Specials` | 21 | 7.0s |  |
| 1371 | `ecma3/Unicode/uc_001` | 4 | 7.1s |  |
| 1372 | `ecma3/Unicode/uc_003` | 6 | 7.1s |  |
| 1373 | `ecma3/Unicode/uc_004` | 8 | 7.1s |  |
| 1374 | `ecma3/Unicode/uc_005` | 10 | 7.2s |  |
| 1375 | `ecma3/Unicode/uc_006` | 56 | 7.4s |  |
| 1376 | `ecma3/Unicode/ucs4_bug_515947` | 3 | 7.1s |  |
| 1377 | `ecma3/instanceof/instanceof_001` | 2 | 7.0s |  |
| 1378 | `ecma3/instanceof/instanceof_002` | 5 | 7.0s |  |
| 1379 | `ecma3/instanceof/instanceof_003_rt` | 2 | 7.0s |  |
| 1380 | `ecma3/instanceof/regress_7635_rt` | 3 | 7.1s |  |
| 1381 | `misc/addNull` | 40 | 3.6s |  |
| 1382 | `misc/bug_490371` | 2 | 7.0s |  |
| 1383 | `misc/bug_521353` | 6 | 7.0s |  |
| 1384 | `misc/bug_532806` | 1 | 6.8s |  |
| 1385 | `misc/bug_534074` | 1 | 6.8s |  |
| 1386 | `misc/bug_547583` | 8 | 6.8s |  |
| 1387 | `misc/bug_598322` | 120 | 8.6s |  |
| 1388 | `misc/denseArrayDelete` | 1 | 6.7s |  |
| 1389 | `misc/getlex_anyname` | 1 | 6.8s |  |
| 1390 | `misc/md5_t` | 7 | 7.3s |  |
| 1391 | `misc/nsunbox` | 3 | 6.7s |  |
| 1392 | `misc/superInit` | 1 | 6.8s |  |
| 1393 | `misc/unchecked` | 1 | 6.8s |  |
| 1394 | `mops/lf32` | 20 | 7.2s |  |
| 1395 | `mops/lf64` | 21 | 7.0s |  |
| 1396 | `mops/li16` | 26 | 6.8s |  |
| 1397 | `mops/li32` | 20 | 6.8s |  |
| 1398 | `mops/li8` | 46 | 6.9s |  |
| 1399 | `mops/lix16` | 17 | 6.8s |  |
| 1400 | `mops/lix8` | 21 | 6.9s |  |
| 1401 | `mops/mops_basics` | 56 | 10.2s |  |
| 1402 | `mops/sf32` | 26 | 6.9s |  |
| 1403 | `mops/sf64` | 51 | 7.0s |  |
| 1404 | `mops/si16` | 28 | 7.0s |  |
| 1405 | `mops/si32` | 33 | 7.0s |  |
| 1406 | `mops/si8` | 28 | 7.0s |  |
| 1407 | `recursion/pcre_could_be_empty_branch` | 1 | 6.8s |  |
| 1408 | `recursion/pcre_find_firstassertedchar` | 2 | 6.8s |  |
| 1409 | `recursion/pcre_is_anchored` | 2 | 6.8s |  |
| 1410 | `recursion/pcre_is_startline` | 2 | 6.8s |  |
| 1411 | `recursion/xml_functions` | 3 | 6.9s |  |
| 1412 | `regress/bug_415080` | 1 | 6.7s |  |
| 1413 | `regress/bug_420755` | 27 | 7.6s |  |
| 1414 | `regress/bug_424341` | 1 | 6.7s |  |
| 1415 | `regress/bug_458419` | 1 | 7.0s |  |
| 1416 | `regress/bug_460872` | 1 | 7.0s |  |
| 1417 | `regress/bug_481942` | 1 | 7.0s |  |
| 1418 | `regress/bug_492046` | 1 | 7.0s |  |
| 1419 | `regress/bug_498979` | 1 | 7.0s |  |
| 1420 | `regress/bug_521353` | 49 | 3.5s |  |
| 1421 | `regress/bug_526295` | 2 | 7.1s |  |
| 1422 | `regress/bug_532791` | 1 | 7.0s |  |
| 1423 | `regress/bug_535882` | 1 | 7.0s |  |
| 1424 | `regress/bug_538107` | 2 | 7.0s |  |
| 1425 | `regress/bug_547295` | 2 | 7.0s |  |
| 1426 | `regress/bug_549389` | 1 | 6.9s |  |
| 1427 | `regress/bug_551587` | 6 | 7.0s |  |
| 1428 | `regress/bug_551587_2_swf10` | 2 | 7.1s |  |
| 1429 | `regress/bug_551587_2_swf11` | 2 | 7.2s |  |
| 1430 | `regress/bug_555544` | 1 | 7.1s |  |
| 1431 | `regress/bug_555705_orig` | 2 | 6.8s |  |
| 1432 | `regress/bug_558863_swf11` | 1 | 7.1s |  |
| 1433 | `regress/bug_559565` | 1 | 6.9s |  |
| 1434 | `regress/bug_561191` | 19 | 7.0s |  |
| 1435 | `regress/bug_564839` | 21 | 7.3s |  |
| 1436 | `regress/bug_588041` | 1 | 7.0s |  |
| 1437 | `regress/bug_593383` | 109 | 8.6s |  |
| 1438 | `regress/bug_598683` | 2 | 7.0s |  |
| 1439 | `regress/bug_599357` | 53 | 8.3s |  |
| 1440 | `regress/bug_609416_swf11` | 1 | 7.0s |  |
| 1441 | `regress/bug_615544` | 2 | 6.9s |  |
| 1442 | `regress/bug_637809` | 3 | 6.9s |  |
| 1443 | `regress/bug_642535` | 8 | 7.0s |  |
| 1444 | `regress/bug_643009` | 6 | 7.0s |  |
| 1445 | `regress/bug_654761` | 2 | 7.0s |  |
| 1446 | `regress/bug_654807_swf12` | 170 | 7.6s |  |
| 1447 | `regress/bug_654807_swf13` | 170 | 7.5s |  |
| 1448 | `regress/bug_655315` | 2 | 7.0s |  |
| 1449 | `regress/bug_663469` | 51 | 6.9s |  |
| 1450 | `regress/bug_672012` | 1 | 7.0s |  |
| 1451 | `regress/bug_673284` | 1 | 7.1s |  |
| 1452 | `regress/bug_687838` | 111 | 7.9s |  |
| 1453 | `regress/bug_700613` | 5 | 7.0s |  |
| 1454 | `regress/bug_703238` | 27 | 6.8s |  |
| 1455 | `regress/bug_707133` | 2 | 7.0s |  |
| 1456 | `regress/bug_723461` | 6 | 7.0s |  |
| 1457 | `regress/security/bug_550269` | 2 | 7.0s |  |
| 1458 | `regress/security/bug_663469` | 5 | 7.0s |  |

## Ruffle-Matched Tests

**51 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `as3/Array/bug_535446` | 4 | 4 | 7.1s |  |
| 2 | `as3/Array/length_mods` | 5 | 11 | 7.5s |  |
| 3 | `as3/Expressions/asOperator/asOper` | 2 | 2 | 7.1s |  |
| 4 | `as3/Math/e15_1_2_2` | 1 | 1 | 2.9s |  |
| 5 | `as3/RegExp/replace` | 2 | 3 | 6.7s |  |
| 6 | `as3/RuntimeErrors/Error1092XmlUnterminatedXmlDecl` | 1 | 1 | 7.0s |  |
| 7 | `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | 1 | 1 | 7.0s |  |
| 8 | `as3/Types/Number/cos` | 1 | 1 | 6.9s |  |
| 9 | `as3/Types/Number/e15_7_4_6_1/swf14` | 18 | 18 | 8.0s |  |
| 10 | `as3/Types/Number/e15_7_4_6_1/swf15` | 3 | 3 | 8.0s |  |
| 11 | `e4x/XML/bug_564468` | 7 | 7 | 7.3s |  |
| 12 | `e4x/XML/e13_4_4_30` | 3 | 3 | 7.1s |  |
| 13 | `e4x/XML/misc_errors` | 2 | 2 | 7.7s |  |
| 14 | `e4x/XML/setNotification` | 13 | 13 | 3.8s |  |
| 15 | `e4x/XMLList/e13_5_4_18` | 2 | 2 | 7.2s |  |
| 16 | `ecma3/Array/e15_4_4_5` | 1 | 1 | 6.7s |  |
| 17 | `ecma3/Array/toLocaleString` | 1 | 1 | 6.7s |  |
| 18 | `ecma3/Date/e15_9_4_2_1` | 2 | 2 | 8.0s |  |
| 19 | `ecma3/Date/e15_9_5_10` | 3 | 3 | 8.3s |  |
| 20 | `ecma3/Date/e15_9_5_10_1` | 33 | 33 | 8.0s |  |
| 21 | `ecma3/Date/e15_9_5_10_10` | 31 | 31 | 8.1s |  |
| 22 | `ecma3/Date/e15_9_5_10_11` | 93 | 93 | 8.0s |  |
| 23 | `ecma3/Date/e15_9_5_11` | 3 | 3 | 7.8s |  |
| 24 | `ecma3/Date/e15_9_5_12` | 3 | 3 | 8.1s |  |
| 25 | `ecma3/Date/e15_9_5_12_1` | 67 | 67 | 7.9s |  |
| 26 | `ecma3/Date/e15_9_5_13` | 3 | 3 | 8.1s |  |
| 27 | `ecma3/Date/e15_9_5_15_1` | 3 | 3 | 7.9s |  |
| 28 | `ecma3/Date/e15_9_5_17_1` | 3 | 3 | 8.0s |  |
| 29 | `ecma3/Date/e15_9_5_22_1` | 66 | 66 | 8.8s |  |
| 30 | `ecma3/Date/e15_9_5_28_1` | 3 | 3 | 8.3s |  |
| 31 | `ecma3/Date/e15_9_5_29_1` | 1 | 1 | 8.3s |  |
| 32 | `ecma3/Date/e15_9_5_35_1` | 9 | 9 | 8.4s |  |
| 33 | `ecma3/Date/e15_9_5_4` | 14 | 14 | 8.2s |  |
| 34 | `ecma3/JSON/Classes` | 1 | 3 | 6.9s |  |
| 35 | `ecma3/JSON/adhoc` | 7 | 7 | 7.5s |  |
| 36 | `ecma3/Number/e15_7_1` | 1 | 1 | 7.0s |  |
| 37 | `ecma3/Number/e15_7_2` | 1 | 1 | 7.5s |  |
| 38 | `ecma3/Number/e15_7_4_2_4` | 1 | 1 | 8.6s |  |
| 39 | `ecma3/Number/e15_7_4_7_1` | 3 | 10 | 7.5s |  |
| 40 | `ecma3/Number/eregress_121952` | 1 | 1 | 7.2s |  |
| 41 | `ecma3/Number/toStringLimits` | 1 | 1 | 6.9s |  |
| 42 | `ecma3/Number/tostring_001` | 2 | 2 | 6.9s |  |
| 43 | `ecma3/String/e15_5_1` | 1 | 1 | 7.2s |  |
| 44 | `ecma3/String/e15_5_2` | 1 | 1 | 7.5s |  |
| 45 | `ecma3/TypeConversion/e9_8_1` | 1 | 1 | 5.3s |  |
| 46 | `ecma3/Types/e8_5` | 3 | 3 | 5.3s |  |
| 47 | `regress/bug_478501` | 1 | 1 | 6.9s |  |
| 48 | `regress/bug_479786` | 1 | 1 | 7.0s |  |
| 49 | `regress/bug_558863_swf10` | 1 | 1 | 7.1s |  |
| 50 | `regress/bug_609416_swf10` | 1 | 1 | 7.0s |  |
| 51 | `regress/bug_638233` | 2 | 2 | 7.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**29 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as3/Array/insertremove` | 99.7% | 30766 | 30870 | 104 |  |
| 2 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321 | 323 | 2 |  |
| 3 | `as3/AMF/AMFSerializer` | 99.1% | 223 | 225 | 2 |  |
| 4 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474 | 481 | 7 |  |
| 5 | `e4x/QName/e13_3_2` | 98.0% | 48 | 49 | 1 |  |
| 6 | `recursion/pcre_find_fixedlength` | 95.0% | 19 | 20 | 1 |  |
| 7 | `e4x/XML/e13_4_4_17` | 94.7% | 18 | 19 | 1 |  |
| 8 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89 | 94 | 5 |  |
| 9 | `e4x/Namespace/e13_2_5` | 94.4% | 34 | 36 | 2 |  |
| 10 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16 | 17 | 1 |  |
| 11 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13 | 14 | 1 |  |
| 12 | `e4x/XML/e13_4_4_28` | 92.3% | 12 | 13 | 1 |  |
| 13 | `ecma3/Number/toLocaleString_rt` | 91.7% | 44 | 48 | 4 |  |
| 14 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28 | 31 | 3 |  |
| 15 | `e4x/XMLList/e13_5_4_17` | 90.0% | 9 | 10 | 1 |  |
| 16 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9 | 10 | 1 |  |
| 17 | `ecma3/ObjectObjects/hasOwnProperty` | 90.0% | 9 | 10 | 1 |  |
| 18 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54 | 60 | 6 |  |
| 19 | `e4x/Expressions/e11_1_1` | 89.7% | 35 | 39 | 4 |  |
| 20 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8 | 9 | 1 |  |
| 21 | `e4x/XML/e13_4_4_36` | 81.2% | 13 | 16 | 3 |  |
| 22 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6 | 8 | 2 |  |
| 23 | `ecma3/Statements/eforin_001` | 75.0% | 12 | 16 | 4 |  |
| 24 | `ecma3/String/e15_5_5_1` | 70.0% | 7 | 10 | 3 |  |
| 25 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2 | 3 | 1 |  |
| 26 | `ecma3/Unicode/utf8count` | 66.7% | 2 | 3 | 1 |  |
| 27 | `regress/bug_550958` | 66.7% | 2 | 3 | 1 |  |
| 28 | `e4x/Statements/e12_1` | 64.7% | 11 | 17 | 6 |  |
| 29 | `e4x/Expressions/e11_1_2` | 50.0% | 12 | 24 | 12 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `as3/Definitions/Super/SuperInForLoop` | exit code 1 | 6.6s |  |
| 2 | `as3/Definitions/Super/SuperProps` | exit code 1 | 6.8s |  |
| 3 | `misc/bug_508617` | exit code 1 | 6.8s |  |
| 4 | `regress/bug_483783` | exit code 1 | 7.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**61 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as3/Array/insertremove` | 99.7% | 30766/30870 | 30870 | 30870 |  |
| 2 | `ecma3/String/e15_5_4_5_4` | 99.4% | 321/323 | 323 | 323 |  |
| 3 | `as3/AMF/AMFSerializer` | 99.1% | 223/225 | 225 | 225 |  |
| 4 | `ecma3/String/e15_5_3_2_3` | 98.5% | 474/481 | 481 | 481 |  |
| 5 | `e4x/QName/e13_3_2` | 98.0% | 48/49 | 49 | 49 |  |
| 6 | `recursion/pcre_find_fixedlength` | 95.0% | 19/20 | 20 | 20 |  |
| 7 | `e4x/XML/e13_4_4_17` | 94.7% | 18/19 | 19 | 19 |  |
| 8 | `ecma3/TypeConversion/e9_3_1_3_rt` | 94.7% | 89/94 | 94 | 94 |  |
| 9 | `e4x/Namespace/e13_2_5` | 94.4% | 34/36 | 36 | 36 |  |
| 10 | `as3/Definitions/Variable/ConstVariables_custom1` | 94.1% | 16/17 | 17 | 17 |  |
| 11 | `ecma3/Function/e15_3_4_3_1` | 92.9% | 13/14 | 14 | 14 |  |
| 12 | `e4x/XML/e13_4_4_28` | 92.3% | 12/13 | 13 | 13 |  |
| 13 | `ecma3/Number/toLocaleString_rt` | 91.7% | 44/48 | 48 | 48 |  |
| 14 | `ecma3/GlobalObject/e15_1_2_2_2` | 90.3% | 28/31 | 31 | 31 |  |
| 15 | `e4x/XMLList/e13_5_4_17` | 90.0% | 9/10 | 10 | 10 |  |
| 16 | `ecma3/Function/e15_3_4_4_1_rt` | 90.0% | 9/10 | 10 | 10 |  |
| 17 | `ecma3/ObjectObjects/hasOwnProperty` | 90.0% | 9/10 | 10 | 10 |  |
| 18 | `ecma3/String/e15_5_4_8_2` | 90.0% | 54/60 | 60 | 60 |  |
| 19 | `e4x/Expressions/e11_1_1` | 89.7% | 35/39 | 39 | 39 |  |
| 20 | `e4x/XML/e13_4_4_32/v9` | 88.9% | 8/9 | 9 | 9 |  |
| 21 | `e4x/XML/e13_4_4_36` | 81.2% | 13/16 | 16 | 16 |  |
| 22 | `ecma3/ObjectObjects/isPrototypeOf` | 75.0% | 6/8 | 8 | 8 |  |
| 23 | `ecma3/Statements/eforin_001` | 75.0% | 12/16 | 16 | 16 |  |
| 24 | `ecma3/String/e15_5_5_1` | 70.0% | 7/10 | 10 | 10 |  |
| 25 | `as3/Definitions/Super/SuperRuntimeError` | 66.7% | 2/3 | 3 | 3 |  |
| 26 | `ecma3/Unicode/utf8count` | 66.7% | 2/3 | 3 | 3 |  |
| 27 | `regress/bug_550958` | 66.7% | 2/3 | 2 | 3 |  |
| 28 | `e4x/Statements/e12_1` | 64.7% | 11/17 | 17 | 17 |  |
| 29 | `e4x/Expressions/e11_1_2` | 50.0% | 12/24 | 24 | 20 |  |
| 30 | `regress/bug_539328` | 46.7% | 7/15 | 8 | 15 |  |
| 31 | `e4x/Expressions/e11_1_4` | 37.8% | 14/37 | 37 | 34 |  |
| 32 | `as3/Expressions/QualifiedReferences/WildcardOperator` | 33.3% | 1/3 | 3 | 3 |  |
| 33 | `ecma3/Exceptions/exception_011_rt` | 33.3% | 1/3 | 1 | 3 |  |
| 34 | `ecma3/Expressions/e11_6_1_3` | 33.3% | 3/9 | 9 | 9 |  |
| 35 | `e4x/Expressions/e11_3_1` | 28.6% | 10/35 | 35 | 20 |  |
| 36 | `e4x/XML/e13_4_4_2` | 26.7% | 4/15 | 14 | 15 |  |
| 37 | `as3/String/localeCompare_585791/v9` | 25.0% | 2/8 | 8 | 8 |  |
| 38 | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 16.7% | 1/6 | 6 | 6 |  |
| 39 | `e4x/Regress/regress-524214` | 9.1% | 1/11 | 11 | 3 |  |
| 40 | `as3/Definitions/Classes/ClassDef/Bug118272Package` | 0.0% | 0/6 | 6 | 6 |  |
| 41 | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 42 | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | 0.0% | 0/2 | 1 | 2 |  |
| 43 | `as3/RuntimeErrors/Error1052InvalidUriPassed` | 0.0% | 0/1 | 1 | 1 |  |
| 44 | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 45 | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | 0.0% | 0/1 | 0 | 1 |  |
| 46 | `as3/RuntimeErrors/Error1075MathNotAFunction` | 0.0% | 0/1 | 1 | 1 |  |
| 47 | `as3/RuntimeErrors/Error1076MathNotAConstructor` | 0.0% | 0/1 | 1 | 1 |  |
| 48 | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 0.0% | 0/1 | 1 | 1 |  |
| 49 | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | 0.0% | 0/3 | 3 | 3 |  |
| 50 | `as3/RuntimeErrors/Error1117InvalidXmlName` | 0.0% | 0/2 | 1 | 2 |  |
| 51 | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | 0.0% | 0/2 | 1 | 2 |  |
| 52 | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | 0.0% | 0/1 | 1 | 1 |  |
| 53 | `e4x/Global/e13_1_2_1` | 0.0% | 0/10 | 0 | 10 |  |
| 54 | `e4x/Global/isXMLNameTypeErr` | 0.0% | 0/5 | 3 | 5 |  |
| 55 | `e4x/Regress/regress-263935` | 0.0% | 0/3 | 3 | 2 |  |
| 56 | `ecma3/Exceptions/exception_001_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 57 | `ecma3/Exceptions/exception_002_rt` | 0.0% | 0/1 | 0 | 1 |  |
| 58 | `ecma3/Exceptions/expression_005_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 59 | `ecma3/Expressions/e11_2_2_10_rt` | 0.0% | 0/1 | 1 | 1 |  |
| 60 | `ecma3/Statements/e12_10` | 0.0% | 0/1 | 1 | 1 |  |
| 61 | `ecma3/Statements/eforin_002` | 0.0% | 0/10 | 10 | 10 |  |
