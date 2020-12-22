// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GW_SMARTZONES_GW_SmartZonesProjectile_generated_h
#error "GW_SmartZonesProjectile.generated.h already included, missing '#pragma once' in GW_SmartZonesProjectile.h"
#endif
#define GW_SMARTZONES_GW_SmartZonesProjectile_generated_h

#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_SPARSE_DATA
#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGW_SmartZonesProjectile(); \
	friend struct Z_Construct_UClass_AGW_SmartZonesProjectile_Statics; \
public: \
	DECLARE_CLASS(AGW_SmartZonesProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GW_SmartZones"), NO_API) \
	DECLARE_SERIALIZER(AGW_SmartZonesProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGW_SmartZonesProjectile(); \
	friend struct Z_Construct_UClass_AGW_SmartZonesProjectile_Statics; \
public: \
	DECLARE_CLASS(AGW_SmartZonesProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GW_SmartZones"), NO_API) \
	DECLARE_SERIALIZER(AGW_SmartZonesProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGW_SmartZonesProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGW_SmartZonesProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGW_SmartZonesProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGW_SmartZonesProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGW_SmartZonesProjectile(AGW_SmartZonesProjectile&&); \
	NO_API AGW_SmartZonesProjectile(const AGW_SmartZonesProjectile&); \
public:


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGW_SmartZonesProjectile(AGW_SmartZonesProjectile&&); \
	NO_API AGW_SmartZonesProjectile(const AGW_SmartZonesProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGW_SmartZonesProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGW_SmartZonesProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGW_SmartZonesProjectile)


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AGW_SmartZonesProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AGW_SmartZonesProjectile, ProjectileMovement); }


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_12_PROLOG
#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_SPARSE_DATA \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_RPC_WRAPPERS \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_INCLASS \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_SPARSE_DATA \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_INCLASS_NO_PURE_DECLS \
	GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GW_SMARTZONES_API UClass* StaticClass<class AGW_SmartZonesProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GW_SmartZones_Source_GW_SmartZones_GW_SmartZonesProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
