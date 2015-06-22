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

#include "Predictor.h"

Predictor *p_predictor = NULL;

Predictor::Predictor(Trigger* trig, Window *win)
  : m_trig(trig), m_win(win)
{
   m_thr = std::thread(&Predictor::ProcessTrigger, this);
}

Predictor::~Predictor()
{

}

void Predictor::ProcessTrigger()
{
   while(true)
   {
      m_trig->Wait(1);
      //std::cout << "New trigger received" << std::endl;;
      Grid g;
      m_trig->ReadData(&g);
      std::cout << g.x << " " << g.y << " " << g.z << std::endl;
      m_trig->Notify(2);
   }
}
