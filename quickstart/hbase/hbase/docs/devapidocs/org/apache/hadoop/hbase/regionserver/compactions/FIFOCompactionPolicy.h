<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>FIFOCompactionPolicy (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="FIFOCompactionPolicy (Apache HBase 1.4.13 API)";
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
<li><a href="class-use/FIFOCompactionPolicy.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExponentialCompactionWindowFactory.html" title="class in org.apache.hadoop.hbase.regionserver.compactions"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/OffPeakHours.html" title="class in org.apache.hadoop.hbase.regionserver.compactions"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html" target="_top">Frames</a></li>
<li><a href="FIFOCompactionPolicy.html" target="_top">No Frames</a></li>
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
<li><a href="#fields_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.CompactionPolicy">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
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
<div class="subTitle">org.apache.hadoop.hbase.regionserver.compactions</div>
<h2 title="Class FIFOCompactionPolicy" class="title">Class FIFOCompactionPolicy</h2>
</div>
<div class="contentContainer">
<ul class="inheritance">
<li><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">java.lang.Object</a></li>
<li>
<ul class="inheritance">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">org.apache.hadoop.hbase.regionserver.compactions.CompactionPolicy</a></li>
<li>
<ul class="inheritance">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">org.apache.hadoop.hbase.regionserver.compactions.SortedCompactionPolicy</a></li>
<li>
<ul class="inheritance">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">org.apache.hadoop.hbase.regionserver.compactions.RatioBasedCompactionPolicy</a></li>
<li>
<ul class="inheritance">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExploringCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">org.apache.hadoop.hbase.regionserver.compactions.ExploringCompactionPolicy</a></li>
<li>
<ul class="inheritance">
<li>org.apache.hadoop.hbase.regionserver.compactions.FIFOCompactionPolicy</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</li>
</ul>
<div class="description">
<ul class="blockList">
<li class="blockList">
<hr>
<br>
<pre><a href="../../../../../../org/apache/hadoop/hbase/classification/InterfaceAudience.Private.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceAudience.Private</a>
public class <span class="strong">FIFOCompactionPolicy</span>
extends <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExploringCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">ExploringCompactionPolicy</a></pre>
<div class="block">FIFO compaction policy selects only files which have all cells expired. 
 The column family MUST have non-default TTL. One of the use cases for this 
 policy is when we need to store raw data which will be post-processed later 
 and discarded completely after quite short period of time. Raw time-series vs. 
 time-based roll up aggregates and compacted time-series. We collect raw time-series
 and store them into CF with FIFO compaction policy, periodically we run task 
 which creates roll up aggregates and compacts time-series, the original raw data 
 can be discarded after that.</div>
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
<ul class="blockList">
<li class="blockList"><a name="fields_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.CompactionPolicy">
<!--   -->
</a>
<h3>Fields inherited from class&nbsp;org.apache.hadoop.hbase.regionserver.compactions.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">CompactionPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html#comConf">comConf</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html#storeConfigInfo">storeConfigInfo</a></code></li>
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
<td class="colOne"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html#FIFOCompactionPolicy(org.apache.hadoop.conf.Configuration,%20org.apache.hadoop.hbase.regionserver.StoreConfigInformation)">FIFOCompactionPolicy</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
                    <a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreConfigInformation.html" title="interface in org.apache.hadoop.hbase.regionserver">StoreConfigInformation</a>&nbsp;storeConfigInfo)</code>&nbsp;</td>
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
<td class="colFirst"><code>boolean</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html#needsCompaction(java.util.Collection,%20java.util.List)">needsCompaction</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;storeFiles,
               <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesCompacting)</code>
<div class="block">A heuristic method to decide whether to schedule a compaction request</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionRequest.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">CompactionRequest</a></code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html#selectCompaction(java.util.Collection,%20java.util.List,%20boolean,%20boolean,%20boolean)">selectCompaction</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;candidateFiles,
                <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesCompacting,
                boolean&nbsp;isUserCompaction,
                boolean&nbsp;mayUseOffPeak,
                boolean&nbsp;forceMajor)</code>&nbsp;</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>boolean</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html#shouldPerformMajorCompaction(java.util.Collection)">shouldPerformMajorCompaction</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesToCompact)</code>&nbsp;</td>
</tr>
</table>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.ExploringCompactionPolicy">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;org.apache.hadoop.hbase.regionserver.compactions.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExploringCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">ExploringCompactionPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExploringCompactionPolicy.html#applyCompactionPolicy(java.util.ArrayList,%20boolean,%20boolean)">applyCompactionPolicy</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExploringCompactionPolicy.html#applyCompactionPolicy(java.util.List,%20boolean,%20boolean,%20int,%20int)">applyCompactionPolicy</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.RatioBasedCompactionPolicy">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;org.apache.hadoop.hbase.regionserver.compactions.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">RatioBasedCompactionPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html#createCompactionRequest(java.util.ArrayList,%20boolean,%20boolean,%20boolean)">createCompactionRequest</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html#setMinThreshold(int)">setMinThreshold</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.SortedCompactionPolicy">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;org.apache.hadoop.hbase.regionserver.compactions.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">SortedCompactionPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#checkMinFilesCriteria(java.util.ArrayList,%20int)">checkMinFilesCriteria</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#filterBulk(java.util.ArrayList)">filterBulk</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#getCurrentEligibleFiles(java.util.ArrayList,%20java.util.List)">getCurrentEligibleFiles</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#getNextMajorCompactTime(java.util.Collection)">getNextMajorCompactTime</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#preSelectCompactionForCoprocessor(java.util.Collection,%20java.util.List)">preSelectCompactionForCoprocessor</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#removeExcessFiles(java.util.ArrayList,%20boolean,%20boolean)">removeExcessFiles</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#skipLargeFiles(java.util.ArrayList,%20boolean)">skipLargeFiles</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#throttleCompaction(long)">throttleCompaction</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.CompactionPolicy">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;org.apache.hadoop.hbase.regionserver.compactions.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">CompactionPolicy</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html#getConf()">getConf</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionPolicy.html#setConf(org.apache.hadoop.conf.Configuration)">setConf</a></code></li>
</ul>
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
<!-- ========= CONSTRUCTOR DETAIL ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_detail">
<!--   -->
</a>
<h3>Constructor Detail</h3>
<a name="FIFOCompactionPolicy(org.apache.hadoop.conf.Configuration, org.apache.hadoop.hbase.regionserver.StoreConfigInformation)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>FIFOCompactionPolicy</h4>
<pre>public&nbsp;FIFOCompactionPolicy(org.apache.hadoop.conf.Configuration&nbsp;conf,
                    <a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreConfigInformation.html" title="interface in org.apache.hadoop.hbase.regionserver">StoreConfigInformation</a>&nbsp;storeConfigInfo)</pre>
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
<a name="selectCompaction(java.util.Collection, java.util.List, boolean, boolean, boolean)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>selectCompaction</h4>
<pre>public&nbsp;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/CompactionRequest.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">CompactionRequest</a>&nbsp;selectCompaction(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;candidateFiles,
                                 <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesCompacting,
                                 boolean&nbsp;isUserCompaction,
                                 boolean&nbsp;mayUseOffPeak,
                                 boolean&nbsp;forceMajor)
                                   throws <a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></pre>
<dl>
<dt><strong>Overrides:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html#selectCompaction(java.util.Collection,%20java.util.List,%20boolean,%20boolean,%20boolean)">selectCompaction</a></code>&nbsp;in class&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/SortedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">SortedCompactionPolicy</a></code></dd>
<dt><span class="strong">Parameters:</span></dt><dd><code>candidateFiles</code> - candidate files, ordered from oldest to newest by seqId. We rely on
   DefaultStoreFileManager to sort the files by seqId to guarantee contiguous compaction based
   on seqId for data consistency.</dd>
<dt><span class="strong">Returns:</span></dt><dd>subset copy of candidate list that meets compaction criteria</dd>
<dt><span class="strong">Throws:</span></dt>
<dd><code><a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></code></dd></dl>
</li>
</ul>
<a name="shouldPerformMajorCompaction(java.util.Collection)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>shouldPerformMajorCompaction</h4>
<pre>public&nbsp;boolean&nbsp;shouldPerformMajorCompaction(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesToCompact)
                                     throws <a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></pre>
<dl>
<dt><strong>Overrides:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html#shouldPerformMajorCompaction(java.util.Collection)">shouldPerformMajorCompaction</a></code>&nbsp;in class&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">RatioBasedCompactionPolicy</a></code></dd>
<dt><span class="strong">Parameters:</span></dt><dd><code>filesToCompact</code> - Files to compact. Can be null.</dd>
<dt><span class="strong">Returns:</span></dt><dd>True if we should run a major compaction.</dd>
<dt><span class="strong">Throws:</span></dt>
<dd><code><a href="http://docs.oracle.com/javase/7/docs/api/java/io/IOException.html?is-external=true" title="class or interface in java.io">IOException</a></code></dd></dl>
</li>
</ul>
<a name="needsCompaction(java.util.Collection, java.util.List)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>needsCompaction</h4>
<pre>public&nbsp;boolean&nbsp;needsCompaction(<a href="http://docs.oracle.com/javase/7/docs/api/java/util/Collection.html?is-external=true" title="class or interface in java.util">Collection</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;storeFiles,
                      <a href="http://docs.oracle.com/javase/7/docs/api/java/util/List.html?is-external=true" title="class or interface in java.util">List</a>&lt;<a href="../../../../../../org/apache/hadoop/hbase/regionserver/StoreFile.html" title="class in org.apache.hadoop.hbase.regionserver">StoreFile</a>&gt;&nbsp;filesCompacting)</pre>
<div class="block"><strong>Description copied from class:&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html#needsCompaction(java.util.Collection,%20java.util.List)">RatioBasedCompactionPolicy</a></code></strong></div>
<div class="block">A heuristic method to decide whether to schedule a compaction request</div>
<dl>
<dt><strong>Overrides:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html#needsCompaction(java.util.Collection,%20java.util.List)">needsCompaction</a></code>&nbsp;in class&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/RatioBasedCompactionPolicy.html" title="class in org.apache.hadoop.hbase.regionserver.compactions">RatioBasedCompactionPolicy</a></code></dd>
<dt><span class="strong">Parameters:</span></dt><dd><code>storeFiles</code> - files in the store.</dd><dd><code>filesCompacting</code> - files being scheduled to compact.</dd>
<dt><span class="strong">Returns:</span></dt><dd>true to schedule a request.</dd></dl>
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
<li><a href="class-use/FIFOCompactionPolicy.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/ExponentialCompactionWindowFactory.html" title="class in org.apache.hadoop.hbase.regionserver.compactions"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/compactions/OffPeakHours.html" title="class in org.apache.hadoop.hbase.regionserver.compactions"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/regionserver/compactions/FIFOCompactionPolicy.html" target="_top">Frames</a></li>
<li><a href="FIFOCompactionPolicy.html" target="_top">No Frames</a></li>
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
<li><a href="#fields_inherited_from_class_org.apache.hadoop.hbase.regionserver.compactions.CompactionPolicy">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
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
