// Copyright (c) 2005-2011 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD/e, an XML Schema
// to C++ data binding compiler for embedded systems.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
//

// Begin prologue.
//
//
// End prologue.

#include "pidf+xml-pimpl.hxx"

#include <xsde/cxx/parser/validating/string-common.hxx>

namespace pidf
{
  // note_pimpl
  //

  note_pimpl::
  note_pimpl ()
  : note_pskel (&base_impl_)
  {
  }

  void note_pimpl::
  pre ()
  {
    this->base_impl_.pre ();
    this->note_pimpl_state_.note_ = ::pidf::note ();
  }

  void note_pimpl::
  lang (const ::namespace_::lang& x)
  {
    this->note_pimpl_state_.note_.lang (x);
  }

  ::pidf::note note_pimpl::
  post_note ()
  {
    static_cast< ::std::string& > (this->note_pimpl_state_.note_) = 
    this->base_impl_.post_string ();
    return this->note_pimpl_state_.note_;
  }

  // presence_pimpl
  //

  presence_pimpl::
  presence_pimpl (bool b)
  {
    this->presence_pimpl_base_ = b;
    this->presence_pimpl_state_.presence_ = 0;
  }

  presence_pimpl::
  ~presence_pimpl ()
  {
    if (!this->presence_pimpl_base_ && this->presence_pimpl_state_.presence_)
      delete this->presence_pimpl_state_.presence_;
  }

  void presence_pimpl::
  _reset ()
  {
    presence_pskel::_reset ();

    if (!this->presence_pimpl_base_ && this->presence_pimpl_state_.presence_)
    {
      delete this->presence_pimpl_state_.presence_;
      this->presence_pimpl_state_.presence_ = 0;
    }
  }

  void presence_pimpl::
  pre_impl (::pidf::presence* x)
  {
    this->presence_pimpl_state_.presence_ = x;
  }

  void presence_pimpl::
  pre ()
  {
    ::pidf::presence* x = new ::pidf::presence;
    this->pre_impl (x);
  }

  void presence_pimpl::
  entity (const ::std::string& x)
  {
    this->presence_pimpl_state_.presence_->entity (x);
  }

  void presence_pimpl::
  tuple (::pidf::tuple* x)
  {
    this->presence_pimpl_state_.presence_->tuple ().push_back (x);
  }

  void presence_pimpl::
  note (const ::pidf::note& x)
  {
    this->presence_pimpl_state_.presence_->note ().push_back (x);
  }

  ::pidf::presence* presence_pimpl::
  post_presence ()
  {
    ::pidf::presence* r = this->presence_pimpl_state_.presence_;
    this->presence_pimpl_state_.presence_ = 0;
    return r;
  }

  // basic_pimpl
  //

  basic_pimpl::
  basic_pimpl ()
  : basic_pskel (0)
  {
  }

  void basic_pimpl::
  pre ()
  {
    this->basic_pimpl_state_.str_.clear ();
  }

  void basic_pimpl::
  _characters (const ::xsde::cxx::ro_string& s)
  {
    if (this->_facets ().whitespace_ == 2 &&
        this->basic_pimpl_state_.str_.size () == 0)
    {
      ::xsde::cxx::ro_string tmp (s.data (), s.size ());

      if (::xsde::cxx::trim_left (tmp) != 0)
      {
        this->basic_pimpl_state_.str_ += tmp;
      }
    }
    else
      this->basic_pimpl_state_.str_ += s;
  }

  void basic_pimpl::
  _post ()
  {
    ::xsde::cxx::parser::validating::string_common::validate_facets (
      this->basic_pimpl_state_.str_,
      this->_facets (),
      this->_context ());
  }

  ::pidf::basic basic_pimpl::
  post_basic ()
  {
    ::pidf::basic::value_type v =
    static_cast< ::pidf::basic::value_type > (0);
    const char* s = this->basic_pimpl_state_.str_.c_str ();

    if (strcmp (s, "open") == 0)
      v = ::pidf::basic::open;
    else if (strcmp (s, "closed") == 0)
      v = ::pidf::basic::closed;

    ::pidf::basic r (v);
    return r;
  }

  // status_pimpl
  //

  void status_pimpl::
  pre ()
  {
    this->status_pimpl_state_.status_ = ::pidf::status ();
  }

  void status_pimpl::
  basic (const ::pidf::basic& x)
  {
    this->status_pimpl_state_.status_.basic (x);
  }

  ::pidf::status status_pimpl::
  post_status ()
  {
    return this->status_pimpl_state_.status_;
  }

  // qvalue_pimpl
  //

  qvalue_pimpl::
  qvalue_pimpl ()
  : qvalue_pskel (&base_impl_)
  {
  }

  void qvalue_pimpl::
  pre ()
  {
    this->base_impl_.pre ();
    this->qvalue_pimpl_state_.qvalue_ = ::pidf::qvalue ();
  }

  ::pidf::qvalue qvalue_pimpl::
  post_qvalue ()
  {
    static_cast< ::xml_schema::decimal_base& > (this->qvalue_pimpl_state_.qvalue_) = 
    this->base_impl_.post_decimal ();
    return this->qvalue_pimpl_state_.qvalue_;
  }

  // contact_pimpl
  //

  contact_pimpl::
  contact_pimpl ()
  : contact_pskel (&base_impl_)
  {
  }

  void contact_pimpl::
  pre ()
  {
    this->base_impl_.pre ();
    this->contact_pimpl_state_.contact_ = ::pidf::contact ();
  }

  void contact_pimpl::
  priority (const ::pidf::qvalue& x)
  {
    this->contact_pimpl_state_.contact_.priority (x);
  }

  ::pidf::contact contact_pimpl::
  post_contact ()
  {
    static_cast< ::std::string& > (this->contact_pimpl_state_.contact_) = 
    this->base_impl_.post_uri ();
    return this->contact_pimpl_state_.contact_;
  }

  // tuple_pimpl
  //

  tuple_pimpl::
  tuple_pimpl (bool b)
  {
    this->tuple_pimpl_base_ = b;
    this->tuple_pimpl_state_.tuple_ = 0;
  }

  tuple_pimpl::
  ~tuple_pimpl ()
  {
    if (!this->tuple_pimpl_base_ && this->tuple_pimpl_state_.tuple_)
      delete this->tuple_pimpl_state_.tuple_;
  }

  void tuple_pimpl::
  _reset ()
  {
    tuple_pskel::_reset ();

    if (!this->tuple_pimpl_base_ && this->tuple_pimpl_state_.tuple_)
    {
      delete this->tuple_pimpl_state_.tuple_;
      this->tuple_pimpl_state_.tuple_ = 0;
    }
  }

  void tuple_pimpl::
  pre_impl (::pidf::tuple* x)
  {
    this->tuple_pimpl_state_.tuple_ = x;
  }

  void tuple_pimpl::
  pre ()
  {
    ::pidf::tuple* x = new ::pidf::tuple;
    this->pre_impl (x);
  }

  void tuple_pimpl::
  id (const ::std::string& x)
  {
    this->tuple_pimpl_state_.tuple_->id (x);
  }

  void tuple_pimpl::
  status (const ::pidf::status& x)
  {
    this->tuple_pimpl_state_.tuple_->status (x);
  }

  void tuple_pimpl::
  contact (const ::pidf::contact& x)
  {
    this->tuple_pimpl_state_.tuple_->contact (x);
  }

  void tuple_pimpl::
  note (const ::pidf::note& x)
  {
    this->tuple_pimpl_state_.tuple_->note ().push_back (x);
  }

  void tuple_pimpl::
  timestamp (const ::xml_schema::date_time& x)
  {
    this->tuple_pimpl_state_.tuple_->timestamp (x);
  }

  ::pidf::tuple* tuple_pimpl::
  post_tuple ()
  {
    ::pidf::tuple* r = this->tuple_pimpl_state_.tuple_;
    this->tuple_pimpl_state_.tuple_ = 0;
    return r;
  }
}

namespace pidf
{
  // presence_paggr
  //

  presence_paggr::
  presence_paggr ()
  {
    this->status_p_.parsers (this->basic_p_);

    this->contact_p_.parsers (this->qvalue_p_);

    this->note_p_.parsers (this->lang_p_);

    this->presence_p_.parsers (this->uri_p_,
                               this->tuple_p_,
                               this->note_p_);

    this->tuple_p_.parsers (this->id_p_,
                            this->status_p_,
                            this->contact_p_,
                            this->note_p_,
                            this->date_time_p_);
  }

  const char* presence_paggr::
  root_name ()
  {
    return "presence";
  }

  const char* presence_paggr::
  root_namespace ()
  {
    return "urn:ietf:params:xml:ns:pidf";
  }
}

// Begin epilogue.
//
//
// End epilogue.
