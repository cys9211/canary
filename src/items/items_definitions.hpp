/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2024 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#pragma once

class Imbuement;

// Enums
enum ItemProperty {
	CONST_PROP_BLOCKSOLID = 0,
	CONST_PROP_HASHEIGHT,
	CONST_PROP_BLOCKPROJECTILE,
	CONST_PROP_BLOCKPATH,
	CONST_PROP_ISVERTICAL,
	CONST_PROP_ISHORIZONTAL,
	CONST_PROP_MOVABLE,
	CONST_PROP_IMMOVABLEBLOCKSOLID,
	CONST_PROP_IMMOVABLEBLOCKPATH,
	CONST_PROP_IMMOVABLENOFIELDBLOCKPATH,
	CONST_PROP_NOFIELDBLOCKPATH,
	CONST_PROP_SUPPORTHANGABLE,
};

enum Attr_ReadValue {
	ATTR_READ_CONTINUE,
	ATTR_READ_ERROR,
	ATTR_READ_END,
};

enum ReturnValue {
	RETURNVALUE_NOERROR,
	RETURNVALUE_NOTBOUGHTINSTORE,
	RETURNVALUE_ITEMCANNOTBEMOVEDTHERE,
	RETURNVALUE_ITEMCANNOTBEMOVEDPOUCH,
	RETURNVALUE_NOTPOSSIBLE,
	RETURNVALUE_NOTENOUGHROOM,
	RETURNVALUE_PLAYERISPZLOCKED,
	RETURNVALUE_PLAYERISNOTINVITED,
	RETURNVALUE_CANNOTTHROW,
	RETURNVALUE_THEREISNOWAY,
	RETURNVALUE_DESTINATIONOUTOFREACH,
	RETURNVALUE_CREATUREBLOCK,
	RETURNVALUE_NOTMOVABLE,
	RETURNVALUE_DROPTWOHANDEDITEM,
	RETURNVALUE_BOTHHANDSNEEDTOBEFREE,
	RETURNVALUE_CANONLYUSEONEWEAPON,
	RETURNVALUE_NEEDEXCHANGE,
	RETURNVALUE_CANNOTBEDRESSED,
	RETURNVALUE_PUTTHISOBJECTINYOURHAND,
	RETURNVALUE_PUTTHISOBJECTINBOTHHANDS,
	RETURNVALUE_TOOFARAWAY,
	RETURNVALUE_FIRSTGODOWNSTAIRS,
	RETURNVALUE_FIRSTGOUPSTAIRS,
	RETURNVALUE_CONTAINERNOTENOUGHROOM,
	RETURNVALUE_ONLYAMMOINQUIVER,
	RETURNVALUE_NOTENOUGHCAPACITY,
	RETURNVALUE_CANNOTPICKUP,
	RETURNVALUE_THISISIMPOSSIBLE,
	RETURNVALUE_DEPOTISFULL,
	RETURNVALUE_CONTAINERISFULL,
	RETURNVALUE_CREATUREDOESNOTEXIST,
	RETURNVALUE_CANNOTUSETHISOBJECT,
	RETURNVALUE_PLAYERWITHTHISNAMEISNOTONLINE,
	RETURNVALUE_NOTREQUIREDLEVELTOUSERUNE,
	RETURNVALUE_YOUAREALREADYTRADING,
	RETURNVALUE_THISPLAYERISALREADYTRADING,
	RETURNVALUE_YOUMAYNOTLOGOUTDURINGAFIGHT,
	RETURNVALUE_DIRECTPLAYERSHOOT,
	RETURNVALUE_NOTENOUGHLEVEL,
	RETURNVALUE_NOTENOUGHMAGICLEVEL,
	RETURNVALUE_NOTENOUGHMANA,
	RETURNVALUE_NOTENOUGHSOUL,
	RETURNVALUE_YOUAREEXHAUSTED,
	RETURNVALUE_YOUCANNOTUSEOBJECTSTHATFAST,
	RETURNVALUE_PLAYERISNOTREACHABLE,
	RETURNVALUE_CANONLYUSETHISRUNEONCREATURES,
	RETURNVALUE_ACTIONNOTPERMITTEDINPROTECTIONZONE,
	RETURNVALUE_YOUMAYNOTATTACKTHISPLAYER,
	RETURNVALUE_YOUMAYNOTATTACKAPERSONINPROTECTIONZONE,
	RETURNVALUE_YOUMAYNOTATTACKAPERSONWHILEINPROTECTIONZONE,
	RETURNVALUE_YOUMAYNOTATTACKTHISCREATURE,
	RETURNVALUE_YOUCANONLYUSEITONCREATURES,
	RETURNVALUE_CREATUREISNOTREACHABLE,
	RETURNVALUE_TURNSECUREMODETOATTACKUNMARKEDPLAYERS,
	RETURNVALUE_YOUNEEDPREMIUMACCOUNT,
	RETURNVALUE_YOUNEEDTOLEARNTHISSPELL,
	RETURNVALUE_YOURVOCATIONCANNOTUSETHISSPELL,
	RETURNVALUE_YOUNEEDAWEAPONTOUSETHISSPELL,
	RETURNVALUE_PLAYERISPZLOCKEDLEAVEPVPZONE,
	RETURNVALUE_PLAYERISPZLOCKEDENTERPVPZONE,
	RETURNVALUE_ACTIONNOTPERMITTEDINANOPVPZONE,
	RETURNVALUE_YOUCANNOTLOGOUTHERE,
	RETURNVALUE_YOUNEEDAMAGICITEMTOCASTSPELL,
	RETURNVALUE_CANNOTCONJUREITEMHERE,
	RETURNVALUE_YOUNEEDTOSPLITYOURSPEARS,
	RETURNVALUE_NAMEISTOOAMBIGUOUS,
	RETURNVALUE_CANONLYUSEONESHIELD,
	RETURNVALUE_NOPARTYMEMBERSINRANGE,
	RETURNVALUE_YOUARENOTTHEOWNER,
	RETURNVALUE_YOUCANTOPENCORPSEADM,
	RETURNVALUE_NOSUCHRAIDEXISTS,
	RETURNVALUE_ANOTHERRAIDISALREADYEXECUTING,
	RETURNVALUE_TRADEPLAYERFARAWAY,
	RETURNVALUE_YOUDONTOWNTHISHOUSE,
	RETURNVALUE_TRADEPLAYERALREADYOWNSAHOUSE,
	RETURNVALUE_TRADEPLAYERHIGHESTBIDDER,
	RETURNVALUE_YOUCANNOTTRADETHISHOUSE,
	RETURNVALUE_YOUDONTHAVEREQUIREDPROFESSION,
	RETURNVALUE_NOTENOUGHFISTLEVEL,
	RETURNVALUE_NOTENOUGHCLUBLEVEL,
	RETURNVALUE_NOTENOUGHSWORDLEVEL,
	RETURNVALUE_NOTENOUGHAXELEVEL,
	RETURNVALUE_NOTENOUGHDISTANCELEVEL,
	RETURNVALUE_NOTENOUGHSHIELDLEVEL,
	RETURNVALUE_NOTENOUGHFISHLEVEL,
	RETURNVALUE_REWARDCHESTISEMPTY,
	RETURNVALUE_REWARDCONTAINERISEMPTY,
	RETURNVALUE_CONTACTADMINISTRATOR,
	RETURNVALUE_ITEMISNOTYOURS,
	RETURNVALUE_ITEMUNTRADEABLE,
};

enum ItemGroup_t {
	ITEM_GROUP_NONE,

	ITEM_GROUP_GROUND,
	ITEM_GROUP_CONTAINER,
	ITEM_GROUP_SPLASH,
	ITEM_GROUP_FLUID,

	ITEM_GROUP_LAST
};

enum ItemTypes_t {
	ITEM_TYPE_NONE,

	// Odered to make the cast from protobuf::itemCategory to ItemTypes_t easier.
	// Do not edit it from Start-End
	// Start
	ITEM_TYPE_ARMOR,
	ITEM_TYPE_AMULET,
	ITEM_TYPE_BOOTS,
	ITEM_TYPE_CONTAINER,
	ITEM_TYPE_DECORATION,
	ITEM_TYPE_FOOD,
	ITEM_TYPE_HELMET,
	ITEM_TYPE_LEGS,
	ITEM_TYPE_OTHER,
	ITEM_TYPE_POTION,
	ITEM_TYPE_RING,
	ITEM_TYPE_RUNE,
	ITEM_TYPE_SHIELD,
	ITEM_TYPE_TOOLS,
	ITEM_TYPE_VALUABLE,
	ITEM_TYPE_AMMO,
	ITEM_TYPE_AXE,
	ITEM_TYPE_CLUB,
	ITEM_TYPE_DISTANCE,
	ITEM_TYPE_SWORD,
	ITEM_TYPE_WAND,
	ITEM_TYPE_PREMIUMSCROLL,
	ITEM_TYPE_TIBIACOIN,
	ITEM_TYPE_CREATUREPRODUCT,
	ITEM_TYPE_QUIVER,
	// End

	ITEM_TYPE_DEPOT,
	ITEM_TYPE_MAILBOX,
	ITEM_TYPE_TRASHHOLDER,
	ITEM_TYPE_DOOR,
	ITEM_TYPE_MAGICFIELD,
	ITEM_TYPE_TELEPORT,
	ITEM_TYPE_BED,
	ITEM_TYPE_KEY,
	ITEM_TYPE_SUPPLY,
	ITEM_TYPE_REWARDCHEST,
	ITEM_TYPE_CARPET,
	ITEM_TYPE_RETRIEVE,
	ITEM_TYPE_GOLD,
	ITEM_TYPE_UNASSIGNED,

	// Other types
	ITEM_TYPE_LADDER,
	ITEM_TYPE_DUMMY,

	ITEM_TYPE_LAST,
};

enum TradeEvents_t {
	ON_TRADE_TRANSFER,
	ON_TRADE_CANCEL,
};

enum AttrTypes_t {
	// ATTR_NONE = 0 (last enum)
	ATTR_STORE = 1,
	// ATTR_EXT_FILE = 2,
	ATTR_TILE_FLAGS = 3,
	ATTR_ACTION_ID = 4,
	ATTR_UNIQUE_ID = 5,
	ATTR_TEXT = 6,
	ATTR_DESC = 7,
	ATTR_TELE_DEST = 8,
	ATTR_ITEM = 9,
	ATTR_DEPOT_ID = 10,
	// ATTR_EXT_SPAWN_FILE = 11,
	ATTR_RUNE_CHARGES = 12,
	// ATTR_EXT_HOUSE_FILE = 13,
	ATTR_HOUSEDOORID = 14,
	ATTR_COUNT = 15,
	ATTR_DURATION = 16,
	ATTR_DECAYING_STATE = 17,
	ATTR_WRITTENDATE = 18,
	ATTR_WRITTENBY = 19,
	ATTR_SLEEPERGUID = 20,
	ATTR_SLEEPSTART = 21,
	ATTR_CHARGES = 22,
	ATTR_CONTAINER_ITEMS = 23,
	ATTR_NAME = 24,
	ATTR_ARTICLE = 25,
	ATTR_PLURALNAME = 26,
	ATTR_WEIGHT = 27,
	ATTR_ATTACK = 28,
	ATTR_DEFENSE = 29,
	ATTR_EXTRADEFENSE = 30,
	ATTR_ARMOR = 31,
	ATTR_HITCHANCE = 32,
	ATTR_SHOOTRANGE = 33,
	ATTR_SPECIAL = 34,
	ATTR_IMBUEMENT_SLOT = 35,
	ATTR_OPENCONTAINER = 36,
	ATTR_CUSTOM_ATTRIBUTES = 37, // Deprecated (override by ATTR_CUSTOM)
	ATTR_QUICKLOOTCONTAINER = 38,
	ATTR_AMOUNT = 39,
	ATTR_TIER = 40,
	ATTR_CUSTOM = 41,
	ATTR_STORE_INBOX_CATEGORY = 42,
	ATTR_OWNER = 43,
	ATTR_OBTAINCONTAINER = 44,

	// Always the last
	ATTR_NONE = 0
};

enum ImbuementTypes_t : int64_t {
	IMBUEMENT_NONE = -1,
	IMBUEMENT_ELEMENTAL_DAMAGE = 0,
	IMBUEMENT_LIFE_LEECH = 1,
	IMBUEMENT_MANA_LEECH = 2,
	IMBUEMENT_CRITICAL_HIT = 3,
	IMBUEMENT_ELEMENTAL_PROTECTION_DEATH = 4,
	IMBUEMENT_ELEMENTAL_PROTECTION_EARTH = 5,
	IMBUEMENT_ELEMENTAL_PROTECTION_FIRE = 6,
	IMBUEMENT_ELEMENTAL_PROTECTION_ICE = 7,
	IMBUEMENT_ELEMENTAL_PROTECTION_ENERGY = 8,
	IMBUEMENT_ELEMENTAL_PROTECTION_HOLY = 9,
	IMBUEMENT_INCREASE_SPEED = 10,
	IMBUEMENT_SKILLBOOST_AXE = 11,
	IMBUEMENT_SKILLBOOST_SWORD = 12,
	IMBUEMENT_SKILLBOOST_CLUB = 13,
	IMBUEMENT_SKILLBOOST_SHIELDING = 14,
	IMBUEMENT_SKILLBOOST_DISTANCE = 15,
	IMBUEMENT_SKILLBOOST_MAGIC_LEVEL = 16,
	IMBUEMENT_INCREASE_CAPACITY = 17
};

enum AugmentTypes_t : uint8_t {
	AUGMENT_NONE,
	AUGMENT_POWERFUL_IMPACT,
	AUGMENT_STRONG_IMPACT,
	AUGMENT_INCREASED_DAMAGE,
	AUGMENT_COOLDOWN,
	AUGMENT_CRITICALHITDAMAGE,
	AUGMENT_LIFELEECHAMOUNT,
	AUGMENT_MANALEECHAMOUNT
};

enum class ContainerCategory_t : uint8_t {
	All,
	Ammunition,
	AmuletsAndNecklaces,
	Animals,
	Annelids,
	Arachnids,
	Armors,
	ArtificialTiles,
	AstralShapers,
	AttackRunes,
	AxeWeapons,
	Bats,
	Bears,
	Birds,
	BlessingCharms,
	Blobs,
	Books,
	Boots,
	Bushes,
	Cactuses,
	Canines,
	Casks,
	Closets,
	ClothingAccessories,
	ClubWeapons,
	Coffins,
	Constructions,
	Containers,
	ContestPrizes,
	CreatureProducts,
	Decoration,
	Demons,
	DistanceWeapons,
	DocumentsAndPapers,
	DollsAndBears,
	Doors,
	Dragons,
	Dreamhaunters,
	Dropdowns,
	EnchantedItems,
	EventCreatures,
	ExerciseWeapons,
	FansiteItems,
	Ferns,
	Fields,
	Flags,
	FloorDecorations,
	FloraAndMinerals,
	Flowers,
	FluidContainers,
	Food,
	Furniture,
	GameTokens,
	Ghosts,
	Glires,
	Grass,
	HealingRunes,
	Helmets,
	HiveBorn,
	Illumination,
	Keys,
	KitchenTools,
	Ladders,
	Legs,
	LightSources,
	Liquids,
	MachinesObjects,
	Machines,
	MagicalItems,
	Metals,
	Mollusks,
	Mushrooms,
	MusicalInstruments,
	NaturalProducts,
	NaturalTiles,
	OtherItems,
	Outlaws,
	PaintingEquipment,
	PartyItems,
	Pillars,
	PlantsAndHerbs,
	Plants,
	Portals,
	QuestItems,
	QuestObjects,
	Quivers,
	Refuse,
	Remains,
	Rings,
	Rocks,
	Rods,
	Rubbish,
	Shields,
	ShrinesAndAltars,
	Signs,
	Skeletons,
	Spellbooks,
	Stairs,
	Statues,
	SupportRunes,
	SwordWeapons,
	Tables,
	TamingItems,
	Teleporters,
	ToolsObjects,
	Tools,
	TortureInstruments,
	TournamentRewards,
	TrainingWeapons,
	Transportation,
	Traps,
	Trees,
	Trophies,
	UndeadHumanoids,
	Ungulates,
	Utilities,
	Valuables,
	WallHangings,
	Walls,
	Wands,
	Windows
};

enum SlotPositionBits : uint32_t {
	SLOTP_WHEREEVER = 0xFFFFFFFF,
	SLOTP_HEAD = 1 << 0,
	SLOTP_NECKLACE = 1 << 1,
	SLOTP_BACKPACK = 1 << 2,
	SLOTP_ARMOR = 1 << 3,
	SLOTP_RIGHT = 1 << 4,
	SLOTP_LEFT = 1 << 5,
	SLOTP_LEGS = 1 << 6,
	SLOTP_FEET = 1 << 7,
	SLOTP_RING = 1 << 8,
	SLOTP_AMMO = 1 << 9,
	SLOTP_DEPOT = 1 << 10,
	SLOTP_TWO_HAND = 1 << 11,
	SLOTP_HAND = (SLOTP_LEFT | SLOTP_RIGHT)
};

enum TileFlags_t : uint32_t {
	TILESTATE_NONE = 0,

	TILESTATE_FLOORCHANGE_DOWN = 1 << 0,
	TILESTATE_FLOORCHANGE_NORTH = 1 << 1,
	TILESTATE_FLOORCHANGE_SOUTH = 1 << 2,
	TILESTATE_FLOORCHANGE_EAST = 1 << 3,
	TILESTATE_FLOORCHANGE_WEST = 1 << 4,
	TILESTATE_FLOORCHANGE_SOUTH_ALT = 1 << 5,
	TILESTATE_FLOORCHANGE_EAST_ALT = 1 << 6,
	TILESTATE_PROTECTIONZONE = 1 << 7,
	TILESTATE_NOPVPZONE = 1 << 8,
	TILESTATE_NOLOGOUT = 1 << 9,
	TILESTATE_PVPZONE = 1 << 10,
	TILESTATE_TELEPORT = 1 << 11,
	TILESTATE_MAGICFIELD = 1 << 12,
	TILESTATE_MAILBOX = 1 << 13,
	TILESTATE_TRASHHOLDER = 1 << 14,
	TILESTATE_BED = 1 << 15,
	TILESTATE_DEPOT = 1 << 16,
	TILESTATE_BLOCKSOLID = 1 << 17,
	TILESTATE_BLOCKPATH = 1 << 18,
	TILESTATE_IMMOVABLEBLOCKSOLID = 1 << 19,
	TILESTATE_IMMOVABLEBLOCKPATH = 1 << 20,
	TILESTATE_IMMOVABLENOFIELDBLOCKPATH = 1 << 21,
	TILESTATE_NOFIELDBLOCKPATH = 1 << 22,
	TILESTATE_SUPPORTS_HANGABLE = 1 << 23,
	TILESTATE_MOVABLE = 1 << 24,
	TILESTATE_ISHORIZONTAL = 1 << 25,
	TILESTATE_ISVERTICAL = 1 << 26,
	TILESTATE_BLOCKPROJECTILE = 1 << 27,
	TILESTATE_HASHEIGHT = 1 << 28,

	TILESTATE_FLOORCHANGE = TILESTATE_FLOORCHANGE_DOWN | TILESTATE_FLOORCHANGE_NORTH | TILESTATE_FLOORCHANGE_SOUTH | TILESTATE_FLOORCHANGE_EAST | TILESTATE_FLOORCHANGE_WEST | TILESTATE_FLOORCHANGE_SOUTH_ALT | TILESTATE_FLOORCHANGE_EAST_ALT,
};

enum ZoneType_t {
	ZONE_PROTECTION,
	ZONE_NOPVP,
	ZONE_PVP,
	ZONE_NOLOGOUT,
	ZONE_NORMAL,
};

enum CylinderFlags_t {
	FLAG_NOLIMIT = 1 << 0, // Bypass limits like capacity/container limits, blocking items/creatures etc.
	FLAG_IGNOREBLOCKITEM = 1 << 1, // Bypass movable blocking item checks
	FLAG_IGNOREBLOCKCREATURE = 1 << 2, // Bypass creature checks
	FLAG_CHILDISOWNER = 1 << 3, // Used by containers to query capacity of the carrier (player)
	FLAG_PATHFINDING = 1 << 4, // An additional check is done for floor changing/teleport items
	FLAG_IGNOREFIELDDAMAGE = 1 << 5, // Bypass field damage checks
	FLAG_IGNORENOTMOVABLE = 1 << 6, // Bypass check for mobility
	FLAG_IGNOREAUTOSTACK = 1 << 7, // queryDestination will not try to stack items together
};

enum CylinderLink_t {
	LINK_OWNER,
	LINK_PARENT,
	LINK_TOPPARENT,
	LINK_NEAR,
};

enum ItemParseAttributes_t {
	ITEM_PARSE_TYPE,
	ITEM_PARSE_DESCRIPTION,
	ITEM_PARSE_RUNESPELLNAME,
	ITEM_PARSE_WEIGHT,
	ITEM_PARSE_SHOWCOUNT,
	ITEM_PARSE_ARMOR,
	ITEM_PARSE_DEFENSE,
	ITEM_PARSE_EXTRADEF,
	ITEM_PARSE_ATTACK,
	ITEM_PARSE_ROTATETO,
	ITEM_PARSE_WRAPCONTAINER,
	ITEM_PARSE_IMBUEMENT,
	ITEM_PARSE_WRAPABLETO,
	ITEM_PARSE_MOVABLE,
	ITEM_PARSE_BLOCKPROJECTILE,
	ITEM_PARSE_PICKUPABLE,
	ITEM_PARSE_FLOORCHANGE,
	ITEM_PARSE_CONTAINERSIZE,
	ITEM_PARSE_FLUIDSOURCE,
	ITEM_PARSE_READABLE,
	ITEM_PARSE_WRITEABLE,
	ITEM_PARSE_MAXTEXTLEN,
	ITEM_PARSE_WRITEONCEITEMID,
	ITEM_PARSE_WEAPONTYPE,
	ITEM_PARSE_SLOTTYPE,
	ITEM_PARSE_AMMOTYPE,
	ITEM_PARSE_SHOOTTYPE,
	ITEM_PARSE_EFFECT,
	ITEM_PARSE_LOOTTYPE,
	ITEM_PARSE_RANGE,
	ITEM_PARSE_STOPDURATION,
	ITEM_PARSE_DECAYTO,
	ITEM_PARSE_TRANSFORMEQUIPTO,
	ITEM_PARSE_TRANSFORMDEEQUIPTO,
	ITEM_PARSE_DURATION,
	ITEM_PARSE_SHOWDURATION,
	ITEM_PARSE_CHARGES,
	ITEM_PARSE_SHOWCHARGES,
	ITEM_PARSE_SHOWATTRIBUTES,
	ITEM_PARSE_HITCHANCE,
	ITEM_PARSE_MAXHITCHANCE,
	ITEM_PARSE_INVISIBLE,
	ITEM_PARSE_SPEED,
	ITEM_PARSE_HEALTHGAIN,
	ITEM_PARSE_HEALTHTICKS,
	ITEM_PARSE_MANAGAIN,
	ITEM_PARSE_MANATICKS,
	ITEM_PARSE_MANASHIELD,
	ITEM_PARSE_SKILLSWORD,
	ITEM_PARSE_SKILLAXE,
	ITEM_PARSE_SKILLCLUB,
	ITEM_PARSE_SKILLDIST,
	ITEM_PARSE_SKILLFISH,
	ITEM_PARSE_SKILLSHIELD,
	ITEM_PARSE_SKILLFIST,
	ITEM_PARSE_CRITICALHITCHANCE,
	ITEM_PARSE_CRITICALHITDAMAGE,
	ITEM_PARSE_LIFELEECHCHANCE,
	ITEM_PARSE_LIFELEECHAMOUNT,
	ITEM_PARSE_MANALEECHCHANCE,
	ITEM_PARSE_MANALEECHAMOUNT,
	ITEM_PARSE_MAXHITPOINTS,
	ITEM_PARSE_MAXHITPOINTSPERCENT,
	ITEM_PARSE_MAXMANAPOINTS,
	ITEM_PARSE_MAXMANAPOINTSPERCENT,
	ITEM_PARSE_MAGICLEVELPOINTS,
	ITEM_PARSE_MAGICLEVELPOINTSPERCENT,
	ITEM_PARSE_FIELDABSORBPERCENTENERGY,
	ITEM_PARSE_FIELDABSORBPERCENTFIRE,
	ITEM_PARSE_FIELDABSORBPERCENTPOISON,
	ITEM_PARSE_ABSORBPERCENTALL,
	ITEM_PARSE_ABSORBPERCENTELEMENTS,
	ITEM_PARSE_ABSORBPERCENTMAGIC,
	ITEM_PARSE_ABSORBPERCENTENERGY,
	ITEM_PARSE_ABSORBPERCENTFIRE,
	ITEM_PARSE_ABSORBPERCENTPOISON,
	ITEM_PARSE_ABSORBPERCENTICE,
	ITEM_PARSE_ABSORBPERCENTHOLY,
	ITEM_PARSE_ABSORBPERCENTDEATH,
	ITEM_PARSE_ABSORBPERCENTLIFEDRAIN,
	ITEM_PARSE_ABSORBPERCENTMANADRAIN,
	ITEM_PARSE_ABSORBPERCENTDROWN,
	ITEM_PARSE_ABSORBPERCENTPHYSICAL,
	ITEM_PARSE_ABSORBPERCENTHEALING,
	ITEM_PARSE_SUPPRESSDRUNK,
	ITEM_PARSE_SUPPRESSENERGY,
	ITEM_PARSE_SUPPRESSFIRE,
	ITEM_PARSE_SUPPRESSPOISON,
	ITEM_PARSE_SUPPRESSDROWN,
	ITEM_PARSE_SUPPRESSPHYSICAL,
	ITEM_PARSE_SUPPRESSFREEZE,
	ITEM_PARSE_SUPPRESSDAZZLE,
	ITEM_PARSE_SUPPRESSCURSE,
	ITEM_PARSE_FIELD,
	ITEM_PARSE_REPLACEABLE,
	ITEM_PARSE_PARTNERDIRECTION,
	ITEM_PARSE_LEVELDOOR,
	ITEM_PARSE_MALETRANSFORMTO,
	ITEM_PARSE_FEMALETRANSFORMTO,
	ITEM_PARSE_BEDPART,
	ITEM_PARSE_BEDPARTOF,
	ITEM_PARSE_TRANSFORMONUSE,
	ITEM_PARSE_DESTROYTO,
	ITEM_PARSE_ELEMENTICE,
	ITEM_PARSE_ELEMENTEARTH,
	ITEM_PARSE_ELEMENTFIRE,
	ITEM_PARSE_ELEMENTENERGY,
	ITEM_PARSE_ELEMENTDEATH,
	ITEM_PARSE_ELEMENTHOLY,
	ITEM_PARSE_WALKSTACK,
	ITEM_PARSE_BLOCK_SOLID,
	ITEM_PARSE_ALLOWDISTREAD,
	ITEM_PARSE_STACKSIZE,
	// 12.72 modifiers
	ITEM_PARSE_DEATHMAGICLEVELPOINTS,
	ITEM_PARSE_ENERGYMAGICLEVELPOINTS,
	ITEM_PARSE_EARTHMAGICLEVELPOINTS,
	ITEM_PARSE_FIREMAGICLEVELPOINTS,
	ITEM_PARSE_ICEMAGICLEVELPOINTS,
	ITEM_PARSE_HEALINGMAGICLEVELPOINTS,
	ITEM_PARSE_HOLYMAGICLEVELPOINTS,
	ITEM_PARSE_PHYSICALMAGICLEVELPOINTS,
	ITEM_PARSE_MAGICSHIELDCAPACITYPERCENT,
	ITEM_PARSE_MAGICSHIELDCAPACITYFLAT,
	ITEM_PARSE_PERFECTSHOTDAMAGE,
	ITEM_PARSE_PERFECTSHOTRANGE,
	ITEM_PARSE_CLEAVEPERCENT,
	ITEM_PARSE_REFLECTPERCENTALL,
	ITEM_PARSE_REFLECTDAMAGE,
	ITEM_PARSE_PRIMARYTYPE,
	ITEM_PARSE_USEDBYGUESTS,
	ITEM_PARSE_SCRIPT,
	ITEM_PARSE_AUGMENT,
};

struct ImbuementInfo {
	Imbuement* imbuement;
	uint32_t duration = 0;
};

struct AugmentInfo {
	AugmentInfo(std::string spellName, AugmentTypes_t type, uint16_t value) :
		spellName(std::move(spellName)), type(type), value(value) { }

	std::string spellName;
	AugmentTypes_t type;
	uint16_t value;
};

using Augments = std::list<AugmentInfo>;
