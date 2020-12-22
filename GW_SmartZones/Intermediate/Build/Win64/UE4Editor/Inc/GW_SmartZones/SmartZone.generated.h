// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef GW_SMARTZONES_SmartZone_generated_h
#error "SmartZone.generated.h already included, missing '#pragma once' in SmartZone.h"
#endif
#define GW_SMARTZONES_SmartZone_generated_h

#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_SPARSE_DATA
#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASmartZone(); \
	friend struct Z_Construct_UClass_ASmartZone_Statics; \
public: \
	DECLARE_CLASS(ASmartZone, ATriggerBox, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GW_SmartZones"), NO_API) \
	DECLARE_SERIALIZER(ASmartZone)


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_INCLASS \
private: \
	static void StaticRegisterNativesASmartZone(); \
	friend struct Z_Construct_UClass_ASmartZone_Statics; \
public: \
	DECLARE_CLASS(ASmartZone, ATriggerBox, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GW_SmartZones"), NO_API) \
	DECLARE_SERIALIZER(ASmartZone)


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASmartZone(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASmartZone) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASmartZone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASmartZone); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASmartZone(ASmartZone&&); \
	NO_API ASmartZone(const ASmartZone&); \
public:


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASmartZone(ASmartZone&&); \
	NO_API ASmartZone(const ASmartZone&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASmartZone); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASmartZone); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASmartZone)


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_IsInDebugMode() { return STRUCT_OFFSET(ASmartZone, m_IsInDebugMode); }


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_7_PROLOG
#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_PRIVATE_PROPERTY_OFFSET \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_SPARSE_DATA \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_RPC_WRAPPERS \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_INCLASS \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_PRIVATE_PROPERTY_OFFSET \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_SPARSE_DATA \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_INCLASS_NO_PURE_DECLS \
	GW_SmartZones_Source_GW_SmartZones_SmartZone_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GW_SMARTZONES_API UClass* StaticClass<class ASmartZone>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GW_SmartZones_Source_GW_SmartZones_SmartZone_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
