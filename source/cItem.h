#pragma once

#include "Defines.h"
#include "BlockID.h"

namespace Json
{
	class Value;
};





// tolua_begin
class cItem
{
public:
	cItem( ENUM_ITEM_ID a_ItemID = E_ITEM_EMPTY, char a_ItemCount = 0, short a_ItemHealth = 0 )
		: m_ItemID		( a_ItemID )
		, m_ItemCount	( a_ItemCount )
		, m_ItemHealth	( a_ItemHealth )
	{
		if(!IsValidItem( m_ItemID ) ) m_ItemID = E_ITEM_EMPTY;
	}
	void Empty()
	{
		m_ItemID = E_ITEM_EMPTY;
		m_ItemCount = 0;
		m_ItemHealth = 0;
	}
	void Clear(void)
	{
		m_ItemID = E_ITEM_EMPTY;
		m_ItemCount = 0;
		m_ItemHealth = 0;
	}
	bool IsEmpty(void) const
	{
		return (m_ItemID <= 0 || m_ItemCount <= 0);
	}
	bool Equals( cItem & a_Item ) const
	{
		return ( (m_ItemID == a_Item.m_ItemID) && (m_ItemHealth == a_Item.m_ItemHealth) );
	}

	// TODO Sorry for writing the functions in the header. But somehow it doesn�t worked when I put them into the cpp File :s

	inline int GetMaxDuration(void) const
	{
		switch(m_ItemID)
		{
			case 256: return 251;
			case 257: return 251;
			case 258: return 251;
			case 259: return 65;	//Lighter / Flint and Steel
			case 267: return 251;
			case 268: return 60;
			case 269: return 60;
			case 270: return 60;
			case 271: return 60;
			case 272: return 132;
			case 273: return 132;
			case 274: return 132;
			case 275: return 132;
			case 276: return 1563;
			case 277: return 1563;
			case 278: return 1563;
			case 279: return 1563;
			case 283: return 32;
			case 284: return 32;
			case 285: return 32;
			case 286: return 32;
			case 290: return 60;
			case 291: return 132;
			case 292: return 251;
			case 293: return 1563;
			case 294: return 32;
			case 359: return 251;
			default: return 0;
		}
	}

	// Damages a weapon / tool. Returns true when destroyed
	inline bool DamageItem()
	{
		if (HasDuration())
		{
			m_ItemHealth++;
			if(m_ItemHealth >= GetMaxDuration())
				return true;
		}
		return false;
	}

	inline bool HasDuration() { return GetMaxDuration() > 0; }

	// tolua_end
	void GetJson( Json::Value & a_OutValue ) const;
	void FromJson( const Json::Value & a_Value );
	// tolua_begin
	
	static bool IsEnchantable(ENUM_ITEM_ID item);

	ENUM_ITEM_ID m_ItemID;
	char         m_ItemCount;
	short        m_ItemHealth;

};
// tolua_end

typedef std::vector<cItem> cItems;




