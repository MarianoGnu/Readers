/* !!!! GENERATED FILE - DO NOT EDIT !!!!
 * --------------------------------------
 *
 * This file is part of liblcf. Copyright (c) 2018 liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#ifndef LCF_RPG_SAVEVEHICLELOCATION_H
#define LCF_RPG_SAVEVEHICLELOCATION_H

// Headers
#include "rpg_savemapeventbase.h"
#include <stdint.h>
#include <string>
#include "enum_tags.h"

/**
 * RPG::SaveVehicleLocation class.
 */
namespace RPG {
	class SaveVehicleLocation : public SaveMapEventBase {
	public:
		enum VehicleType {
			VehicleType_none = 0,
			VehicleType_skiff = 1,
			VehicleType_ship = 2,
			VehicleType_airship = 3
		};
		static constexpr auto kVehicleTypeTags = makeEnumTags<VehicleType>(
			"none",
			"skiff",
			"ship",
			"airship"
		);

		int32_t vehicle = 0;
		int32_t original_move_route_index = 0;
		int32_t remaining_ascent = 0;
		int32_t remaining_descent = 0;
		std::string sprite2_name;
		int32_t sprite2_id = 0;
	};
}

#endif
