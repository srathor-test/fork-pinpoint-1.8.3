<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Uses of Interface org.apache.hadoop.hbase.regionserver.wal.WALActionsListener (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="Uses of Interface org.apache.hadoop.hbase.regionserver.wal.WALActionsListener (Apache HBase 1.4.13 API)";
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
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="../package-summary.html">Package</a></li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">Class</a></li>
<li class="navBarCell1Rev">Use</li>
<li><a href="../package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev</li>
<li>Next</li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/class-use/WALActionsListener.html" target="_top">Frames</a></li>
<li><a href="WALActionsListener.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
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
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<div class="header">
<h2 title="Uses of Interface org.apache.hadoop.hbase.regionserver.wal.WALActionsListener" class="title">Uses of Interface<br>org.apache.hadoop.hbase.regionserver.wal.WALActionsListener</h2>
</div>
<div class="classUseContainer">
<ul class="blockList">
<li class="blockList">
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing packages, and an explanation">
<caption><span>Packages that use <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Package</th>
<th class="colLast" scope="col">Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.regionserver">org.apache.hadoop.hbase.regionserver</a></td>
<td class="colLast">&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.regionserver.wal">org.apache.hadoop.hbase.regionserver.wal</a></td>
<td class="colLast">&nbsp;</td>
</tr>
<tr class="altColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.replication.regionserver">org.apache.hadoop.hbase.replication.regionserver</a></td>
<td class="colLast">&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.wal">org.apache.hadoop.hbase.wal</a></td>
<td class="colLast">&nbsp;</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList">
<ul class="blockList">
<li class="blockList"><a name="org.apache.hadoop.hbase.regionserver">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a> in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/package-summary.html">org.apache.hadoop.hbase.regionserver</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/package-summary.html">org.apache.hadoop.hbase.regionserver</a> that return <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></code></td>
<td class="colLast"><span class="strong">ReplicationSourceService.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/ReplicationSourceService.html#getWALActionsListener()">getWALActionsListener</a></strong>()</code>
<div class="block">Returns a WALObserver for the service.</div>
</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList"><a name="org.apache.hadoop.hbase.regionserver.wal">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a> in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing classes, and an explanation">
<caption><span>Classes in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> that implement <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Class and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>class&nbsp;</code></td>
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsWAL.html" title="class in org.apache.hadoop.hbase.regionserver.wal">MetricsWAL</a></strong></code>
<div class="block">Class used to push numbers about the WAL into the metrics subsystem.</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>static class&nbsp;</code></td>
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.Base.html" title="class in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener.Base</a></strong></code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> with parameters of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">FSHLog.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/FSHLog.html#registerWALActionsListener(org.apache.hadoop.hbase.regionserver.wal.WALActionsListener)">registerWALActionsListener</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&nbsp;listener)</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>boolean</code></td>
<td class="colLast"><span class="strong">FSHLog.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/FSHLog.html#unregisterWALActionsListener(org.apache.hadoop.hbase.regionserver.wal.WALActionsListener)">unregisterWALActionsListener</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&nbsp;listener)</code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing constructors, and an explanation">
<caption><span>Constructor parameters in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> with type arguments of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/FSHLog.html#FSHLog(org.apache.hadoop.fs.FileSystem,%20org.apache.hadoop.fs.Path,%20java.lang.String,%20java.lang.String,%20org.apache.hadoop.conf.Configuration,%20java.util.List,%20boolean,%20java.lang.String,%20java.lang.String)">FSHLog</a></strong>(org.apache.hadoop.fs.FileSystem&nbsp;fs,
      org.apache.hadoop.fs.Path&nbsp;rootDir,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;logDir,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;archiveDir,
      org.apache.hadoop.conf.Configuration&nbsp;conf,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&gt;&nbsp;listeners,
      boolean&nbsp;failIfWALExists,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;prefix,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;suffix)</code>
<div class="block">Create an edit log at the given <code>dir</code> location.</div>
</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList"><a name="org.apache.hadoop.hbase.replication.regionserver">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a> in <a href="../../../../../../../org/apache/hadoop/hbase/replication/regionserver/package-summary.html">org.apache.hadoop.hbase.replication.regionserver</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing classes, and an explanation">
<caption><span>Classes in <a href="../../../../../../../org/apache/hadoop/hbase/replication/regionserver/package-summary.html">org.apache.hadoop.hbase.replication.regionserver</a> that implement <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Class and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>class&nbsp;</code></td>
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/replication/regionserver/Replication.html" title="class in org.apache.hadoop.hbase.replication.regionserver">Replication</a></strong></code>
<div class="block">Gateway to Replication.</div>
</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/replication/regionserver/package-summary.html">org.apache.hadoop.hbase.replication.regionserver</a> that return <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></code></td>
<td class="colLast"><span class="strong">Replication.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/replication/regionserver/Replication.html#getWALActionsListener()">getWALActionsListener</a></strong>()</code>&nbsp;</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList"><a name="org.apache.hadoop.hbase.wal">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a> in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a> with parameters of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">WAL.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WAL.html#registerWALActionsListener(org.apache.hadoop.hbase.regionserver.wal.WALActionsListener)">registerWALActionsListener</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&nbsp;listener)</code>
<div class="block">Registers WALActionsListener</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>boolean</code></td>
<td class="colLast"><span class="strong">WAL.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WAL.html#unregisterWALActionsListener(org.apache.hadoop.hbase.regionserver.wal.WALActionsListener)">unregisterWALActionsListener</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&nbsp;listener)</code>
<div class="block">Unregisters WALActionsListener</div>
</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Method parameters in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a> with type arguments of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">WALProvider.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WALProvider.html#init(org.apache.hadoop.hbase.wal.WALFactory,%20org.apache.hadoop.conf.Configuration,%20java.util.List,%20java.lang.String)">init</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/wal/WALFactory.html" title="class in org.apache.hadoop.hbase.wal">WALFactory</a>&nbsp;factory,
    org.apache.hadoop.conf.Configuration&nbsp;conf,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&gt;&nbsp;listeners,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;providerId)</code>
<div class="block">Set up the provider to create wals.</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">DefaultWALProvider.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/DefaultWALProvider.html#init(org.apache.hadoop.hbase.wal.WALFactory,%20org.apache.hadoop.conf.Configuration,%20java.util.List,%20java.lang.String)">init</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/wal/WALFactory.html" title="class in org.apache.hadoop.hbase.wal">WALFactory</a>&nbsp;factory,
    org.apache.hadoop.conf.Configuration&nbsp;conf,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&gt;&nbsp;listeners,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;providerId)</code>&nbsp;</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">RegionGroupingProvider.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/RegionGroupingProvider.html#init(org.apache.hadoop.hbase.wal.WALFactory,%20org.apache.hadoop.conf.Configuration,%20java.util.List,%20java.lang.String)">init</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/wal/WALFactory.html" title="class in org.apache.hadoop.hbase.wal">WALFactory</a>&nbsp;factory,
    org.apache.hadoop.conf.Configuration&nbsp;conf,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&gt;&nbsp;listeners,
    <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;providerId)</code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing constructors, and an explanation">
<caption><span>Constructor parameters in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a> with type arguments of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WALFactory.html#WALFactory(org.apache.hadoop.conf.Configuration,%20java.util.List,%20java.lang.String)">WALFactory</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
          <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">WALActionsListener</a>&gt;&nbsp;listeners,
          <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;factoryId)</code>&nbsp;</td>
</tr>
</tbody>
</table>
</li>
</ul>
</li>
</ul>
</div>
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="../package-summary.html">Package</a></li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALActionsListener.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">Class</a></li>
<li class="navBarCell1Rev">Use</li>
<li><a href="../package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev</li>
<li>Next</li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/class-use/WALActionsListener.html" target="_top">Frames</a></li>
<li><a href="WALActionsListener.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
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
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
