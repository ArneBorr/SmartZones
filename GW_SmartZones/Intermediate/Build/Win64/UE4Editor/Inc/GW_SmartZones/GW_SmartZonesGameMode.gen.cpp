// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GW_SmartZones/GW_SmartZonesGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGW_SmartZonesGameMode() {}
// Cross Module References
	GW_SMARTZONES_API UClass* Z_Construct_UClass_AGW_SmartZonesGameMode_NoRegister();
	GW_SMARTZONES_API UClass* Z_Construct_UClass_AGW_SmartZonesGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GW_SmartZones();
// End Cross Module References
	void AGW_SmartZonesGameMode::StaticRegisterNativesAGW_SmartZonesGameMode()
	{
	}
	UClass* Z_Construct_UClass_AGW_SmartZonesGameMode_NoRegister()
	{
		return AGW_SmartZonesGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGW_SmartZonesGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GW_SmartZones,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GW_SmartZonesGameMode.h" },
		{ "ModuleRelativePath", "GW_SmartZonesGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGW_SmartZonesGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::ClassParams = {
		&AGW_SmartZonesGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGW_SmartZonesGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGW_SmartZonesGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGW_SmartZonesGameMode, 1588744950);
	template<> GW_SMARTZONES_API UClass* StaticClass<AGW_SmartZonesGameMode>()
	{
		return AGW_SmartZonesGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGW_SmartZonesGameMode(Z_Construct_UClass_AGW_SmartZonesGameMode, &AGW_SmartZonesGameMode::StaticClass, TEXT("/Script/GW_SmartZones"), TEXT("AGW_SmartZonesGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGW_SmartZonesGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
