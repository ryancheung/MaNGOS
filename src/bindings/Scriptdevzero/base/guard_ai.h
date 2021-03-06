/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_GUARDAI_H
#define SC_GUARDAI_H

enum
{
    GENERIC_CREATURE_COOLDOWN       = 5000
};

struct MANGOS_DLL_DECL guardAI : public ScriptedAI
{
    public:
        explicit guardAI(Creature* pCreature);
        ~guardAI() {}

        uint32 m_uiGlobalCooldown;                          // This variable acts like the global cooldown that players have (1.5 seconds)
        uint32 m_uiBuffTimer;                               // This variable keeps track of buffs

        void Reset();

        void JustDied(Unit *pKiller);

        void UpdateAI(const uint32 uiDiff);

        // Commonly used for guards in main cities
        void DoReplyToTextEmote(uint32 uiTextEmote);
};

struct MANGOS_DLL_DECL guardAI_orgrimmar : public guardAI
{
    guardAI_orgrimmar(Creature* pCreature) : guardAI(pCreature) {}

    void ReceiveEmote(Player* pPlayer, uint32 uiTextEmote);
};

struct MANGOS_DLL_DECL guardAI_stormwind : public guardAI
{
    guardAI_stormwind(Creature* pCreature) : guardAI(pCreature) {}

    void ReceiveEmote(Player* pPlayer, uint32 uiTextEmote);
};

#endif
