#ifndef BITCOIN_EVO_DMN_TYPES_H
#define BITCOIN_EVO_DMN_TYPES_H

#include <amount.h>

#include <limits>
#include <string_view>

enum class MnType : uint16_t {
    Regular = 0,
    Evo = 1,
    COUNT,
    Invalid = std::numeric_limits<uint16_t>::max(),
};

template<typename T> struct is_serializable_enum;
template<> struct is_serializable_enum<MnType> : std::true_type {};

namespace dmn_types {

struct mntype_struct
{
    const int32_t voting_weight;
    const std::string_view description;
};

constexpr auto Regular = mntype_struct{
    .voting_weight = 1,
    .description = "Regular",
};
constexpr auto Evo = mntype_struct{
    .voting_weight = 4,
    .description = "Evo",
};
constexpr auto Invalid = mntype_struct{
    .voting_weight = 0,
    .description = "Invalid",
};

[[nodiscard]] static constexpr CAmount GetCollateralAmount(MnType type, int32_t current_height)
{
    switch (type) {
        case MnType::Regular:
            return (current_height < 271000) ? 3000 * COIN : 6000 * COIN;
        case MnType::Evo:
            return (current_height < 271000) ? 12000 * COIN : 24000 * COIN;
        default:
            return MAX_MONEY; // Invalid
    }
}


[[nodiscard]] static constexpr bool IsCollateralAmount(CAmount amount, int32_t current_height)
{
    return amount == GetCollateralAmount(MnType::Regular, current_height) ||
        amount == GetCollateralAmount(MnType::Evo, current_height);
}

} // namespace dmn_types

[[nodiscard]] constexpr const dmn_types::mntype_struct GetMnType(MnType type)
{
    switch (type) {
        case MnType::Regular: return dmn_types::Regular;
        case MnType::Evo: return dmn_types::Evo;
        default: return dmn_types::Invalid;
    }
}

[[nodiscard]] constexpr const bool IsValidMnType(MnType type)
{
    return type < MnType::COUNT;
}


#endif // BITCOIN_EVO_DMN_TYPES_H
