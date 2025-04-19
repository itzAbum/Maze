#ifndef BN_SOUND_ITEMS_INFO_H
#define BN_SOUND_ITEMS_INFO_H

#include "bn_span.h"
#include "bn_sound_item.h"
#include "bn_string_view.h"

namespace bn::sound_items_info
{
    constexpr inline pair<sound_item, string_view> array[] = {
        make_pair(sound_item(16), string_view("diamond")),
        make_pair(sound_item(17), string_view("door_open")),
        make_pair(sound_item(18), string_view("explosion")),
        make_pair(sound_item(19), string_view("maze")),
        make_pair(sound_item(20), string_view("ping")),
        make_pair(sound_item(21), string_view("pong")),
    };

    constexpr inline span<const pair<sound_item, string_view>> span(array);
}

#endif

