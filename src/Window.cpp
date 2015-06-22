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

#include "Window.h"

Window *p_window = NULL;

Window::Window()
{

}

Window::~Window()
{

}

void Window::WriteData(ExperimentalKey k, unsigned long val)
{
      auto search = m_table.find(k);
      if(search == m_table.end())
      {
          std::cout << k.x << " " << k.y << " " << k.z << " key not present, adding it and adding value " << val << std::endl;
          /*if queue not created for this key, create one, add to it and insert it to the table*/
          MinIdleQueue q;
          q.push(val);
          m_table.emplace(std::make_pair(k, q));
          return;
      }
      /*if queue already present, add to it and insert it to the table*/
      std::cout << k.x << " " << k.y << " " << k.z << " key present, adding it and adding value " << val << std::endl;
      MinIdleQueue q = search->second;
      q.push(val);
      m_table.emplace(std::make_pair(k, q));
}

unsigned long Window::ReadData(ExperimentalKey k)
{

}

void Window::Acquire()
{
   m_mutex.lock();
}

void Window::Release()
{
   m_mutex.unlock();
}
