#pragma once
#include <SceneManager.h>
#include "MasterControl.h"


/// ???b?N?A?b?v?V?[??
class LookupScene :public IScene
{
public:

	LookupScene(ISceneChanger* sceneChanger);

	///
	/// @fn bool init()
	/// @brief ???b?N?A?b?v?V?[??????????????B?O??V?[????????n???????????BArduino??setup???????p
	/// @retval true ????
	/// @retval false ???s
	///
	bool init()override;

	///
	/// @fn bool run()
	/// @brief ???b?N?A?b?v?V?[???????s????Binit()?????????B
	/// @retval true ????
	/// @retval false ???s
	///
	bool run()override;
};