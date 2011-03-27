#include "subsystems/settings.h"


struct PersistentSettings pers_settings;
bool_t settings_store_now;


void settings_init(void) {
#ifdef USE_PERMANENT_SETTINGS
  if (persistent_read((uint32_t)&pers_settings, sizeof(struct PersistentSettings))) 
    return; // return -1 ?
  persitent_settings_load();
#endif
}


void settings_store(void) {
  persitent_settings_store();
  persistent_write((uint32_t)&pers_settings, sizeof(struct PersistentSettings));
}

