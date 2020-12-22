// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GW_SmartZones/GW_SmartZonesHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGW_SmartZonesHUD() {}
// Cross Module References
	GW_SMARTZONES_API UClass* Z_Construct_UClass_AGW_SmartZonesHUD_NoRegister();
	GW_SMARTZONES_API UClass* Z_Construct_UClass_AGW_SmartZonesHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_GW_SmartZones();
// End Cross Module References
	void AGW_SmartZonesHUD::StaticRegisterNativesAGW_SmartZonesHUD()
	{
	}
	UClass* Z_Construct_UClass_AGW_SmartZonesHUD_NoRegister()
	{
		return AGW_SmartZonesHUD::StaticClass();
	}
	struct Z_Construct_UClass_AGW_SmartZonesHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGW_SmartZonesHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_GW_SmartZones,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGW_SmartZonesHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "GW_SmartZonesHUD.h" },
		{ "ModuleRelativePath", "GW_SmartZonesHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGW_SmartZonesHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGW_SmartZonesHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGW_SmartZonesHUD_Statics::ClassParams = {
		&AGW_SmartZonesHUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGW_SmartZonesHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGW_SmartZonesHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGW_SmartZonesHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGW_SmartZonesHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGW_SmartZonesHUD, 1982957382);
	template<> GW_SMARTZONES_API UClass* StaticClass<AGW_SmartZonesHUD>()
	{
		return AGW_SmartZonesHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGW_SmartZonesHUD(Z_Construct_UClass_AGW_SmartZonesHUD, &AGW_SmartZonesHUD::StaticClass, TEXT("/Script/GW_SmartZones"), TEXT("AGW_SmartZonesHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGW_SmartZonesHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
