/*
*   Copyright (C) 2017 Tony Bailey
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include "APRSHelper.h"

#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <iostream>

CAPRSHelper::CAPRSHelper(const std::string& callsign, const std::string& suffix, const std::string& password, const std::string& address, unsigned int port)
:
m_writer(callsign, suffix, password, address, port),
m_buffer(NULL)
{
   m_buffer = new unsigned char[300U];
}

CAPRSHelper::~CAPRSHelper()
{
	delete[] m_buffer;    
}


void CAPRSHelper::open()
{
    m_writer.open();    
}

void CAPRSHelper::send(std::string callsign, float latitude, float longitude )
{    
    ::fprintf(stdout, "Preparing to send data\n");
    unsigned char source[10U];
    //std::string callsign = "N9OTJ";
    copy( callsign.begin(), callsign.end(), source );
    //strcpy(source, callsign.c_str());
    
    char radio[10U];
    ::strcpy(radio, "MD-390");
    //float latitude = 41;
    //float longitude = 85;
    
    ::fprintf(stdout, "Calling the APRSWriter\n");
    m_writer.write(source, radio, m_buffer[4U], latitude, longitude);
    
}
    
void CAPRSHelper::close()
{
    m_writer.close();
}
/*
int main(void)
{
    std::string callsign = "N9OTJ";
    std::string suffix = "11";
    std::string password = "14479";
    std::string address = "aprs.mcducklabs.com";
    int port = 14580;    
	CAPRSHelper* helper = new CAPRSHelper(callsign, suffix, password, address, port);

	helper->open();
    usleep(1000*1000*6);
    
    helper->send();
    
    for (;;)
    {
        
    }

	delete helper;
    
    return 0;
}
*/