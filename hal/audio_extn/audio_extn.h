/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef AUDIO_EXTN_H
#define AUDIO_EXTN_H

#include <cutils/str_parms.h>

void *audio_extn_extspk_init(struct audio_device *adev);
void audio_extn_extspk_deinit(void *extn);
void audio_extn_extspk_update(void* extn);
void audio_extn_extspk_set_mode(void* extn, audio_mode_t mode);
void audio_extn_extspk_set_voice_vol(void* extn, float vol);

#ifndef HFP_ENABLED
#define audio_extn_hfp_is_active(adev)                  (0)
#define audio_extn_hfp_get_usecase()                    (-1)
#define audio_extn_hfp_set_parameters(adev, params)     (0)
#else
bool audio_extn_hfp_is_active(struct audio_device *adev);

audio_usecase_t audio_extn_hfp_get_usecase();

void audio_extn_hfp_set_parameters(struct audio_device *adev,
                                    struct str_parms *parms);
#endif

#ifndef SOUND_TRIGGER_ENABLED
#define audio_extn_sound_trigger_init(adev)                            (0)
#define audio_extn_sound_trigger_deinit(adev)                          (0)
#define audio_extn_sound_trigger_update_device_status(snd_dev, event)  (0)
#define audio_extn_sound_trigger_set_parameters(adev, parms)           (0)
#define audio_extn_sound_trigger_check_and_get_session(in)             (0)
#define audio_extn_sound_trigger_stop_lab(in)                          (0)
#define audio_extn_sound_trigger_read(in, buffer, bytes)               (0)

#else

enum st_event_type {
    ST_EVENT_SND_DEVICE_FREE,
    ST_EVENT_SND_DEVICE_BUSY,
    ST_EVENT_STREAM_FREE,
    ST_EVENT_STREAM_BUSY
};
typedef enum st_event_type st_event_type_t;

int audio_extn_sound_trigger_init(struct audio_device *adev);
void audio_extn_sound_trigger_deinit(struct audio_device *adev);
void audio_extn_sound_trigger_update_device_status(snd_device_t snd_device,
                                     st_event_type_t event);
void audio_extn_sound_trigger_set_parameters(struct audio_device *adev,
                                             struct str_parms *parms);
void audio_extn_sound_trigger_check_and_get_session(struct stream_in *in);
void audio_extn_sound_trigger_stop_lab(struct stream_in *in);
int audio_extn_sound_trigger_read(struct stream_in *in, void *buffer,
                                  size_t bytes);
#endif

#endif /* AUDIO_EXTN_H */
