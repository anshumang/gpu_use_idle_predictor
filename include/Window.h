/*
 * This file is part of gpu_use_idle_predictor
 * 
 * cupti_profiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * cupti_profiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cupti_profiler. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author: Anshuman Goswami <anshumang@gatech.edu>
 */

#ifndef _WINDOW_H
#define _WINDOW_H

#include <queue>
#include <map>
#include <mutex>
#include <cstddef>
#include <iostream>
#include "Trigger.h"

struct Window
{
   typedef std::priority_queue<unsigned long, std::vector<unsigned long>, std::greater<unsigned long> > MinIdleQueue;
   typedef Grid ExperimentalKey;
   struct ExperimentalKeyCmpFtor
   {
      bool operator()(ExperimentalKey a, ExperimentalKey b)
      {
         return a.x < b.x;
      }
   };
   typedef std::map <ExperimentalKey, MinIdleQueue, ExperimentalKeyCmpFtor> KeyIdleQueueTable;
   std::mutex m_mutex;
   KeyIdleQueueTable m_table;
   Window();
   ~Window();
   void WriteData(ExperimentalKey k, unsigned long val);
   unsigned long ReadData(ExperimentalKey k);
   void Acquire();
   void Release();
};

#endif
