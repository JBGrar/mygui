/*!
	@file
	@author		Albert Semenov
	@date		08/2010
*/
#ifndef __TEXTURE_CONTROL_H__
#define __TEXTURE_CONTROL_H__

#include "BaseLayout/BaseLayout.h"
#include "Property.h"
#include "SkinItem.h"
#include "AreaSelectorControl.h"
#include "PropertyAdvisor.h"
#include "SelectorControl.h"

namespace tools
{

	class TextureControl :
		public wraps::BaseLayout
	{
	public:
		TextureControl(MyGUI::Widget* _parent);
		virtual ~TextureControl();

	protected:
		void setTextureName(const MyGUI::UString& _value);
		const MyGUI::IntSize& getTextureSize();

		void setTextureRegion(const MyGUI::IntCoord& _value);
		const MyGUI::IntCoord& getTextureRegion();

		template<typename T>
		void addSelectorControl(T * & _control)
		{
			assignBase(_control, "Texture");
			mSelectors.push_back(_control);

			_control->setScale(mScaleValue);
		}

	private:
		void notifyComboChangePosition(MyGUI::ComboBox* _sender, size_t _index);

		void notifyChangePosition();

		void updateTexture();
		void updateCoord();

		void fillColours(MyGUI::ComboBox* _combo);
		void updateColour(MyGUI::ComboBox* _sender);

		void fillScale();
		void updateScale();

		void updateRegionCoord();

	private:
		MyGUI::ScrollView* mView;
		MyGUI::StaticImage* mTexture;
		MyGUI::ComboBox* mBackgroundColour;
		MyGUI::Widget* mBackground;
		MyGUI::ComboBox* mScale;

		double mScaleValue;
		MyGUI::IntSize mTextureSize;
		MyGUI::IntCoord mTextureRegion;

		std::vector<SelectorControl*> mSelectors;
	};

} // namespace tools

#endif // __TEXTURE_CONTROL_H__
