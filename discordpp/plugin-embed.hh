#pragma once

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>

namespace discordpp{

	using MessageEmbed = PluginEmbed::MessageEmbed;

	template<class BASE>
	class PluginEmbed: public BASE, virtual BotStruct{
	public:
		class MessageEmbed{
		public:
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
				LIME=0x00FF00
				GREEN=0x008000,
				AQUA=0x00FFFF,
				TEAL=0x008080,
				BLUE=0x0000FF,
				NAVY=0x000080,
				FUCHSIA=0xFF00FF,
				PURPLE=0x800080
			};
			
			PluginEmbed setTitle(std::string title){
				embed["title"]=title;

				return *this;
			};

			PluginEmbed setDescription(std::string description){
				embed["description"]=description;

				return *this;
			};

			PluginEmbed setUrl(std::string url){
				embed["url"]=url;

				return *this;
			};
			
			PluginEmbed setTimestamp(std::string timestamp) {
				if (!timestamp.empty()) {
					embed["timestamp"] = timestamp;
				} else {
					time_t now;
					time(&now);
					char buf[sizeof "2011-10-08T07:07:09Z"];
					strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));
					embed["timestamp"] = (std::string)buf;
				}

				return *this;
			};

			PluginEmbed setColor(int color){
				embed["url"]=color;

				return *this;
			};

			PluginEmbed setFooterText(std::string footerText){
				embed["footer"]["text"]=footerText;

				return *this;
			};


			PluginEmbed setFooterIconUrl(std::string footerIconUrl){
				embed["footer"]["icon_url"]=footerIconUrl;

				return *this;
			};

			PluginEmbed setImageUrl(std::string url){
				embed["image"]["url"]=url;

				return *this;
			}

			PluginEmbed setImageDimensions(int width, int height){
				embed["image"]["width"]=width;
				embed["image"]["height"]=height;

				return *this;
			}

			PluginEmbed setThumbnailUrl(std::string url){
				embed["thumbnail"]["url"]=url;

				return *this;
			}

			PluginEmbed setThumbnailDimensions(int width, int height){
				embed["thumbnail"]["width"]=width;
				embed["thumbnail"]["height"]=height;

				return *this;
			}

			PluginEmbed setVideoUrl(std::string url){
				embed["video"]["url"]=url;

				return *this;
			}

			PluginEmbed setVideoDimensions(int width, int height){
				embed["video"]["width"]=width;
				embed["video"]["height"]=height;

				return *this;
			}

			PluginEmbed setProviderName(std::string name){
				embed["provider"]["name"]=name;

				return *this;
			}

			PluginEmbed setProviderUrl(std::string url){
				embed["provider"]["url"]=url;

				return *this;
			}

			PluginEmbed setAuthorName(std::string name){
				embed["author"]["name"]=name;

				return *this;
			}

			PluginEmbed setAuthorUrl(std::string url){
				embed["author"]["url"]=url;

				return *this;
			}

			PluginEmbed setAuthorImageUrl(std::string url){
				embed["author"]["icon_url"]=url;

				return *this;
			}

			PluginEmbed addField(std::string title, std::string desc ,bool _inline){
				if (embed.find("fields") == embed.end()) embed["fields"] = nlohmann::json::array();
				
				nlohmann::json toPush;

				toPush["name"] = title;
				toPush["value"] = desc;
				toPush["inline"] = _inline;

				embed["fields"].push_back(toPush);

				return *this;
			}

			nlohmann::json getEmbed(){
				return embed;
			};
		protected:
			nlohman::json embed;
		}
	};
	
}