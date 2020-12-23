#pragma once

#include "CoreMinimal.h"
//#include <functional>

/*class ConditionBase
{
public: 
	ConditionBase(const FString& name);
	virtual ~ConditionBase() {};
	virtual bool Call() { return false; };

private:
	FString m_Name;
};

template< typename... args>
struct ConditionFunction
{
	explicit ConditionFunction(std::function<bool(args...)> f, args... ar) :
		Function(f), Arguments(std::tuple<args...>(ar...)) {}

	std::function<bool(args...)> Function;
	*///std::tuple<args...> Arguments;
//};

//template< typename... args>
//class Condition final : public ConditionBase, public ConditionFunction<bool, args...>
//{
//	Condition(std::function<bool(args...)> f, args... ar, const FString& name)
//		: ConditionBase(name), ConditionFunction(f, args) { }
//	
//	bool Call() override
//	{
//		return Function(std::get< std::index_sequence_for<args...>() >(Arguments)...);
//	}
//};

class ASmartZone;

class GW_SMARTZONES_API Condition final
{
public:
	Condition(TFunction<bool(ASmartZone*)> f, const FString& name) : m_Function(f), m_Name(name) {};

	bool IsTrue(ASmartZone* pSmartZone)
	{
		return m_Function(pSmartZone);
	}

	const FString& GetName() const { return m_Name; }

private:
	TFunction<bool(ASmartZone*)> m_Function;
	FString m_Name;
};


class GW_SMARTZONES_API ConditionRepository final
{
public:
	ConditionRepository();

	Condition* GetCondition(const FString& name) const;

private:
	TArray<Condition*> m_pConditions;
};
