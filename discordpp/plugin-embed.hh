#pragma once

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>

namespace discordpp{
	class MessageEmbed{

	public:
	
		~MessageEmbed() = default;

		// Basic HTML colors by Wikipedia
		enum color:int{
			WHITE=0xFFFFFF,
			SILVER=0xC0C0C0,
			GRAY=0x808080,
			BLACK=0x000000,
			RED=0xFF0000,
			MAROON=0x800000,
			YELLOW=0xFFFF00,
			OLIVE=0x808000,
			LIME=0x00FF00,
			GREEN=0x008000,
			AQUA=0x00FFFF,
			TEAL=0x008080,
			BLUE=0x0000FF,
			NAVY=0x000080,
			FUCHSIA=0xFF00FF,
			PURPLE=0x800080
		};
		
		void setTitle(std::string title){
			this->embed["title"]=title;
		};

		void setDescription(std::string description){
			this->embed["description"]=description;
		};

		void setUrl(std::string url){
			this->embed["url"]=url;
		};
		
		void setTimestamp(std::string timestamp) {
			if (!timestamp.empty()) {
				this->embed["timestamp"] = timestamp;
			} else {
				time_t now;
				time(&now);
				char buf[sizeof "2011-10-08T07:07:09Z"];
				strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));
				this->embed["timestamp"] = (std::string)buf;
			}
		};

		void setColor(int color){
			this->embed["color"]=color;
		};

		void setFooterText(std::string footerText){
			this->embed["footer"]["text"]=footerText;
		};

		void setFooterIconUrl(std::string footerIconUrl){
			this->embed["footer"]["icon_url"]=footerIconUrl;
		};
		
		void setImageUrl(std::string url){
			this->embed["image"]["url"]=url;
		}
		//TODO: Check why dimensions does not work
		void setImageDimensions(int width, int height){
			this->embed["image"]["width"]=width;
			this->embed["image"]["height"]=height;
		}

		void setThumbnailUrl(std::string url){
			this->embed["thumbnail"]["url"]=url;
		}
		//TODO: Check why dimensions does not work
		void setThumbnailDimensions(int width, int height){
			this->embed["thumbnail"]["width"]=width;
			this->embed["thumbnail"]["height"]=height;
		}

		void setVideoUrl(std::string url){
			this->embed["video"]["url"]=url;
		}
		//TODO: Check why video does not work
		void setVideoDimensions(int width, int height){
			this->embed["video"]["width"]=width;
			this->embed["video"]["height"]=height;
		}
		//TODO: Check why provider name and url does not show
		void setProviderName(std::string name){
			this->embed["provider"]["name"]=name;
		}

		void setProviderUrl(std::string url){
			this->embed["provider"]["url"]=url;
		}
		
		void setAuthorName(std::string name){
			this->embed["author"]["name"]=name;
		}

		void setAuthorUrl(std::string url){
			this->embed["author"]["url"]=url;
		}

		void setAuthorIconUrl(std::string url){
			this->embed["author"]["icon_url"]=url;
		}

		void addField(std::string title, std::string desc ,bool _inline){
			if (this->embed.find("fields") == this->embed.end()) this->embed["fields"] = nlohmann::json::array();
			
			nlohmann::json toPush;

			toPush["name"] = title;
			toPush["value"] = desc;
			toPush["inline"] = _inline;

			this->embed["fields"].push_back(toPush);
		}

		nlohmann::json getEmbed(){
			return this->embed;
		};
	protected:
		nlohmann::json embed;

	};
	template<class BASE>
	class PluginEmbed: public BASE, virtual BotStruct{
	public:

	};
};