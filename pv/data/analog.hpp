/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PULSEVIEW_PV_DATA_ANALOG_HPP
#define PULSEVIEW_PV_DATA_ANALOG_HPP

#include "signaldata.hpp"

#include <deque>
#include <memory>

#include <QObject>

namespace pv {
namespace data {

class AnalogSegment;

class Analog : public QObject, public SignalData
{
	Q_OBJECT

public:
	Analog();

	void push_segment(std::shared_ptr<AnalogSegment> &segment);

	const std::deque<std::shared_ptr<AnalogSegment>> &
	analog_segments() const;

	std::vector<std::shared_ptr<Segment>> segments() const;

	void clear();

	uint64_t max_sample_count() const;

	void notify_samples_added(
		QObject *segment, uint64_t start_sample, uint64_t end_sample);

Q_SIGNALS:
	void samples_cleared();

	void samples_added(
		QObject *segment, uint64_t start_sample, uint64_t end_sample);

private:
	std::deque<std::shared_ptr<AnalogSegment>> segments_;
};

} // namespace data
} // namespace pv

#endif // PULSEVIEW_PV_DATA_ANALOG_HPP
