/* Generated by Opal 0.8.0 */
(function(Opal) {
  Opal.dynamic_require_severity = "error";
  var self = Opal.top, $scope = Opal, nil = Opal.nil, $breaker = Opal.breaker, $slice = Opal.slice, $module = Opal.module, $klass = Opal.klass, $gvars = Opal.gvars;

  Opal.add_stubs(['$include', '$raise', '$==', '$arity', '$instance_exec', '$to_proc', '$call', '$new', '$console']);
  return (function($base) {
    var self = $module($base, 'Browser');

    var def = self.$$proto, $scope = self.$$scope;
    if ($gvars.window == null) $gvars.window = nil;

    (function($base, $super) {
      function $Console(){};
      var self = $Console = $klass($base, $super, 'Console', $Console);

      var def = self.$$proto, $scope = self.$$scope, TMP_1, TMP_2, TMP_3;

      def["native"] = nil;
      self.$include($scope.get('Native'));

      def.$clear = function() {
        var self = this;

        return self["native"].clear();
      };

      def.$trace = function() {
        var self = this;

        return self["native"].trace();
      };

      def.$log = function(args) {
        var self = this;

        args = $slice.call(arguments, 0);
        return self["native"].log.apply(self["native"], args);
      };

      def.$info = function(args) {
        var self = this;

        args = $slice.call(arguments, 0);
        return self["native"].info.apply(self["native"], args);
      };

      def.$warn = function(args) {
        var self = this;

        args = $slice.call(arguments, 0);
        return self["native"].warn.apply(self["native"], args);
      };

      def.$error = function(args) {
        var self = this;

        args = $slice.call(arguments, 0);
        return self["native"].error.apply(self["native"], args);
      };

      def.$time = TMP_1 = function(label) {
        var $a, $b, self = this, $iter = TMP_1.$$p, block = $iter || nil;

        TMP_1.$$p = null;
        if (block !== false && block !== nil) {
          } else {
          self.$raise($scope.get('ArgumentError'), "no block given")
        };
        self["native"].time(label);
        try {
        if (block.$arity()['$=='](0)) {
          return ($a = ($b = self).$instance_exec, $a.$$p = block.$to_proc(), $a).call($b)
          } else {
          return block.$call(self)
        }
        } finally {
        self["native"].timeEnd();
        };
      };

      def.$group = TMP_2 = function(args) {
        var $a, $b, self = this, $iter = TMP_2.$$p, block = $iter || nil;

        args = $slice.call(arguments, 0);
        TMP_2.$$p = null;
        if (block !== false && block !== nil) {
          } else {
          self.$raise($scope.get('ArgumentError'), "no block given")
        };
        self["native"].group.apply(self["native"], args);
        try {
        if (block.$arity()['$=='](0)) {
          return ($a = ($b = self).$instance_exec, $a.$$p = block.$to_proc(), $a).call($b)
          } else {
          return block.$call(self)
        }
        } finally {
        self["native"].groupEnd();
        };
      };

      return (def['$group!'] = TMP_3 = function(args) {
        var $a, $b, self = this, $iter = TMP_3.$$p, block = $iter || nil;

        args = $slice.call(arguments, 0);
        TMP_3.$$p = null;
        if ((block !== nil)) {
          } else {
          return nil
        };
        self["native"].groupCollapsed.apply(self["native"], args);
        try {
        if (block.$arity()['$=='](0)) {
          return ($a = ($b = self).$instance_exec, $a.$$p = block.$to_proc(), $a).call($b)
          } else {
          return block.$call(self)
        }
        } finally {
        self["native"].groupEnd();
        };
      }, nil) && 'group!';
    })(self, null);

    (function($base, $super) {
      function $Window(){};
      var self = $Window = $klass($base, $super, 'Window', $Window);

      var def = self.$$proto, $scope = self.$$scope;

      def["native"] = nil;
      return (def.$console = function() {
        var self = this;

        return $scope.get('Console').$new(self["native"].console);
      }, nil) && 'console'
    })(self, null);

    $gvars.console = $gvars.window.$console();
  })(self)
})(Opal);