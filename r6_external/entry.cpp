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


auto main( ) -> std::int32_t
{
	


	driver->initialize(utils::get_process_id(L"RainbowSix.exe"));
	const auto base = driver->get_module_base("RainbowSix.exe");
	const auto retaddr = driver->get_module_base("RainbowSix.exe");



	auto game_manager = __ROL8__(driver->read<uint64_t>(0x7559898), 0x1D);
	auto v9 = ((game_manager << 0x28) & 0xFF00000000000000ui64 | ((unsigned __int64)((unsigned __int16)game_manager & 0xFF00) << 0x10) | (unsigned __int8)game_manager | (game_manager >> 0x18) & 0xFF00000000i64 | (game_manager >> 8) & 0xFF0000000000i64 | (game_manager << 8) & 0xFF000000000000i64 | (game_manager >> 0x10) & 0xFFFF00);
	return game_manager;

	while ( true )
	{



		
		


		
		const auto list = __ROL8__(driver->read<std::uintptr_t>(game_manager + 0x70), 0x29);
		const auto count = __ROL8__(driver->read<std::uintptr_t>(game_manager + 0x78), 0x29) & 0x3FFFFFFF;

		for ( auto i = 0u; i < count; ++i )
		{
			// Entityloop

			
			const auto entity = driver->read<std::uintptr_t>( list + ( i * 0x08 ) );
			auto pawn = __ROL8__(driver->read<uint64_t>(entity + 0x100), 0x2C);
			auto v59 = ((pawn ^ 0xA99F67CC88CC3242ui64) >> 0x18) & 0xFF000000 | ((pawn^ 0xA99F67CC88CC3242ui64) << 0x10) & 0xFF000000000000i64 | (unsigned __int8)((unsigned __int16)((pawn ^ 0xA99F67CC88CC3242ui64) >> 0x20) >> 8) | ((pawn ^ 0xA99F67CC88CC3242ui64) << 0x38) | ((pawn ^ 0xA99F67CC88CC3242ui64) >> 0x18) & 0xFF00000000i64 | ((pawn ^ 0xA99F67CC88CC3242ui64) << 0x20) & 0xFF0000000000i64 | (unsigned int)((pawn ^ 0xA99F67CC88CC3242ui64) >> 8);
			const auto actor = ((driver->read<std::uintptr_t>  (pawn + +0x18), 0x1A));
		



		

		
			
				
				const auto glow_component = __ROL8__( driver->read<std::uintptr_t>(actor + 0x1C8) ^ 0x6971E32574178A69i64, 0x2B);
				driver->write<std::uintptr_t>(glow_component + 0xB0, 0x20748000000300); //needs update


				
		}
		

		std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) ); 
	}
}
