#ifndef RESOURCES_VIEWS_DASHBOARD_REGISTER_H_
#define RESOURCES_VIEWS_DASHBOARD_REGISTER_H_
#include "../dashboard.h"
#include <cppcms/form.h>

namespace views
{
  namespace dashboard
  {
    struct Register : public views::Dashboard
    {
      struct RegisterForm : public cppcms::form
      {
        RegisterForm()
        {
          this->name.message("Tên đăng nhập");
          this->name.attributes_string("class=\"form-control\"");
          this->password.message("Mật khẩu");
          this->password.attributes_string("class=\"form-control\"");
          this->confirm_password.message("Xác nhận mật khẩu");
          this->confirm_password.attributes_string("class=\"form-control\"");
          this->submit.value("Đăng kí");
          this->submit.attributes_string("class=\"btn btn-primary\"");
          
          add(this->name);
          add(this->password);
          add(this->confirm_password);
          add(this->submit);
        }
        cppcms::widgets::text name;
        cppcms::widgets::password password;
        cppcms::widgets::password confirm_password;
        cppcms::widgets::submit submit;
      };
      RegisterForm register_form;
    };
  }
}

#endif
