#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

#include "driver.h"
#include "utils.h"
#include "ROL.h"

auto retaddr = 0;

auto main( ) -> std::int32_t
{
	driver->initialize( utils::get_process_id( L"RainbowSix.exe" ) );
	const auto base = driver->get_module_base( "RainbowSix.exe" );

	
	//const auto game_manager = __ROL8__(driver->read<std::uintptr_t>(retaddr >> 0x21) ^ (base + 0x72B2960) ^ 0x6A50F193CC31AFA3i64, 0);
	const auto game_manager = __ROL8__(driver->read<std::uintptr_t>(retaddr >> 0x21) ^ (base + 0x72B2960) ^ 0x6A50F193CC31AFA3i64 ^ 0x7838897B8075ACD0i64 & 4, 0);

	while ( true )
	{
		// Entitylist
		
		const auto list = __ROL8__((driver->read<std::uintptr_t>(game_manager + 0x3F0) ^ 0xC) - 0x6F81A3C183B65EE6i64, 0x3E);
		const auto count = static_cast<std::uintptr_t>(__ROL8__((driver->read<std::uintptr_t>(game_manager + 0x3F8) ^ 0xC) - 0x64F4D4C11A089B16i64, 0x3E)) & 0x3FFFFFFF;

		for ( auto i = 0u; i < count; ++i )
		{
			// Entityloop

			
			const auto entity = driver->read<std::uintptr_t>( list + ( i * 0x08 ) );
			const auto pawn = ( ( driver->read<std::uintptr_t>(entity + 0xE8), 0x1C) ^ 0x1381EFE155D98A6Di64);
			const auto actor = ( ( driver->read<std::uintptr_t>(pawn + 0x18i64 ) ^ 0x9ED30F7C034359D0ui64));

		
			
				
				const auto glow_component = __ROL8__( driver->read<std::uintptr_t>(actor + 0x1C8) ^ 0xB24A745E678BCBB8ui64 - 0x7B, 0x3E); 
				driver->write<std::uintptr_t>(glow_component + 0xB0, 0x20748000000300); //Glow overwrite idk about that shit
				
		}
		

		std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) ); 
	}
}
