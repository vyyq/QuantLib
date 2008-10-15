/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2008 Andreas Gaida
 Copyright (C) 2008 Ralph Schreyer
 Copyright (C) 2008 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file fdmstepconditioncomposite.cpp
    \brief composite of fdm step conditions
*/

#ifndef quantlib_fdm_step_condition_composite_hpp
#define quantlib_fdm_step_condition_composite_hpp

#include <ql/methods/finitedifferences/stepcondition.hpp>
#include <ql/experimental/finitedifferences/fdmmesher.hpp>
#include <ql/experimental/finitedifferences/fdminnervaluecalculator.hpp>
#include <set>

namespace QuantLib {

    class FdmStepConditionComposite : public StepCondition<Array> {
    public:
        typedef std::list<boost::shared_ptr<StepCondition<Array> > > Conditions;

        FdmStepConditionComposite(
            const std::list<std::vector<Time> > & stoppingTimes,
            const Conditions & conditions);

        void applyTo(Array& a, Time t) const;
        const std::vector<Time>& stoppingTimes() const;
        const Conditions& conditions() const;

    private:
        std::vector<Time> stoppingTimes_;
        const Conditions conditions_;
    };
}
#endif