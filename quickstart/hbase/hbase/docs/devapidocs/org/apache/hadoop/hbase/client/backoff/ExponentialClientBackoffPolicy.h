<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>ExponentialClientBackoffPolicy (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="ExponentialClientBackoffPolicy (Apache HBase 1.4.13 API)";
        }
    }
    catch(err) {
    }
//-->
</script>
<noscript>
<div>JavaScript is disabled on your browser.</div>
</noscript>
<!-- ========= START OF TOP NAVBAR ======= -->
<div class="topNav"><a name="navbar_top">
<!--   -->
</a><a href="#skip-navbar_top" title="Skip navigation links"></a><a name="navbar_top_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/ExponentialClientBackoffPolicy.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicyFactory.NoBackoffPolicy.html" title="class in org.apache.hadoop.hbase.client.backoff"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ServerStatistics.html" title="class in org.apache.hadoop.hbase.client.backoff"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html" target="_top">Frames</a></li>
<li><a href="ExponentialClientBackoffPolicy.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_top");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li><a href="#field_summary">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li><a href="#field_detail">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<!-- ======== START OF CLASS DATA ======== -->
<div class="header">
<div class="subTitle">org.apache.hadoop.hbase.client.backoff</div>
<h2 title="Class ExponentialClientBackoffPolicy" class="title">Class ExponentialClientBackoffPolicy</h2>
</div>
<div class="contentContainer">
<ul class="inheritance">
<li><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">java.lang.Object</a></li>
<li>
<ul class="inheritance">
<li>org.apache.hadoop.hbase.client.backoff.ExponentialClientBackoffPolicy</li>
</ul>
</li>
</ul>
<div class="description">
<ul class="blockList">
<li class="blockList">
<dl>
<dt>All Implemented Interfaces:</dt>
<dd><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html" title="interface in org.apache.hadoop.hbase.client.backoff">ClientBackoffPolicy</a></dd>
</dl>
<hr>
<br>
<pre><a href="../../../../../../org/apache/hadoop/hbase/classification/InterfaceAudience.Public.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceAudience.Public</a>
<a href="../../../../../../org/apache/hadoop/hbase/classification/InterfaceStability.Unstable.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceStability.Unstable</a>
public class <span class="strong">ExponentialClientBackoffPolicy</span>
extends <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">Object</a>
implements <a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html" title="interface in org.apache.hadoop.hbase.client.backoff">ClientBackoffPolicy</a></pre>
<div class="block">Simple exponential backoff policy on for the client that uses a  percent^4 times the
 max backoff to generate the backoff time.</div>
</li>
</ul>
</div>
<div class="summary">
<ul class="blockList">
<li class="blockList">
<!-- =========== FIELD SUMMARY =========== -->
<ul class="blockList">
<li class="blockList"><a name="field_summary">
<!--   -->
</a>
<h3>Field Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Field Summary table, listing fields, and an explanation">
<caption><span>Fields</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Field and Description</th>
</tr>
<tr class="altColor">
<td class="colFirst"><code>static long</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html#DEFAULT_MAX_BACKOFF">DEFAULT_MAX_BACKOFF</a></strong></code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>static <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a></code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html#MAX_BACKOFF_KEY">MAX_BACKOFF_KEY</a></strong></code>&nbsp;</td>
</tr>
</table>
<ul class="blockList">
<li class="blockList"><a name="fields_inherited_from_class_org.apache.hadoop.hbase.client.backoff.ClientBackoffPolicy">
<!--   -->
</a>
<h3>Fields inherited from interface&nbsp;org.apache.hadoop.hbase.client.backoff.<a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html" title="interface in org.apache.hadoop.hbase.client.backoff">ClientBackoffPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html#BACKOFF_POLICY_CLASS">BACKOFF_POLICY_CLASS</a></code></li>
</ul>
</li>
</ul>
<!-- ======== CONSTRUCTOR SUMMARY ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_summary">
<!--   -->
</a>
<h3>Constructor Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Constructor Summary table, listing constructors, and an explanation">
<caption><span>Constructors</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tr class="altColor">
<td class="colOne"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html#ExponentialClientBackoffPolicy(org.apache.hadoop.conf.Configuration)">ExponentialClientBackoffPolicy</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf)</code>&nbsp;</td>
</tr>
</table>
</li>
</ul>
<!-- ========== METHOD SUMMARY =========== -->
<ul class="blockList">
<li class="blockList"><a name="method_summary">
<!--   -->
</a>
<h3>Method Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Method Summary table, listing methods, and an explanation">
<caption><span>Methods</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tr class="altColor">
<td class="colFirst"><code>long</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html#getBackoffTime(org.apache.hadoop.hbase.ServerName,%20byte[],%20org.apache.hadoop.hbase.client.backoff.ServerStatistics)">getBackoffTime</a></strong>(<a href="../../../../../../org/apache/hadoop/hbase/ServerName.html" title="class in org.apache.hadoop.hbase">ServerName</a>&nbsp;serverName,
              byte[]&nbsp;region,
              <a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ServerStatistics.html" title="class in org.apache.hadoop.hbase.client.backoff">ServerStatistics</a>&nbsp;stats)</code>&nbsp;</td>
</tr>
</table>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_java.lang.Object">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;java.lang.<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">Object</a></h3>
<code><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#clone()" title="class or interface in java.lang">clone</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#equals(java.lang.Object)" title="class or interface in java.lang">equals</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#finalize()" title="class or interface in java.lang">finalize</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#getClass()" title="class or interface in java.lang">getClass</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#hashCode()" title="class or interface in java.lang">hashCode</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notify()" title="class or interface in java.lang">notify</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notifyAll()" title="class or interface in java.lang">notifyAll</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#toString()" title="class or interface in java.lang">toString</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait()" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long)" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long,%20int)" title="class or interface in java.lang">wait</a></code></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
<div class="details">
<ul class="blockList">
<li class="blockList">
<!-- ============ FIELD DETAIL =========== -->
<ul class="blockList">
<li class="blockList"><a name="field_detail">
<!--   -->
</a>
<h3>Field Detail</h3>
<a name="DEFAULT_MAX_BACKOFF">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>DEFAULT_MAX_BACKOFF</h4>
<pre>public static final&nbsp;long DEFAULT_MAX_BACKOFF</pre>
<dl><dt><span class="strong">See Also:</span></dt><dd><a href="../../../../../../constant-values.html#org.apache.hadoop.hbase.client.backoff.ExponentialClientBackoffPolicy.DEFAULT_MAX_BACKOFF">Constant Field Values</a></dd></dl>
</li>
</ul>
<a name="MAX_BACKOFF_KEY">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>MAX_BACKOFF_KEY</h4>
<pre>public static final&nbsp;<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a> MAX_BACKOFF_KEY</pre>
<dl><dt><span class="strong">See Also:</span></dt><dd><a href="../../../../../../constant-values.html#org.apache.hadoop.hbase.client.backoff.ExponentialClientBackoffPolicy.MAX_BACKOFF_KEY">Constant Field Values</a></dd></dl>
</li>
</ul>
</li>
</ul>
<!-- ========= CONSTRUCTOR DETAIL ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_detail">
<!--   -->
</a>
<h3>Constructor Detail</h3>
<a name="ExponentialClientBackoffPolicy(org.apache.hadoop.conf.Configuration)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>ExponentialClientBackoffPolicy</h4>
<pre>public&nbsp;ExponentialClientBackoffPolicy(org.apache.hadoop.conf.Configuration&nbsp;conf)</pre>
</li>
</ul>
</li>
</ul>
<!-- ============ METHOD DETAIL ========== -->
<ul class="blockList">
<li class="blockList"><a name="method_detail">
<!--   -->
</a>
<h3>Method Detail</h3>
<a name="getBackoffTime(org.apache.hadoop.hbase.ServerName, byte[], org.apache.hadoop.hbase.client.backoff.ServerStatistics)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>getBackoffTime</h4>
<pre>public&nbsp;long&nbsp;getBackoffTime(<a href="../../../../../../org/apache/hadoop/hbase/ServerName.html" title="class in org.apache.hadoop.hbase">ServerName</a>&nbsp;serverName,
                  byte[]&nbsp;region,
                  <a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ServerStatistics.html" title="class in org.apache.hadoop.hbase.client.backoff">ServerStatistics</a>&nbsp;stats)</pre>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html#getBackoffTime(org.apache.hadoop.hbase.ServerName,%20byte[],%20org.apache.hadoop.hbase.client.backoff.ServerStatistics)">getBackoffTime</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicy.html" title="interface in org.apache.hadoop.hbase.client.backoff">ClientBackoffPolicy</a></code></dd>
<dt><span class="strong">Returns:</span></dt><dd>the number of ms to wait on the client based on the</dd></dl>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>
<!-- ========= END OF CLASS DATA ========= -->
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/ExponentialClientBackoffPolicy.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ClientBackoffPolicyFactory.NoBackoffPolicy.html" title="class in org.apache.hadoop.hbase.client.backoff"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/client/backoff/ServerStatistics.html" title="class in org.apache.hadoop.hbase.client.backoff"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/client/backoff/ExponentialClientBackoffPolicy.html" target="_top">Frames</a></li>
<li><a href="ExponentialClientBackoffPolicy.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_bottom");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li><a href="#field_summary">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li><a href="#field_detail">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
