#pragma once
#include "MiniginPCH.h"
#include "RailComponent.h"
#include "MoveRailComponent.h"
#include "RenderComponent.h"


void LoadPickups(dae::Scene& scene, std::vector<std::shared_ptr<dae::GameObject>> Pickuppers)
{
	for (int i = 0; i < 185; i++)
	{
		auto Go = std::make_shared<dae::GameObject>();
		auto Texture = std::make_shared<TextureComponent>(Go);
		Texture->SetTexture("PickUpSmall.png");
		Texture->setWidthHeight(32.f, 24.f);
		Go->AddComponent(Texture);
		auto ren = std::make_shared<RenderComponent>(Go);
		Go->AddComponent(ren);
		auto pickUp = std::make_shared<PickupComponent>(Go);
		for (auto pickupper : Pickuppers)
		{
			pickUp->AddPickupper(pickupper);
		}
		pickUp->SetGO(Go);
		pickUp->SetRadius(24.f);

		switch (i)
		{
			//first row
		case 0:
			Go->SetPosition(36.f, 71.f);
			break;
		case 1:
			Go->SetPosition(72.f, 71.f);
			break;
		case 2:
			Go->SetPosition(108.f, 71.f);
			break;
		case 3:
			Go->SetPosition(144.f, 71.f);
			break;
		case 4:
			Go->SetPosition(180.f, 71.f);
			break;
		case 5:
			Go->SetPosition(216.f, 71.f);
			break;
		case 6:
			Go->SetPosition(252.f, 71.f);
			break;
		case 7:
			Go->SetPosition(288.f, 71.f);
			break;
		case 8:
			Go->SetPosition(360.f, 71.f);
			break;
		case 9:
			Go->SetPosition(396.f, 71.f);
			break;
		case 10:
			Go->SetPosition(432.f, 71.f);
			break;
		case 11:
			Go->SetPosition(468.f, 71.f);
			break;
		case 12:
			Go->SetPosition(504.f, 71.f);
			break;
		case 13:
			Go->SetPosition(540.f, 71.f);
			break;
		case 14:
			Go->SetPosition(576.f, 71.f);
			break;
		case 15:
			Go->SetPosition(612.f, 71.f);
			break;
			//second row
		case 16:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(36.f, 103.f);
			break;
		case 17:
			Go->SetPosition(144.f, 103.f);
			break;
		case 18:
			Go->SetPosition(288.f, 103.f);
			break;
		case 19:
			Go->SetPosition(360.f, 103.f);
			break;
		case 20:
			Go->SetPosition(504.f, 103.f);
			break;
		case 21:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(612.f, 103.f);
			break;
			//third row
		case 22:
			Go->SetPosition(36.f, 135.f);
			break;
		case 23:
			Go->SetPosition(144.f, 135.f);
			break;
		case 24:
			Go->SetPosition(288.f, 135.f);
			break;
		case 25:
			Go->SetPosition(360.f, 135.f);
			break;
		case 26:
			Go->SetPosition(504.f, 135.f);
			break;
		case 27:
			Go->SetPosition(612.f, 135.f);
			break;
			//fourth row
		case 29:
			Go->SetPosition(36.f, 167.f);
			break;
		case 30:
			Go->SetPosition(72.f, 167.f);
			break;
		case 31:
			Go->SetPosition(108.f, 167.f);
			break;
		case 32:
			Go->SetPosition(144.f, 167.f);
			break;
		case 33:
			Go->SetPosition(180.f, 167.f);
			break;
		case 34:
			Go->SetPosition(216.f, 167.f);
			break;
		case 35:
			Go->SetPosition(252.f, 167.f);
			break;
		case 36:
			Go->SetPosition(288.f, 167.f);
			break;
		case 37:
			Go->SetPosition(360.f, 167.f);
			break;
		case 38:
			Go->SetPosition(396.f, 167.f);
			break;
		case 39:
			Go->SetPosition(432.f, 167.f);
			break;
		case 40:
			Go->SetPosition(468.f, 167.f);
			break;
		case 41:
			Go->SetPosition(504.f, 167.f);
			break;
		case 42:
			Go->SetPosition(540.f, 167.f);
			break;
		case 43:
			Go->SetPosition(576.f, 167.f);
			break;
		case 44:
			Go->SetPosition(612.f, 167.f);
			break;
		case 46:
			Go->SetPosition(324.f, 167.f);
			break;
			//fifth row
		case 47:
			Go->SetPosition(36.f, 199.f);
			break;
		case 48:
			Go->SetPosition(144.f, 199.f);
			break;
		case 49:
			Go->SetPosition(216.f, 199.f);
			break;
		case 50:
			Go->SetPosition(432.f, 199.f);
			break;
		case 51:
			Go->SetPosition(504.f, 199.f);
			break;
		case 52:
			Go->SetPosition(612.f, 199.f);
			break;
			//sixth row
		case 53:
			Go->SetPosition(36.f, 231.f);
			break;
		case 54:
			Go->SetPosition(144.f, 231.f);
			break;
		case 55:
			Go->SetPosition(216.f, 231.f);
			break;
		case 56:
			Go->SetPosition(432.f, 230.f);
			break;
		case 57:
			Go->SetPosition(504.f, 231.f);
			break;
		case 58:
			Go->SetPosition(612.f, 231.f);
			break;
		case 59:
			Go->SetPosition(72.f, 231.f);
			break;
		case 60:
			Go->SetPosition(108.f, 231.f);
			break;
		case 61:
			Go->SetPosition(288.f, 231.f);
			break;
		case 62:
			Go->SetPosition(360.f, 231.f);
			break;
		case 63:
			Go->SetPosition(396.f, 231.f);
			break;
		case 64:
			Go->SetPosition(540.f, 231.f);
			break;
		case 65:
			Go->SetPosition(576.f, 231.f);
			break;
		case 67:
			Go->SetPosition(252.f, 231.f);
			break;
			//seventh row
		case 68:
			Go->SetPosition(144.f, 263.f);
			break;
		case 69:
			Go->SetPosition(288.f, 263.f);
			break;
		case 70:
			Go->SetPosition(360.f, 263.f);
			break;
		case 71:
			Go->SetPosition(504.f, 263.f);
			break;
			//eight row
		case 72:
			Go->SetPosition(144.f, 300.f);
			break;
		case 73:
			Go->SetPosition(216.f, 300.f);
			break;
		case 74:
			Go->SetPosition(252.f, 300.f);
			break;
		case 75:
			Go->SetPosition(288.f, 300.f);
			break;
		case 76:
			Go->SetPosition(360.f, 300.f);
			break;
		case 77:
			Go->SetPosition(396.f, 300.f);
			break;
		case 78:
			Go->SetPosition(432.f, 300.f);
			break;
		case 79:
			Go->SetPosition(504.f, 300.f);
			break;
		case 80:
			Go->SetPosition(324.f, 300.f);
			break;
			//ninth row
		case 81:
			Go->SetPosition(144.f, 332.f);
			break;
		case 82:
			Go->SetPosition(216.f, 332.f);
			break;
		case 83:
			Go->SetPosition(432.f, 332.f);
			break;
		case 84:
			Go->SetPosition(504.f, 332.f);
			break;
			//tenth row
		case 85:
			Go->SetPosition(144.f, 369.f);
			break;
		case 86:
			Go->SetPosition(180.f, 369.f);
			break;
		case 87:
			Go->SetPosition(216.f, 369.f);
			break;
		case 88:
			Go->SetPosition(432.f, 369.f);
			break;
		case 89:
			Go->SetPosition(468.f, 369.f);
			break;
		case 90:
			Go->SetPosition(504.f, 369.f);
			break;
			//eleventh row
		case 91:
			Go->SetPosition(144.f, 401.f);
			break;
		case 92:
			Go->SetPosition(216.f, 401.f);
			break;
		case 93:
			Go->SetPosition(432.f, 401.f);
			break;
		case 94:
			Go->SetPosition(504.f, 401.f);
			break;
			//twelveth row
		case 95:
			Go->SetPosition(144.f, 438.f);
			break;
		case 96:
			Go->SetPosition(216.f, 438.f);
			break;
		case 97:
			Go->SetPosition(252.f, 438.f);
			break;
		case 98:
			Go->SetPosition(288.f, 438.f);
			break;
		case 99:
			Go->SetPosition(360.f, 438.f);
			break;
		case 100:
			Go->SetPosition(396.f, 438.f);
			break;
		case 101:
			Go->SetPosition(432.f, 438.f);
			break;
		case 102:
			Go->SetPosition(504.f, 438.f);
			break;
		case 103:
			Go->SetPosition(324.f, 438.f);
			break;
			//thirteenth row
		case 104:
			Go->SetPosition(144.f, 470.f);
			break;
		case 105:
			Go->SetPosition(216.f, 470.f);
			break;
		case 106:
			Go->SetPosition(432.f, 470.f);
			break;
		case 107:
			Go->SetPosition(504.f, 470.f);
			break;
			//fourteenth row
		case 108:
			Go->SetPosition(36.f, 510.f);
			break;
		case 109:
			Go->SetPosition(72.f, 510.f);
			break;
		case 110:
			Go->SetPosition(108.f, 510.f);
			break;
		case 111:
			Go->SetPosition(144.f, 510.f);
			break;
		case 112:
			Go->SetPosition(180.f, 510.f);
			break;
		case 113:
			Go->SetPosition(216.f, 510.f);
			break;
		case 114:
			Go->SetPosition(252.f, 510.f);
			break;
		case 115:
			Go->SetPosition(288.f, 510.f);
			break;
		case 116:
			Go->SetPosition(360.f, 510.f);
			break;
		case 117:
			Go->SetPosition(396.f, 510.f);
			break;
		case 118:
			Go->SetPosition(432.f, 510.f);
			break;
		case 119:
			Go->SetPosition(468.f, 510.f);
			break;
		case 120:
			Go->SetPosition(504.f, 510.f);
			break;
		case 121:
			Go->SetPosition(540.f, 510.f);
			break;
		case 122:
			Go->SetPosition(576.f, 510.f);
			break;
		case 124:
			Go->SetPosition(612.f, 510.f);
			break;
			//fifteenth row
		case 125:
			Go->SetPosition(36.f, 542.f);
			break;
		case 126:
			Go->SetPosition(144.f, 542.f);
			break;
		case 127:
			Go->SetPosition(288.f, 542.f);
			break;
		case 128:
			Go->SetPosition(360.f, 542.f);
			break;
		case 129:
			Go->SetPosition(504.f, 542.f);
			break;
		case 130:
			Go->SetPosition(612.f, 542.f);
			break;
			//sixteenth row
		case 131:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(36.f, 578.f);
			break;
		case 132:
			Go->SetPosition(72.f, 578.f);
			break;
		case 133:
			Go->SetPosition(144.f, 578.f);
			break;
		case 134:
			Go->SetPosition(180.f, 578.f);
			break;
		case 135:
			Go->SetPosition(216.f, 578.f);
			break;
		case 136:
			Go->SetPosition(252.f, 578.f);
			break;
		case 137:
			Go->SetPosition(288.f, 578.f);
			break;
		case 138:
			Go->SetPosition(360.f, 578.f);
			break;
		case 139:
			Go->SetPosition(396.f, 578.f);
			break;
		case 140:
			Go->SetPosition(432.f, 578.f);
			break;
		case 141:
			Go->SetPosition(468.f, 578.f);
			break;
		case 142:
			Go->SetPosition(504.f, 578.f);
			break;
		case 143:
			Go->SetPosition(576.f, 578.f);
			break;
		case 123:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(612.f, 578.f);
			break;
		case 28:
			Go->SetPosition(324.f, 578.f);
			break;
			//seventeenth row
		case 144:
			Go->SetPosition(72.f, 614.f);
			break;
		case 145:
			Go->SetPosition(144.f, 614.f);
			break;
		case 146:
			Go->SetPosition(216.f, 614.f);
			break;
		case 147:
			Go->SetPosition(432.f, 614.f);
			break;
		case 148:
			Go->SetPosition(504.f, 614.f);
			break;
		case 149:
			Go->SetPosition(576.f, 614.f);
			break;
			//eighteenth row
		case 150:
			Go->SetPosition(36.f, 650.f);
			break;
		case 151:
			Go->SetPosition(72.f, 650.f);
			break;
		case 152:
			Go->SetPosition(108.f, 650.f);
			break;
		case 153:
			Go->SetPosition(144.f, 650.f);
			break;
		case 154:
			Go->SetPosition(216.f, 650.f);
			break;
		case 155:
			Go->SetPosition(252.f, 650.f);
			break;
		case 156:
			Go->SetPosition(288.f, 650.f);
			break;
		case 157:
			Go->SetPosition(360.f, 650.f);
			break;
		case 158:
			Go->SetPosition(396.f, 650.f);
			break;
		case 159:
			Go->SetPosition(432.f, 650.f);
			break;
		case 160:
			Go->SetPosition(504.f, 650.f);
			break;
		case 161:
			Go->SetPosition(540.f, 650.f);
			break;
		case 162:
			Go->SetPosition(576.f, 650.f);
			break;
		case 163:
			Go->SetPosition(612.f, 650.f);
			break;
			//nineteenth row
		case 164:
			Go->SetPosition(36.f, 686.f);
			break;
		case 165:
			Go->SetPosition(288.f, 686.f);
			break;
		case 166:
			Go->SetPosition(360.f, 686.f);
			break;
		case 167:
			Go->SetPosition(612.f, 686.f);
			break;
			//twentieth row
		case 168:
			Go->SetPosition(36.f, 722.f);
			break;
		case 169:
			Go->SetPosition(72.f, 722.f);
			break;
		case 170:
			Go->SetPosition(108.f, 722.f);
			break;
		case 171:
			Go->SetPosition(144.f, 722.f);
			break;
		case 172:
			Go->SetPosition(180.f, 722.f);
			break;
		case 173:
			Go->SetPosition(216.f, 722.f);
			break;
		case 174:
			Go->SetPosition(252.f, 722.f);
			break;
		case 175:
			Go->SetPosition(288.f, 722.f);
			break;
		case 176:
			Go->SetPosition(360.f, 722.f);
			break;
		case 177:
			Go->SetPosition(396.f, 722.f);
			break;
		case 178:
			Go->SetPosition(432.f, 722.f);
			break;
		case 179:
			Go->SetPosition(468.f, 722.f);
			break;
		case 180:
			Go->SetPosition(504.f, 722.f);
			break;
		case 181:
			Go->SetPosition(540.f, 722.f);
			break;
		case 182:
			Go->SetPosition(576.f, 722.f);
			break;
		case 183:
			Go->SetPosition(612.f, 722.f);
			break;
		case 184:
			Go->SetPosition(324.f, 722.f);
			break;
		default:
			Go->SetPosition(0.f, -100.f);
			break;
		}

		Go->AddComponent(pickUp);
		scene.Add(Go);
	}
}
void LoadPickups(dae::Scene& scene, std::shared_ptr<dae::GameObject> Pickupper)
{
	for (int i = 0; i < 185; i++)
	{
		auto Go = std::make_shared<dae::GameObject>();
		auto Texture = std::make_shared<TextureComponent>(Go);

		auto ren = std::make_shared<RenderComponent>(Go);
		Go->AddComponent(ren);

		Texture->SetTexture("PickUpSmall.png");
		Texture->setWidthHeight(32.f, 24.f);
		Go->AddComponent(Texture);
		auto pickUp = std::make_shared<PickupComponent>(Go);
		pickUp->AddPickupper(Pickupper);
		pickUp->SetGO(Go);
		pickUp->SetRadius(24.f);

		switch (i)
		{
			//first row
		case 0:
			Go->SetPosition(36.f, 71.f);
			break;
		case 1:
			Go->SetPosition(72.f, 71.f);
			break;
		case 2:
			Go->SetPosition(108.f, 71.f);
			break;
		case 3:
			Go->SetPosition(144.f, 71.f);
			break;
		case 4:
			Go->SetPosition(180.f, 71.f);
			break;
		case 5:
			Go->SetPosition(216.f, 71.f);
			break;
		case 6:
			Go->SetPosition(252.f, 71.f);
			break;
		case 7:
			Go->SetPosition(288.f, 71.f);
			break;
		case 8:
			Go->SetPosition(360.f, 71.f);
			break;
		case 9:
			Go->SetPosition(396.f, 71.f);
			break;
		case 10:
			Go->SetPosition(432.f, 71.f);
			break;
		case 11:
			Go->SetPosition(468.f, 71.f);
			break;
		case 12:
			Go->SetPosition(504.f, 71.f);
			break;
		case 13:
			Go->SetPosition(540.f, 71.f);
			break;
		case 14:
			Go->SetPosition(576.f, 71.f);
			break;
		case 15:
			Go->SetPosition(612.f, 71.f);
			break;
			//second row
		case 16:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(36.f, 103.f);
			break;
		case 17:
			Go->SetPosition(144.f, 103.f);
			break;
		case 18:
			Go->SetPosition(288.f, 103.f);
			break;
		case 19:
			Go->SetPosition(360.f, 103.f);
			break;
		case 20:
			Go->SetPosition(504.f, 103.f);
			break;
		case 21:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(612.f, 103.f);
			break;
			//third row
		case 22:
			Go->SetPosition(36.f, 135.f);
			break;
		case 23:
			Go->SetPosition(144.f, 135.f);
			break;
		case 24:
			Go->SetPosition(288.f, 135.f);
			break;
		case 25:
			Go->SetPosition(360.f, 135.f);
			break;
		case 26:
			Go->SetPosition(504.f, 135.f);
			break;
		case 27:
			Go->SetPosition(612.f, 135.f);
			break;
			//fourth row
		case 29:
			Go->SetPosition(36.f, 167.f);
			break;
		case 30:
			Go->SetPosition(72.f, 167.f);
			break;
		case 31:
			Go->SetPosition(108.f, 167.f);
			break;
		case 32:
			Go->SetPosition(144.f, 167.f);
			break;
		case 33:
			Go->SetPosition(180.f, 167.f);
			break;
		case 34:
			Go->SetPosition(216.f, 167.f);
			break;
		case 35:
			Go->SetPosition(252.f, 167.f);
			break;
		case 36:
			Go->SetPosition(288.f, 167.f);
			break;
		case 37:
			Go->SetPosition(360.f, 167.f);
			break;
		case 38:
			Go->SetPosition(396.f, 167.f);
			break;
		case 39:
			Go->SetPosition(432.f, 167.f);
			break;
		case 40:
			Go->SetPosition(468.f, 167.f);
			break;
		case 41:
			Go->SetPosition(504.f, 167.f);
			break;
		case 42:
			Go->SetPosition(540.f, 167.f);
			break;
		case 43:
			Go->SetPosition(576.f, 167.f);
			break;
		case 44:
			Go->SetPosition(612.f, 167.f);
			break;
		case 46:
			Go->SetPosition(324.f, 167.f);
			break;
			//fifth row
		case 47:
			Go->SetPosition(36.f, 199.f);
			break;
		case 48:
			Go->SetPosition(144.f, 199.f);
			break;
		case 49:
			Go->SetPosition(216.f, 199.f);
			break;
		case 50:
			Go->SetPosition(432.f, 199.f);
			break;
		case 51:
			Go->SetPosition(504.f, 199.f);
			break;
		case 52:
			Go->SetPosition(612.f, 199.f);
			break;
			//sixth row
		case 53:
			Go->SetPosition(36.f, 231.f);
			break;
		case 54:
			Go->SetPosition(144.f, 231.f);
			break;
		case 55:
			Go->SetPosition(216.f, 231.f);
			break;
		case 56:
			Go->SetPosition(432.f, 230.f);
			break;
		case 57:
			Go->SetPosition(504.f, 231.f);
			break;
		case 58:
			Go->SetPosition(612.f, 231.f);
			break;
		case 59:
			Go->SetPosition(72.f, 231.f);
			break;
		case 60:
			Go->SetPosition(108.f, 231.f);
			break;
		case 61:
			Go->SetPosition(288.f, 231.f);
			break;
		case 62:
			Go->SetPosition(360.f, 231.f);
			break;
		case 63:
			Go->SetPosition(396.f, 231.f);
			break;
		case 64:
			Go->SetPosition(540.f, 231.f);
			break;
		case 65:
			Go->SetPosition(576.f, 231.f);
			break;
		case 67:
			Go->SetPosition(252.f, 231.f);
			break;
			//seventh row
		case 68:
			Go->SetPosition(144.f, 263.f);
			break;
		case 69:
			Go->SetPosition(288.f, 263.f);
			break;
		case 70:
			Go->SetPosition(360.f, 263.f);
			break;
		case 71:
			Go->SetPosition(504.f, 263.f);
			break;
			//eight row
		case 72:
			Go->SetPosition(144.f, 300.f);
			break;
		case 73:
			Go->SetPosition(216.f, 300.f);
			break;
		case 74:
			Go->SetPosition(252.f, 300.f);
			break;
		case 75:
			Go->SetPosition(288.f, 300.f);
			break;
		case 76:
			Go->SetPosition(360.f, 300.f);
			break;
		case 77:
			Go->SetPosition(396.f, 300.f);
			break;
		case 78:
			Go->SetPosition(432.f, 300.f);
			break;
		case 79:
			Go->SetPosition(504.f, 300.f);
			break;
		case 80:
			Go->SetPosition(324.f, 300.f);
			break;
			//ninth row
		case 81:
			Go->SetPosition(144.f, 332.f);
			break;
		case 82:
			Go->SetPosition(216.f, 332.f);
			break;
		case 83:
			Go->SetPosition(432.f, 332.f);
			break;
		case 84:
			Go->SetPosition(504.f, 332.f);
			break;
			//tenth row
		case 85:
			Go->SetPosition(144.f, 369.f);
			break;
		case 86:
			Go->SetPosition(180.f, 369.f);
			break;
		case 87:
			Go->SetPosition(216.f, 369.f);
			break;
		case 88:
			Go->SetPosition(432.f, 369.f);
			break;
		case 89:
			Go->SetPosition(468.f, 369.f);
			break;
		case 90:
			Go->SetPosition(504.f, 369.f);
			break;
			//eleventh row
		case 91:
			Go->SetPosition(144.f, 401.f);
			break;
		case 92:
			Go->SetPosition(216.f, 401.f);
			break;
		case 93:
			Go->SetPosition(432.f, 401.f);
			break;
		case 94:
			Go->SetPosition(504.f, 401.f);
			break;
			//twelveth row
		case 95:
			Go->SetPosition(144.f, 438.f);
			break;
		case 96:
			Go->SetPosition(216.f, 438.f);
			break;
		case 97:
			Go->SetPosition(252.f, 438.f);
			break;
		case 98:
			Go->SetPosition(288.f, 438.f);
			break;
		case 99:
			Go->SetPosition(360.f, 438.f);
			break;
		case 100:
			Go->SetPosition(396.f, 438.f);
			break;
		case 101:
			Go->SetPosition(432.f, 438.f);
			break;
		case 102:
			Go->SetPosition(504.f, 438.f);
			break;
		case 103:
			Go->SetPosition(324.f, 438.f);
			break;
			//thirteenth row
		case 104:
			Go->SetPosition(144.f, 470.f);
			break;
		case 105:
			Go->SetPosition(216.f, 470.f);
			break;
		case 106:
			Go->SetPosition(432.f, 470.f);
			break;
		case 107:
			Go->SetPosition(504.f, 470.f);
			break;
			//fourteenth row
		case 108:
			Go->SetPosition(36.f, 510.f);
			break;
		case 109:
			Go->SetPosition(72.f, 510.f);
			break;
		case 110:
			Go->SetPosition(108.f, 510.f);
			break;
		case 111:
			Go->SetPosition(144.f, 510.f);
			break;
		case 112:
			Go->SetPosition(180.f, 510.f);
			break;
		case 113:
			Go->SetPosition(216.f, 510.f);
			break;
		case 114:
			Go->SetPosition(252.f, 510.f);
			break;
		case 115:
			Go->SetPosition(288.f, 510.f);
			break;
		case 116:
			Go->SetPosition(360.f, 510.f);
			break;
		case 117:
			Go->SetPosition(396.f, 510.f);
			break;
		case 118:
			Go->SetPosition(432.f, 510.f);
			break;
		case 119:
			Go->SetPosition(468.f, 510.f);
			break;
		case 120:
			Go->SetPosition(504.f, 510.f);
			break;
		case 121:
			Go->SetPosition(540.f, 510.f);
			break;
		case 122:
			Go->SetPosition(576.f, 510.f);
			break;
		case 124:
			Go->SetPosition(612.f, 510.f);
			break;
			//fifteenth row
		case 125:
			Go->SetPosition(36.f, 542.f);
			break;
		case 126:
			Go->SetPosition(144.f, 542.f);
			break;
		case 127:
			Go->SetPosition(288.f, 542.f);
			break;
		case 128:
			Go->SetPosition(360.f, 542.f);
			break;
		case 129:
			Go->SetPosition(504.f, 542.f);
			break;
		case 130:
			Go->SetPosition(612.f, 542.f);
			break;
			//sixteenth row
		case 131:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(36.f, 578.f);
			break;
		case 132:
			Go->SetPosition(72.f, 578.f);
			break;
		case 133:
			Go->SetPosition(144.f, 578.f);
			break;
		case 134:
			Go->SetPosition(180.f, 578.f);
			break;
		case 135:
			Go->SetPosition(216.f, 578.f);
			break;
		case 136:
			Go->SetPosition(252.f, 578.f);
			break;
		case 137:
			Go->SetPosition(288.f, 578.f);
			break;
		case 138:
			Go->SetPosition(360.f, 578.f);
			break;
		case 139:
			Go->SetPosition(396.f, 578.f);
			break;
		case 140:
			Go->SetPosition(432.f, 578.f);
			break;
		case 141:
			Go->SetPosition(468.f, 578.f);
			break;
		case 142:
			Go->SetPosition(504.f, 578.f);
			break;
		case 143:
			Go->SetPosition(576.f, 578.f);
			break;
		case 123:
			Texture->SetTexture("PickUpBig.png");
			pickUp->setBig(true);
			Go->SetPosition(612.f, 578.f);
			break;
		case 28:
			Go->SetPosition(324.f, 578.f);
			break;
			//seventeenth row
		case 144:
			Go->SetPosition(72.f, 614.f);
			break;
		case 145:
			Go->SetPosition(144.f, 614.f);
			break;
		case 146:
			Go->SetPosition(216.f, 614.f);
			break;
		case 147:
			Go->SetPosition(432.f, 614.f);
			break;
		case 148:
			Go->SetPosition(504.f, 614.f);
			break;
		case 149:
			Go->SetPosition(576.f, 614.f);
			break;
			//eighteenth row
		case 150:
			Go->SetPosition(36.f, 650.f);
			break;
		case 151:
			Go->SetPosition(72.f, 650.f);
			break;
		case 152:
			Go->SetPosition(108.f, 650.f);
			break;
		case 153:
			Go->SetPosition(144.f, 650.f);
			break;
		case 154:
			Go->SetPosition(216.f, 650.f);
			break;
		case 155:
			Go->SetPosition(252.f, 650.f);
			break;
		case 156:
			Go->SetPosition(288.f, 650.f);
			break;
		case 157:
			Go->SetPosition(360.f, 650.f);
			break;
		case 158:
			Go->SetPosition(396.f, 650.f);
			break;
		case 159:
			Go->SetPosition(432.f, 650.f);
			break;
		case 160:
			Go->SetPosition(504.f, 650.f);
			break;
		case 161:
			Go->SetPosition(540.f, 650.f);
			break;
		case 162:
			Go->SetPosition(576.f, 650.f);
			break;
		case 163:
			Go->SetPosition(612.f, 650.f);
			break;
			//nineteenth row
		case 164:
			Go->SetPosition(36.f, 686.f);
			break;
		case 165:
			Go->SetPosition(288.f, 686.f);
			break;
		case 166:
			Go->SetPosition(360.f, 686.f);
			break;
		case 167:
			Go->SetPosition(612.f, 686.f);
			break;
			//twentieth row
		case 168:
			Go->SetPosition(36.f, 722.f);
			break;
		case 169:
			Go->SetPosition(72.f, 722.f);
			break;
		case 170:
			Go->SetPosition(108.f, 722.f);
			break;
		case 171:
			Go->SetPosition(144.f, 722.f);
			break;
		case 172:
			Go->SetPosition(180.f, 722.f);
			break;
		case 173:
			Go->SetPosition(216.f, 722.f);
			break;
		case 174:
			Go->SetPosition(252.f, 722.f);
			break;
		case 175:
			Go->SetPosition(288.f, 722.f);
			break;
		case 176:
			Go->SetPosition(360.f, 722.f);
			break;
		case 177:
			Go->SetPosition(396.f, 722.f);
			break;
		case 178:
			Go->SetPosition(432.f, 722.f);
			break;
		case 179:
			Go->SetPosition(468.f, 722.f);
			break;
		case 180:
			Go->SetPosition(504.f, 722.f);
			break;
		case 181:
			Go->SetPosition(540.f, 722.f);
			break;
		case 182:
			Go->SetPosition(576.f, 722.f);
			break;
		case 183:
			Go->SetPosition(612.f, 722.f);
			break;
		case 184:
			Go->SetPosition(324.f, 722.f);
			break;
		default:
			Go->SetPosition(0.f, -100.f);
			break;
		}

		Go->AddComponent(pickUp);
		scene.Add(Go);
	}
}
void LoadWalkingGrid(std::shared_ptr<RailComponent> comp)
{
	//possible directions
	std::vector<MoveDirection> movU{ MoveDirection::UP};
	std::vector<MoveDirection> movD{MoveDirection::DOWN};
	std::vector<MoveDirection> movR{MoveDirection::RIGHT };
	std::vector<MoveDirection> movL{ MoveDirection::LEFT};
	std::vector<MoveDirection> movDL{ MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUR{ MoveDirection::UP, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUL{ MoveDirection::UP, MoveDirection::LEFT };
	std::vector<MoveDirection> movDR{ MoveDirection::DOWN, MoveDirection::RIGHT};
	std::vector<MoveDirection> movDLR{MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movULR{ MoveDirection::UP, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDL{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUDLR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };

	//actual points
	for (int i = 0; i < 76 ; i++)
	{
		CornerPoint p;
		switch (i)
		{
		case 0:
			p.pos.x = 150.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 1:
			p.pos.x = 150.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 2:
			p.pos.x = 30.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;
		case 3:
			p.pos.x = 293.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 4:
			p.pos.x = 293.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 5:
			p.pos.x = 150.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 6:
			p.pos.x = 30.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 7:
			p.pos.x = 150.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 8:
			p.pos.x = 30.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 9:
			p.pos.x = 20.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movR;
			break;
		case 10:
			p.pos.x = 220.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 11:
			p.pos.x = 220.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 12:
			p.pos.x = 220.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 13:
			p.pos.x = 293.f;
			p.pos.y = 215.f;
			p.m_AllowedDirections = movDL;
			break;
		case 14:
			p.pos.x = 293.f;
			p.pos.y = 295.f;
			p.m_AllowedDirections = movULR;
			break;
		case 15:
			p.pos.x = 220.f;
			p.pos.y = 285.f;
			p.m_AllowedDirections = movDR;
			break;
		case 16:
			p.pos.x = 150.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 17:
			p.pos.x = 150.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 18:
			p.pos.x = 30.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDR;
			break;
		case 19:
			p.pos.x = 30.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUR;
			break;
		case 20:
			p.pos.x = 90.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDL;
			break;
		case 21:
			p.pos.x = 90.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movULR;
			break;
		case 22:
			p.pos.x = 30.f;
			p.pos.y = 641.f;
			p.m_AllowedDirections = movDR;
			break;
		case 23:
			p.pos.x = 30.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUR;
			break;
		case 24:
			p.pos.x = 293.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 25:
			p.pos.x = 150.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movUL;
			break;
		case 26:
			p.pos.x = 293.f;
			p.pos.y = 630.f;
			p.m_AllowedDirections = movDL;
			break;
		case 27:
			p.pos.x = 220.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 28:
			p.pos.x = 220.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 29:
			p.pos.x = 293.f;
			p.pos.y = 574.f;
			p.m_AllowedDirections = movULR;
			break;
		case 30:
			p.pos.x = 293.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDL;
			break;
		case 31:
			p.pos.x = 220.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 32:
			p.pos.x = 220.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 33:
			p.pos.x = 360.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 34:
			p.pos.x = 360.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDR;
			break;
		case 35:
			p.pos.x = 430.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUL;
			break;
		case 36:
			p.pos.x = 625.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUL;
			break;
		case 37:
			p.pos.x = 625.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDL;
			break;
		case 38:
			p.pos.x = 560.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movULR;
			break;
		case 39:
			p.pos.x = 500.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 40:
			p.pos.x = 505.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 41:

			p.pos.x = 430.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 42:
			p.pos.x = 360.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movULR;
			break;
		case 43:
			p.pos.x = 560.f;
			p.pos.y = 565.f;
			p.m_AllowedDirections = movDR;
			break;
		case 44:
			p.pos.x = 625.f;
			p.pos.y = 568.f;
			p.m_AllowedDirections = movUL;
			break;
		case 45:
			p.pos.x = 360.f;
			p.pos.y = 495.f;
			p.m_AllowedDirections = movDR;
			break;
		case 46:
			p.pos.x = 625.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movDL;
			break;
		case 47:
			p.pos.x = 505.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 48:
			p.pos.x = 430.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 49:
			p.pos.x = 430.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 50:
			p.pos.x = 430.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 51:
			p.pos.x = 625.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movL;
			break;
		case 52:
			p.pos.x = 505.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 53:
			p.pos.x = 434.f;
			p.pos.y = 290.f;
			p.m_AllowedDirections = movDL;
			break;
		case 54:
			p.pos.x = 360.f;
			p.pos.y = 294.f;
			p.m_AllowedDirections = movULR;
			break;
		case 55:
			p.pos.x = 360.f;
			p.pos.y = 220.f;
			p.m_AllowedDirections = movDR;
			break;
		case 56:
			p.pos.x = 434.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 57:
			p.pos.x = 500.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 58:
			p.pos.x = 625.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 59:
			p.pos.x = 625.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 60:
			p.pos.x = 625.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 61:
			p.pos.x = 500.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 62:
			p.pos.x = 500.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 63:
			p.pos.x = 434.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 64:
			p.pos.x = 360.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 65:
			p.pos.x = 360.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;	
		default:
			break;
		}
		
		comp->AddCornerPoint(p);
	}
}
void LoadEnemyWalkingGrid(std::shared_ptr<MoveRailComponent> comp)
{
	//possible directions
	std::vector<MoveDirection> movU{ MoveDirection::UP };
	std::vector<MoveDirection> movD{ MoveDirection::DOWN };
	std::vector<MoveDirection> movR{ MoveDirection::RIGHT };
	std::vector<MoveDirection> movL{ MoveDirection::LEFT };
	std::vector<MoveDirection> movLR{ MoveDirection::RIGHT, MoveDirection::LEFT };
	std::vector<MoveDirection> movDL{ MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUR{ MoveDirection::UP, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUL{ MoveDirection::UP, MoveDirection::LEFT };
	std::vector<MoveDirection> movDR{ MoveDirection::DOWN, MoveDirection::RIGHT };
	std::vector<MoveDirection> movDLR{ MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movULR{ MoveDirection::UP, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDL{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUDLR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };

	//actual points
	for (int i = 0; i < 78; i++)
	{
		CornerPoint p;
		switch (i)
		{
		case 0:
			p.pos.x = 150.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 1:
			p.pos.x = 150.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 2:
			p.pos.x = 30.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;
		case 3:
			p.pos.x = 293.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 4:
			p.pos.x = 293.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 5:
			p.pos.x = 150.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 6:
			p.pos.x = 30.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 7:
			p.pos.x = 150.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 8:
			p.pos.x = 30.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 9:
			p.pos.x = 20.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movR;
			break;
		case 10:
			p.pos.x = 220.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 11:
			p.pos.x = 220.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 12:
			p.pos.x = 220.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 13:
			p.pos.x = 293.f;
			p.pos.y = 215.f;
			p.m_AllowedDirections = movDL;
			break;
		case 14:
			p.pos.x = 293.f;
			p.pos.y = 295.f;
			p.m_AllowedDirections = movULR;
			break;
		case 15:
			p.pos.x = 220.f;
			p.pos.y = 285.f;
			p.m_AllowedDirections = movDR;
			break;
		case 16:
			p.pos.x = 150.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 17:
			p.pos.x = 150.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 18:
			p.pos.x = 30.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDR;
			break;
		case 19:
			p.pos.x = 30.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUR;
			break;
		case 20:
			p.pos.x = 90.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDL;
			break;
		case 21:
			p.pos.x = 90.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movULR;
			break;
		case 22:
			p.pos.x = 30.f;
			p.pos.y = 641.f;
			p.m_AllowedDirections = movDR;
			break;
		case 23:
			p.pos.x = 30.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUR;
			break;
		case 24:
			p.pos.x = 293.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 25:
			p.pos.x = 150.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movUL;
			break;
		case 26:
			p.pos.x = 293.f;
			p.pos.y = 630.f;
			p.m_AllowedDirections = movDL;
			break;
		case 27:
			p.pos.x = 220.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 28:
			p.pos.x = 220.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 29:
			p.pos.x = 293.f;
			p.pos.y = 574.f;
			p.m_AllowedDirections = movULR;
			break;
		case 30:
			p.pos.x = 293.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDL;
			break;
		case 31:
			p.pos.x = 220.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 32:
			p.pos.x = 220.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 33:
			p.pos.x = 360.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 34:
			p.pos.x = 360.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDR;
			break;
		case 35:
			p.pos.x = 430.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUL;
			break;
		case 36:
			p.pos.x = 625.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUL;
			break;
		case 37:
			p.pos.x = 625.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDL;
			break;
		case 38:
			p.pos.x = 560.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movULR;
			break;
		case 39:
			p.pos.x = 500.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 40:
			p.pos.x = 505.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 41:

			p.pos.x = 430.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 42:
			p.pos.x = 360.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movULR;
			break;
		case 43:
			p.pos.x = 560.f;
			p.pos.y = 565.f;
			p.m_AllowedDirections = movDR;
			break;
		case 44:
			p.pos.x = 625.f;
			p.pos.y = 568.f;
			p.m_AllowedDirections = movUL;
			break;
		case 45:
			p.pos.x = 360.f;
			p.pos.y = 495.f;
			p.m_AllowedDirections = movDR;
			break;
		case 46:
			p.pos.x = 625.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movDL;
			break;
		case 47:
			p.pos.x = 505.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 48:
			p.pos.x = 430.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 49:
			p.pos.x = 430.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 50:
			p.pos.x = 430.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 51:
			p.pos.x = 625.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movL;
			break;
		case 52:
			p.pos.x = 505.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 53:
			p.pos.x = 434.f;
			p.pos.y = 290.f;
			p.m_AllowedDirections = movDL;
			break;
		case 54:
			p.pos.x = 360.f;
			p.pos.y = 294.f;
			p.m_AllowedDirections = movULR;
			break;
		case 55:
			p.pos.x = 360.f;
			p.pos.y = 220.f;
			p.m_AllowedDirections = movDR;
			break;
		case 56:
			p.pos.x = 434.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 57:
			p.pos.x = 500.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 58:
			p.pos.x = 625.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 59:
			p.pos.x = 625.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 60:
			p.pos.x = 625.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 61:
			p.pos.x = 500.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 62:
			p.pos.x = 500.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 63:
			p.pos.x = 434.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 64:
			p.pos.x = 360.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 65:
			p.pos.x = 360.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;
		case 66:
			p.pos.x = 324.f;
			p.pos.y = 279.f;
			p.m_AllowedDirections = movLR;
			break;
		case 67:
			p.pos.x = 324.f;
			p.pos.y = 370.f;
			p.m_AllowedDirections = movU;
			break;
		default:
			break;
		}

		comp->AddCornerPoint(p);
	}
}
void LoadEnemyWalkingGrid(std::shared_ptr<RailComponent> comp)
{
	//possible directions
	std::vector<MoveDirection> movU{ MoveDirection::UP };
	std::vector<MoveDirection> movD{ MoveDirection::DOWN };
	std::vector<MoveDirection> movR{ MoveDirection::RIGHT };
	std::vector<MoveDirection> movL{ MoveDirection::LEFT };
	std::vector<MoveDirection> movLR{ MoveDirection::RIGHT, MoveDirection::LEFT };
	std::vector<MoveDirection> movDL{ MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUR{ MoveDirection::UP, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUL{ MoveDirection::UP, MoveDirection::LEFT };
	std::vector<MoveDirection> movDR{ MoveDirection::DOWN, MoveDirection::RIGHT };
	std::vector<MoveDirection> movDLR{ MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movULR{ MoveDirection::UP, MoveDirection::LEFT, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::RIGHT };
	std::vector<MoveDirection> movUDL{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT };
	std::vector<MoveDirection> movUDLR{ MoveDirection::UP, MoveDirection::DOWN, MoveDirection::LEFT, MoveDirection::RIGHT };

	//actual points
	for (int i = 0; i < 78; i++)
	{
		CornerPoint p;
		switch (i)
		{
		case 0:
			p.pos.x = 150.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 1:
			p.pos.x = 150.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 2:
			p.pos.x = 30.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;
		case 3:
			p.pos.x = 293.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 4:
			p.pos.x = 293.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 5:
			p.pos.x = 150.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 6:
			p.pos.x = 30.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 7:
			p.pos.x = 150.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 8:
			p.pos.x = 30.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 9:
			p.pos.x = 20.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movR;
			break;
		case 10:
			p.pos.x = 220.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 11:
			p.pos.x = 220.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 12:
			p.pos.x = 220.f;
			p.pos.y = 225.f;
			p.m_AllowedDirections = movUR;
			break;
		case 13:
			p.pos.x = 293.f;
			p.pos.y = 215.f;
			p.m_AllowedDirections = movDL;
			break;
		case 14:
			p.pos.x = 293.f;
			p.pos.y = 295.f;
			p.m_AllowedDirections = movULR;
			break;
		case 15:
			p.pos.x = 220.f;
			p.pos.y = 285.f;
			p.m_AllowedDirections = movDR;
			break;
		case 16:
			p.pos.x = 150.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 17:
			p.pos.x = 150.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 18:
			p.pos.x = 30.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDR;
			break;
		case 19:
			p.pos.x = 30.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movUR;
			break;
		case 20:
			p.pos.x = 90.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDL;
			break;
		case 21:
			p.pos.x = 90.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movULR;
			break;
		case 22:
			p.pos.x = 30.f;
			p.pos.y = 641.f;
			p.m_AllowedDirections = movDR;
			break;
		case 23:
			p.pos.x = 30.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUR;
			break;
		case 24:
			p.pos.x = 293.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 25:
			p.pos.x = 150.f;
			p.pos.y = 648.f;
			p.m_AllowedDirections = movUL;
			break;
		case 26:
			p.pos.x = 293.f;
			p.pos.y = 630.f;
			p.m_AllowedDirections = movDL;
			break;
		case 27:
			p.pos.x = 220.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 28:
			p.pos.x = 220.f;
			p.pos.y = 573.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 29:
			p.pos.x = 293.f;
			p.pos.y = 574.f;
			p.m_AllowedDirections = movULR;
			break;
		case 30:
			p.pos.x = 293.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movDL;
			break;
		case 31:
			p.pos.x = 220.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 32:
			p.pos.x = 220.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 33:
			p.pos.x = 360.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movULR;
			break;
		case 34:
			p.pos.x = 360.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDR;
			break;
		case 35:
			p.pos.x = 430.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUL;
			break;
		case 36:
			p.pos.x = 625.f;
			p.pos.y = 718.f;
			p.m_AllowedDirections = movUL;
			break;
		case 37:
			p.pos.x = 625.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movDL;
			break;
		case 38:
			p.pos.x = 560.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movULR;
			break;
		case 39:
			p.pos.x = 500.f;
			p.pos.y = 640.f;
			p.m_AllowedDirections = movUR;
			break;
		case 40:
			p.pos.x = 505.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 41:

			p.pos.x = 430.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 42:
			p.pos.x = 360.f;
			p.pos.y = 570.f;
			p.m_AllowedDirections = movULR;
			break;
		case 43:
			p.pos.x = 560.f;
			p.pos.y = 565.f;
			p.m_AllowedDirections = movDR;
			break;
		case 44:
			p.pos.x = 625.f;
			p.pos.y = 568.f;
			p.m_AllowedDirections = movUL;
			break;
		case 45:
			p.pos.x = 360.f;
			p.pos.y = 495.f;
			p.m_AllowedDirections = movDR;
			break;
		case 46:
			p.pos.x = 625.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movDL;
			break;
		case 47:
			p.pos.x = 505.f;
			p.pos.y = 498.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 48:
			p.pos.x = 430.f;
			p.pos.y = 503.f;
			p.m_AllowedDirections = movULR;
			break;
		case 49:
			p.pos.x = 430.f;
			p.pos.y = 440.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 50:
			p.pos.x = 430.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 51:
			p.pos.x = 625.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movL;
			break;
		case 52:
			p.pos.x = 505.f;
			p.pos.y = 363.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 53:
			p.pos.x = 434.f;
			p.pos.y = 290.f;
			p.m_AllowedDirections = movDL;
			break;
		case 54:
			p.pos.x = 360.f;
			p.pos.y = 294.f;
			p.m_AllowedDirections = movULR;
			break;
		case 55:
			p.pos.x = 360.f;
			p.pos.y = 220.f;
			p.m_AllowedDirections = movDR;
			break;
		case 56:
			p.pos.x = 434.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 57:
			p.pos.x = 500.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUDR;
			break;
		case 58:
			p.pos.x = 625.f;
			p.pos.y = 223.f;
			p.m_AllowedDirections = movUL;
			break;
		case 59:
			p.pos.x = 625.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDL;
			break;
		case 60:
			p.pos.x = 625.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDL;
			break;
		case 61:
			p.pos.x = 500.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 62:
			p.pos.x = 500.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movUDLR;
			break;
		case 63:
			p.pos.x = 434.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movDLR;
			break;
		case 64:
			p.pos.x = 360.f;
			p.pos.y = 150.f;
			p.m_AllowedDirections = movULR;
			break;
		case 65:
			p.pos.x = 360.f;
			p.pos.y = 55.f;
			p.m_AllowedDirections = movDR;
			break;
		case 66:
			p.pos.x = 324.f;
			p.pos.y = 279.f;
			p.m_AllowedDirections = movLR;
			break;
		case 67:
			p.pos.x = 324.f;
			p.pos.y = 370.f;
			p.m_AllowedDirections = movU;
			break;
		default:
			break;
		}

		comp->AddCornerPoint(p);
	}
}
